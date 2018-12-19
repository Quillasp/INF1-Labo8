//
// Variables globales - LABO8
//

#ifndef LABO8_GLOBAL_H
#define LABO8_GLOBAL_H

const int SIZE_BOARD = 7; // Taille du plateau de jeu
enum class StateCase { FILLED, VOID, DOT }; // Différents états du plateau de jeu
enum class MoveAllowed { DOWN = int('d'), UP = int('u'), RIGHT = int('r'), LEFT = int('l') }; // Directions autorisées

#endif //LABO8_GLOBAL_H
