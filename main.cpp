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
#include "rules.cpp"
#include "display.cpp"

int main() {
    StateCase actualBoard[SIZE_BOARD][SIZE_BOARD] = {};

    initGame(actualBoard);

    displayBoard(actualBoard);

    return 0;
}