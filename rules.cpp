#include "rules.h"

#include <cstddef>
#include <iostream>

void initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    /**
     * Le plateau est rempli de case à l'état FILLED
     * Cette solution a été utilisiée car des appels à des cases du plateau retournaient parfois des
     * accès mémoire indéfinis
     */

    for (std::size_t i = 0; i < SIZE_BOARD; ++i) {
        for (std::size_t j = 0; j < SIZE_BOARD; ++j)
            board[i][j] = StateCase::FILLED;
    }

    /**
     * Le plateau est défini comme un modèle par défaut qui est le suivant :
     */

    board[0][0] = StateCase::VOID;
    board[0][1] = StateCase::VOID;
    board[1][0] = StateCase::VOID;
    board[1][1] = StateCase::VOID;

    board[5][0] = StateCase::VOID;
    board[5][1] = StateCase::VOID;
    board[6][0] = StateCase::VOID;
    board[6][1] = StateCase::VOID;

    board[0][5] = StateCase::VOID;
    board[0][6] = StateCase::VOID;
    board[1][5] = StateCase::VOID;
    board[1][6] = StateCase::VOID;

    board[5][5] = StateCase::VOID;
    board[5][6] = StateCase::VOID;
    board[6][5] = StateCase::VOID;
    board[6][6] = StateCase::VOID;

    board[3][3] = StateCase::DOT;

}

bool checkInputs(std::string userInput, StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    // Si la longueur est 3

    if (userInput.length() == 3) {

        // Nous récupérons les 2 premiers caractères de notre chaîne passé en paramètre

        char firstChar = userInput.at(0), secondChar = userInput.at(1);

        // On vérifie que ce sont des caractères numériques (0,1,2,3,...,9)

        if(isdigit(firstChar) && isdigit(secondChar)) {

            /**
             * On transforme ces caractères en valeur entière
             * p.ex.
             * '1' -> 1
             * '9' -> 9
             */

            int valFChar = firstChar - '0', valSChar = secondChar - '0';

            /**
             * On vérifie que les cordonnées et la direction transmise par l'utilisateur est bien valide
             * p.ex.
             * 19d -> valFChar (ligne) = 1, valSChar (colonne) = 9, d transmis comme caractère
             */

            return moveValid((size_t)valSChar, (size_t)valFChar, char(tolower(userInput.at(2))), board);
        }
    }

    return false;
}

void move(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    /**
     * Les cases modifiées ne sont pas les mêmes en fonction de la direction.
     * Nous modifions donc les cases en conséquence
     */

    /**
     * On enlève la bille sur laquelle on saute et on déplace notre bille vers ...
     */

    switch (MoveAllowed(int(direction))) {
        case MoveAllowed::DOWN:
            board[y][x - 1] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y + 1][x - 1] = StateCase::FILLED; // celle qui est 2 cases dessous de notre bille
            break;
        case MoveAllowed::UP:
            board[y - 2][x - 1] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 3][x - 1] = StateCase::FILLED; // celle qui est 2 cases au dessus de notre bille
            break;
        case MoveAllowed::LEFT:
            board[y - 1][x - 2] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 1][x - 3] = StateCase::FILLED; // celle qui est 2 cases à gauche de notre bille
            break;
        case MoveAllowed::RIGHT:
            board[y - 1][x] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 1][x + 1] = StateCase::FILLED; // celle qui est 2 cases à droite de notre bille
            break;
    }

}

bool moveValid(size_t x, size_t y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    /**
     * xArray => x qui est dans notre tableau : 1 devient 0, 7 devient 6, ...
     * yArray => y qui est dans notre tableau : 1 devient 0, ...
     */
    size_t xArray = x - 1, yArray = y - 1;

    /**
     * Nous vérifions que nos transformations de position sont bien dans nos bornes et que la case que nous
     * souhaitons modifier est bien REMPLIE
     */
    if(xArray >= 0 && xArray < SIZE_BOARD &&
    yArray >= 0 && yArray < SIZE_BOARD &&
    board[yArray][xArray] == StateCase::FILLED){

        /**
         * En fonction de la direction désirée, nous allons vérifier que nos modifications de positions seront
         * bien dans nos bornes avec les tests précédents les différents "return"
         */

        switch (MoveAllowed(int(direction))) {
            case MoveAllowed::DOWN:
                if(y + 1 >= 0 && y + 1 < SIZE_BOARD)

                    // Si la case qui est juste en dessous de notre bille est bien une bille et que la case
                    // 2 emplacements en dessous de notre bille est vide, alors on retourne true sinon false

                    return board[y][xArray] == StateCase::FILLED && board[y + 1][xArray] == StateCase::DOT;
                break;
            case MoveAllowed::UP:
                if(y - 3 >= 0 && y - 3 < SIZE_BOARD)

                    // Si la case qui est juste en dessus de notre bille est bien une bille et que la case
                    // 2 emplacements en dessus de notre bille est vide, alors on retourne true sinon false

                    return board[y - 2][xArray] == StateCase::FILLED && board[y - 3][xArray] == StateCase::DOT;
                break;
            case MoveAllowed::LEFT:
                if(x - 3 >= 0 && x - 3 < SIZE_BOARD)

                    // Si la case qui est juste à gauche de notre bille est bien une bille et que la case
                    // 2 emplacements à gauche de notre bille est vide, alors on retourne true sinon false

                    return board[yArray][x - 2] == StateCase::FILLED && board[yArray][x - 3] == StateCase::DOT;
                break;
            case MoveAllowed::RIGHT:
                if(x + 1 >= 0 && x + 1 < SIZE_BOARD)

                    // Si la case qui est juste à droite de notre bille est bien une bille et que la case
                    // 2 emplacements à droite de notre bille est vide, alors on retourne true sinon false

                    return board[yArray][x] == StateCase::FILLED && board[yArray][x + 1] == StateCase::DOT;
                break;
        }
    }

    // Si aucun de nos tests est vrai, nous retournons faux

    return false;
}

bool gameOver(StateCase board[SIZE_BOARD][SIZE_BOARD]){

    /**
     * Nous allons analyser chacune de nos cases qui sont de type FILLED pour savoir si il est encore possible
     * d'avoir un déplacement. Si c'est le cas, alors on retourne true, sinon on continue jusqu'à ce que le programme
     * ne dise qu'aucun déplacement est possible, et la fonction retournera false
     */

    for(size_t i = 0; i < SIZE_BOARD; ++i){
        for(size_t j = 0; j < SIZE_BOARD; ++j){
            if(board[i][j] == StateCase::FILLED) {

                size_t x = j + 1, y = i + 1;

                // Vérifie si le déplacement est possible vers le haut
                bool upValid = moveValid(x, y, char(MoveAllowed::UP), board);
                // Vérifie si le déplacement est possible vers le bas
                bool downValid = moveValid(x, y, char(MoveAllowed::DOWN), board);
                // Vérifie si le déplacement est possible vers la gauche
                bool leftValid = moveValid(x, y, char(MoveAllowed::LEFT), board);
                // Vérifie si le déplacement est possible vers la droite
                bool rightValid = moveValid(x, y, char(MoveAllowed::RIGHT), board);

                if(upValid || downValid || leftValid || rightValid)
                    return true;
            }
        }
    }

    return false;
}