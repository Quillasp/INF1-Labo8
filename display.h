#ifndef LABO8_DISPLAY_H
#define LABO8_DISPLAY_H

#include "global.h"

const char VOIDCASE = ' ';
const char DOTCASE = '.';
const int CHAR_REP = 2;

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void help(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void displayWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]);
int countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]);

#endif //LABO8_DISPLAY_H
