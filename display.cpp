#include "display.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    /**
     * Parcours chaque case du tableau et fait l'affichage suivant ce qui a été défini dans l'initialisation :
     * - FILLED : affiche les coordonnées de la case en partant de 1 (comme dans une matrice)
     * - VOID   : affiche un espace dans la configuration de base pour indiquer qu'il n'y a rien à cet endroit, qu'il
     *            est hors de la table de jeu
     * - DOT    : affiche deux points dans la configuration de base pour indiquer que la case est vide et qu'on peut y
     *            placer une bille pour un mouvement (s'il est possible, bien entendu)
     */
    for (std::size_t i = 0; i < SIZE_BOARD + 0; ++i) { // Ligne
        for (std::size_t j = 0; j < SIZE_BOARD + 0; ++j) { // Colonne
        
            switch (board[i][j]) {

                case StateCase::FILLED :
                    std::cout << i + 1 << j + 1 << std::string(CHAR_REP - 1, VOIDCASE);
                    break;

                case StateCase::VOID :
                    std::cout << std::string(CHAR_REP, VOIDCASE) + std::string(1, VOIDCASE);
                    break;

                case StateCase::DOT :
                    std::cout << std::string(CHAR_REP, DOTCASE) + std::string(1, VOIDCASE);
                    break;
            }
        }

        std::cout << std::endl;
    }
}

void help(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    std::cout << "Deplacements possibles : ";

    /**
     * Parcours le tableau et affiche les possibilité de jeu de la part du joueur.
     * En prenant en compte que la case à partir de laquelle on fait les tests doit être en DOT :
     * - on regarde si la case à sa droite contient une bille et celle d'encore à droite, par exemple :
     *   ".. 45 46" va nous donner "46l"
     * - on répète cette opération pour les trois autres côtés.
     */
    for(size_t i = 0; i < SIZE_BOARD; ++i){
        for(size_t j = 0; j < SIZE_BOARD; ++j){
            if(board[i][j] == StateCase::DOT) {
                if(j + 2 < SIZE_BOARD && board[i][j + 1] == StateCase::FILLED && board[i][j + 2] == StateCase::FILLED)
                    std::cout << i + 1 << j + 3 << 'l' << " ";// RIGHT
                if(j - 2 < SIZE_BOARD && board[i][j - 1] == StateCase::FILLED && board[i][j - 2] == StateCase::FILLED)
                    std::cout << i + 1 << j - 1 << 'r' << " "; // LEFT
                if(i + 2 < SIZE_BOARD && board[i + 1][j] == StateCase::FILLED && board[i + 2][j] == StateCase::FILLED)
                    std::cout << i + 3 << j + 1 << 'u' << " "; // UP
                if(i - 2 < SIZE_BOARD && board[i - 1][j] == StateCase::FILLED && board[i - 2][j] == StateCase::FILLED)
                    std::cout << i - 1 << j + 1 << 'd' << " "; // DOWN
            }
        }
    }

    std::cout << std::endl;
}

void displayWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    /**
     * À la fin d'une partie, on compte le nombre de billes encore présentent dans le jeu.
     * S'il y en a :
     * - plus de 5 : on indique un message une sorte de "peut mieux faire"
     * - entre 2 et 5 : on affiche un message disant que c'est pas mal joué
     * - 1 :
     *      - si elle est au centre, c'est une partie parfaite
     *      - sinon, c'est quand même une très bonne partie
     */
    int nbMarbles = countNumMarbles(board);

    if (nbMarbles > 5) {
        std::cout << "Vous pouvez faire mieux, il reste " << nbMarbles << " billes." << std::endl;
    } else if (nbMarbles <= 5 && nbMarbles >= 2) {
        std::cout << "Pas mal, il ne reste que " << nbMarbles << " billes." << std::endl;
    } else if (nbMarbles < 2) {
        if(board[3][3] == StateCase::FILLED)
            std::cout << "Parfait, il vous reste qu'une bille au centre" << std::endl;
        else
            std::cout << "Bravo, vous avez gagné avec une seule billes restante. Au centre serait parfait" << std::endl;
    }
}

int countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]) {
    int counter = 0;

    /**
     * Parcours la table de jeu pour compter le nombre de billes restante.
     */
    for (size_t i = 0; i < SIZE_BOARD; ++i) {
        for (size_t j = 0; j < SIZE_BOARD; ++j) {
            if (board[i][j] == StateCase::FILLED) {
                counter++;
            }
        }
    }

    return counter;
}