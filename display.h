#ifndef LABO8_DISPLAY_H
#define LABO8_DISPLAY_H

#include "global.h"

const char VOIDCASE = 'v';
const char DOTCASE = 'd';

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void help(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void displayCell(char c);
void checkWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]);
int countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]);

#endif //LABO8_DISPLAY_H
