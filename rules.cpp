#include "rules.h"

#include <cstddef>

void initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]){

    for(std::size_t i = 0; i < SIZE_BOARD; ++i){
        for(std::size_t j = 0; j < SIZE_BOARD; ++j)
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

bool moveValid(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]){

    // Si x et y sont dans l'intervalle [ 0 - SIZE_BOARD [, il est considéré
    // sinon non

    switch (MoveAllowed(int(direction))) {
        case MoveAllowed::DOWN:
            return board[x][y + 2] == StateCase::DOT;
        case MoveAllowed::UP:
            return board[x][y - 2] == StateCase::DOT;
        case MoveAllowed::LEFT:
            return board[x - 2][y] == StateCase::DOT;
        case MoveAllowed::RIGHT:
            return board[x + 2][y] == StateCase::DOT;
        default:
            return false;
    }
}