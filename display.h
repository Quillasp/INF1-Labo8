//
// Created by Bastien on 12.12.2018.
//

#ifndef LABO8_DISPLAY_H
#define LABO8_DISPLAY_H

const int SIZE_BOARD = 7;
const enum class StateCase = { FILLED, VOID, DOT };
const char VOIDCASE = ' ';
const char DOTCASE = '.';

void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void help(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void displayCell(char c);

#endif //LABO8_DISPLAY_H
