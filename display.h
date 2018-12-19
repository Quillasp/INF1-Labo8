#ifndef LABO8_DISPLAY_H
#define LABO8_DISPLAY_H

#include "global.h"

/**
 * Constantes d'affichage :
 * VOIDCASE : pour représenter les cases qui ne font pas partie du jeu
 * DOTCASE  : pour représenter les cases qui n'ont plus de billes
 * CHAR_REP : pour indiquer le nombre de fois qu'on veut voir le caractère apparaître
 */
const char VOIDCASE = ' ';
const char DOTCASE = '.';
const int CHAR_REP = 2;

/**
 * Affiche la table de jeu
 * @param board table de jeu à afficher
 */
void displayBoard(StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Permet d'afficher au joueur les différentes possibilités de coups qui peuvent être effectués
 * @param board table de jeu dont on doit afficher les possibilités de jeu
 */
void help(StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Affiche une phrase de fin de jeu quand il n'y a plus de possibilités de jeu et prenant en compte le nombre de billes
 * encore présentent sur la table de jeu. Et s'il n'en reste qu'une seule, indique si elle est au centre ou non.
 * @param board table de jeu qui permettra de faire le compte
 */
void displayWinCondition(StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Compte le nombre de billes encore présentent sur la table de jeu
 * @param board table de jeu dont on comptera les billes
 * @return le nombre de billes sur la table de jeu
 */
int countNumMarbles(StateCase board[SIZE_BOARD][SIZE_BOARD]);

#endif //LABO8_DISPLAY_H
