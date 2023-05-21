//
// Created by girsz on 21/05/2023.
//

#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H
#include "allegro.h"
enum direction{
    GAUCHE,
    DROITE,
    HAUT,
    BAS
};

struct Personnage{
    BITMAP* spriteGauche;
    BITMAP* spriteDroite;
    BITMAP* spriteHaut;
    BITMAP* spriteBAS;
    int x;
    int y;
    int vitesse;
    int offset;
    int DirectionActuelle;
};
#endif //PROJET_PERSONNAGE_H
