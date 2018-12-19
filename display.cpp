#include "display.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

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

            // std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
}

void help(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    std::cout << "Deplacements possibles : ";

    for(size_t i = 0; i < SIZE_BOARD; ++i){
        for(size_t j = 0; j < SIZE_BOARD; ++j){
            if(board[i][j] == StateCase::DOT) {
                if(j + 2 >= 0 && j + 2 < SIZE_BOARD && board[i][j + 1] == StateCase::FILLED && board[i][j + 2] == StateCase::FILLED)
                    std::cout << i + 1 << j + 3 << 'l' << " ";// RIGHT
                if(j - 2 >= 0 && j - 2 < SIZE_BOARD && board[i][j - 1] == StateCase::FILLED && board[i][j - 2] == StateCase::FILLED)
                    std::cout << i + 1 << j - 1 << 'r' << " "; // LEFT
                if(i + 2 >= 0 && i + 2 < SIZE_BOARD && board[i + 1][j] == StateCase::FILLED && board[i + 2][j] == StateCase::FILLED)
                    std::cout << i + 3 << j + 1 << 'u' << " "; // UP
                if(i - 2 >= 0 && i - 2 < SIZE_BOARD && board[i - 1][j] == StateCase::FILLED && board[i - 2][j] == StateCase::FILLED)
                    std::cout << i - 1 << j + 1 << 'd' << " "; // DOWN
            }
        }
    }

    std::cout << std::endl;
}

void displayWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    int nbMarbles = countNumMarbles(board);

    if (nbMarbles > 5) {
        std::cout << "Vous pouvez faire mieux, il reste " << nbMarbles << " billes." << std::endl;
    } else if (nbMarbles < 5 && nbMarbles >= 2) {
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

    for (size_t i = 0; i < SIZE_BOARD; ++i) {
        for (size_t j = 0; j < SIZE_BOARD; ++j) {
            if (board[i][j] == StateCase::FILLED) {
                counter++;
            }
        }
    }

    return counter;
}