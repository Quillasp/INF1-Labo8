#include "display.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    for (std::size_t i = 0; i < SIZE_BOARD + 0; ++i) {
        for (std::size_t j = 0; j < SIZE_BOARD + 0; ++j) {
        
            switch (board[i][j]) {

                case StateCase::FILLED :
                    std::cout << i + 1 << j + 1 << std::setw(1);
                    break;

                case StateCase::VOID :
                    displayCell(VOIDCASE);
                    break;

                case StateCase::DOT :
                    displayCell(DOTCASE);
            }

            std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
}

void help(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    
}

void displayCell(char c) {

    std::cout << std::setfill(c) << std::setw(2);
    std::cout << std::setw(1);
}