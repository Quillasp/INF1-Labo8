/*
-----------------------------------------------------------------------------------
Laboratoire : Labo7
Fichier     : main.cpp
Auteur(s)   : Pande Rochana, Potet Bastien, Lamrani Soulaymane
Date        : 11.12.2018

But         : Faire un jeu du solitaire jouable entièrement. 

Remarque(s) : Premier Labo avec une compilation séparée.

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "rules.h"
#include "display.h"

int main() {
    StateCase actualBoard[SIZE_BOARD][SIZE_BOARD] = {}; // Déclaration de la table de jeu
    const std::string MSG_ERROR = "Entree non valide"; // message d'erreur

    initGame(actualBoard); // initialisation du tableau définie dans rules.h/.cpp
    bool isValid, stopGame; // isValid : si le mouvement est valide
                            // stopGame : si le jeu est en Game Over ou non

    do{
        std::string inputUser; //entrée utilisateur
        displayBoard(actualBoard); // affichage de la table de jeu

        // indique si la partie est terminée ou non
        stopGame = gameOver(actualBoard);

        if(stopGame) {

            // demande une entrée utilisateur
            std::cout << "Entrez votre deplacement" << std::endl;
            std::cin >> inputUser;

            /**
             * Vérifie les entrées faites par l'utilisateur :
             * S'il n'y a qu'un seul caractère :
             * - h : commande help
             * - q : demande de quitter le jeur
             * - autre chose : message d'erreur
             * 
             * S'il y a 3 caractères :
             * - passe par une vérification avant d'être envoyée à la fonction qui déplacera la bille.
             * - si la vérification est fausse, message d'erreur
             *
             * Si ça n'a pas le bon format, on affiche simplement un message d'erreur.
             */
            if (inputUser.length() == 1) {
                if (inputUser.at(0) == 'h')
                    help(actualBoard);
                else if (inputUser.at(0) == 'q')
                    stopGame = false;
                else
                    std::cout << MSG_ERROR << std::endl;

            } else if (inputUser.length() == 3) {

                isValid = checkInputs(inputUser, actualBoard);

                if (isValid) {
                    char firstChar = inputUser.at(0), secondChar = inputUser.at(1);

                    int valFChar = firstChar - '0', valSChar = secondChar - '0';

                    move(valSChar, valFChar, char(tolower(inputUser.at(2))), actualBoard);
                } else {
                    std::cout << MSG_ERROR << std::endl;
                }
            }
            else{
                std::cout << MSG_ERROR << std::endl;
            }
        }
    }while(stopGame);

    displayWinCondition(actualBoard); // affichage de la phrase de fin de jeu

    return 0;
}