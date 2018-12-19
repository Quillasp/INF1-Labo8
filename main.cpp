/*
-----------------------------------------------------------------------------------
Laboratoire : Labo7
Fichier     : main.cpp
Auteur(s)   : Pande Rochana, Potet Bastien, Lamrani Soulaymane
Date        : 11.12.2018

But         :

Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "rules.h"
#include "display.h"

int main() {
    StateCase actualBoard[SIZE_BOARD][SIZE_BOARD] = {};
    const std::string MSG_ERROR = "Entree non valide";

    initGame(actualBoard);
    bool isValid, stopGame;

    do{
        std::string inputUser;
        displayBoard(actualBoard);

        stopGame = gameOver(actualBoard);

        if(stopGame) {

            std::cout << "Entrez votre deplacement" << std::endl;
            std::cin >> inputUser;

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

    displayWinCondition(actualBoard);

    return 0;
}