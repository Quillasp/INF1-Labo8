#ifndef LABO8_DISPLAY_H
#define LABO8_DISPLAY_H

#include "global.h"

const char VOIDCASE = ' ';
const char DOTCASE = '.';

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void help(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void displayCell(char c);

#endif //LABO8_DISPLAY_H
