#include "rules.h"

#include <cstddef>
#include <iostream>

void initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]) {

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
    if (userInput.length() == 3) {

        char firstChar = userInput.at(0), secondChar = userInput.at(1);

        int valFChar = firstChar - '0', valSChar = secondChar - '0';

        bool value = moveValid(valSChar, valFChar, char(tolower(userInput.at(2))), board);

        return isdigit(firstChar) && isdigit(secondChar) && value;
    }

    return false;
}

void move(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]) {
    switch (MoveAllowed(int(direction))) {
        case MoveAllowed::DOWN:
            board[y][x - 1] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y + 1][x - 1] = StateCase::FILLED;
            break;
        case MoveAllowed::UP:
            board[y - 2][x - 1] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 3][x - 1] = StateCase::FILLED;
            break;
        case MoveAllowed::LEFT:
            board[y - 1][x - 2] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 1][x - 3] = StateCase::FILLED;
            break;
        case MoveAllowed::RIGHT:
            board[y - 1][x] = StateCase::DOT;
            board[y - 1][x - 1] = StateCase::DOT;
            board[y - 1][x + 1] = StateCase::FILLED;
            break;
    }

}

bool moveValid(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    int xArray = x - 1, yArray = y - 1;

    if(xArray >= 0 && xArray < SIZE_BOARD &&
    yArray >= 0 && yArray < SIZE_BOARD &&
    board[yArray][xArray] == StateCase::FILLED){
        switch (MoveAllowed(int(direction))) {
            case MoveAllowed::DOWN:
                if(y + 1 >= 0 && y + 1 < SIZE_BOARD)
                    return board[y][xArray] == StateCase::FILLED && board[y + 1][xArray] == StateCase::DOT;
                break;
            case MoveAllowed::UP:
                if(y - 3 >= 0 && y - 3 < SIZE_BOARD)
                    return board[y - 2][xArray] == StateCase::FILLED && board[y - 3][xArray] == StateCase::DOT;
                break;
            case MoveAllowed::LEFT:
                if(x - 3 >= 0 && x - 3 < SIZE_BOARD)
                    return board[yArray][x - 2] == StateCase::FILLED && board[yArray][x - 3] == StateCase::DOT;
                break;
            case MoveAllowed::RIGHT:
                if(x + 1 >= 0 && x + 1 < SIZE_BOARD)
                    return board[yArray][x] == StateCase::FILLED && board[yArray][x + 1] == StateCase::DOT;
                break;
        }
    }

    return false;
}

bool gameOver(StateCase board[SIZE_BOARD][SIZE_BOARD]){

    for(size_t i = 0; i < SIZE_BOARD; ++i){
        for(size_t j = 0; j < SIZE_BOARD; ++j){
            if(board[i][j] == StateCase::FILLED) {

                int x = j + 1, y = i + 1;

                bool b1 = moveValid(x, y, char(MoveAllowed::UP), board);
                bool b2 = moveValid(x, y, char(MoveAllowed::DOWN), board);
                bool b3 = moveValid(x, y, char(MoveAllowed::LEFT), board);
                bool b4 = moveValid(x, y, char(MoveAllowed::RIGHT), board);

                if(b1 || b2 || b3 || b4)
                    return true;
            }
        }
    }

    return false;
}