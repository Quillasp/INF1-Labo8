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

        return isdigit(firstChar) && isdigit(secondChar) &&
               moveValid(valSChar, valFChar, char(tolower(userInput.at(2))), board);
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
        default:
            break;
    }

}

bool moveValid(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]) {

    if(board[y - 1][x - 1] == StateCase::FILLED) {
        switch (MoveAllowed(int(direction))) {
            case MoveAllowed::DOWN:
                return board[y + 1][x - 1] == StateCase::DOT;
            case MoveAllowed::UP:
                return board[y - 3][x - 1] == StateCase::DOT;
            case MoveAllowed::LEFT:
                return board[y - 1][x - 3] == StateCase::DOT;
            case MoveAllowed::RIGHT:
                return board[y - 1][x + 1] == StateCase::DOT;
            default:
                return false;
        }
    }

    return false;
}

bool gameOver(StateCase board[SIZE_BOARD][SIZE_BOARD]){

    for(size_t i = 0; i < SIZE_BOARD; ++i){
        for(size_t j = 0; j < SIZE_BOARD; ++j){
            if(board[i][j] == StateCase::FILLED) {
                if(moveValid(i, j, char(MoveAllowed::UP), board) ||
                moveValid(i, j, char(MoveAllowed::DOWN), board) ||
                moveValid(i, j, char(MoveAllowed::LEFT), board) ||
                moveValid(i, j, char(MoveAllowed::RIGHT), board))
                    return true;
            }
        }
    }

    return false;
}