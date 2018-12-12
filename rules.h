//
// Created by Bastien on 12.12.2018.
//

#ifndef LABO8_RULES_H
#define LABO8_RULES_H

initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]);
move(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]);
countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]);
checkWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]);
erase(int x, int y, StateCase board[SIZE_BOARD][SIZE_BOARD]);

#endif //LABO8_RULES_H
