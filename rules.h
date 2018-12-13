//
// Created by Bastien on 12.12.2018.
//

#ifndef LABO8_RULES_H
#define LABO8_RULES_H

#include "global.h"
#include <string>

const int DO_BETTER = 5;

void initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void move(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]);
void countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void checkWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]);
void erase(int x, int y, StateCase board[SIZE_BOARD][SIZE_BOARD]);
bool moveValid(int x, int y, char direction);

bool checkInputs(std::string userInput);

#endif //LABO8_RULES_H
