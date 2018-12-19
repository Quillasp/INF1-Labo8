//
// Created by Bastien on 12.12.2018.
//

#ifndef LABO8_RULES_H
#define LABO8_RULES_H

#include "global.h"
#include <string>

const int DO_BETTER = 5;

/**
 * Le plateau est rempli de case d'état "FILLED". La fonction va modifier le tableau de StateCase passé en paramètre
 * pour lui assigner des états VOID et des états DOT à certaines cases précises
 * @param board Plateau de jeu à modifier
 */
void initGame(StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Déplace dans le plateau de jeu la bille à la position x et y dans la direction désirée (En haut, en bas,
 * à gauche, à droite). Le mouvement a été validé auparavant par la fonction "checkInputs".
 * @param x Position affichée en x de la bille
 * @param y Position affichée en y de la bille
 * @param direction Direction que nous souhaitons déplacer notre bille
 * @param board Plateau de jeu que nous modifierons
 */
void move(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Vérifie si le mouvement transmis est valide en fonction d'une bille en position x et y dans une direction voulue
 * @param x Position affichée en x de la bille
 * @param y Position affichée en y de la bille
 * @param direction Direction que nous souhaitons déplacer notre bille
 * @param board Plateau de jeu que nous modifierons
 * @return true si le mouvement est valide sinon false
 */
bool moveValid(int x, int y, char direction, StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Vérifie si il n'y a plus de déplacement possibles. Dans ce cas-là, la partie est terminée.
 * @param board Plateau de jeu que nous analyserons
 * @return true si il y a encore un déplacement sinon false
 */
bool gameOver(StateCase board[SIZE_BOARD][SIZE_BOARD]);

/**
 * Vérifie si l'entrée passé en paramètre est de longueur 3 et correspond bien à nos critères pour pouvoir jouer
 * @param userInput Entrée utilisateur
 * @param board Plateau de jeu que nous analyserons
 * @return true si l'input est valide sinon false
 */
bool checkInputs(std::string userInput, StateCase board[SIZE_BOARD][SIZE_BOARD]);

#endif //LABO8_RULES_H
