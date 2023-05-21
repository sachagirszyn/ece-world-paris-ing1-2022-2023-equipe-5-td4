//
// Created by girsz on 21/05/2023.
//

#ifndef PROJET_MAP_H
#define PROJET_MAP_H
#include "allegro.h"
#include "personnage.h"

enum typedeTerrain{
    FOND=0,
    BETON,
    MAISON,
    MAISON2,
    MAISON3,
    MAISON4,
    MAISON5,
    TROUNOIR,
    DEPART,
    DEPART2,
    DEPART3,
    DEPART4,
    DEPART5,
    FIN
};

BITMAP *ImageBeton;
BITMAP *ImageMaison;
BITMAP *ImageGazon;
BITMAP *ImageMaison2;
BITMAP *ImageMaison3;
BITMAP *ImageMaison4;
BITMAP *ImageMaison5;
BITMAP *ImageTrouNoir;
BITMAP *ImageFin;
BITMAP *ImageFond;
BITMAP *ImageDepart1;
BITMAP *ImageDepart2;
BITMAP *ImageDepart3;
BITMAP *ImageDepart4;
BITMAP *ImageDepart5;
BITMAP *ImageFinDeCourse;
BITMAP* ImageGagnant;
BITMAP* ImagePerdant;

void AfficherImage(BITMAP* Image);
void RemplirMatrice(int tab[5][10]);
void CreerMatriceJeu(int tab[5][10]);
void InsererMaison(BITMAP* ImageTemporaire , int x, int y);
void InsererMaison2(BITMAP* ImageTemporaire , int x, int y);
void InsererMaison3(BITMAP* ImageTemporaire , int x, int y);
void InsererMaison4(BITMAP* ImageTemporaire , int x, int y);
void InsererMaison5(BITMAP* ImageTemporaire , int x, int y);
void InsererTrouNoir(BITMAP* ImageTemporaire , int x, int y);
void AfficherBackground(BITMAP* ImageTemporaire,int tab[5][10]);
void InsererImage(BITMAP* Image , BITMAP* ImageAInserer, int x, int y);
void InsererPersonnage(struct Personnage Personnage, BITMAP* ImageTemporaire);
void BougerPersonnage(int x, int y,struct Personnage* Personnage,BITMAP* ImageTemporaire, int tab[5][10]);
void AfficherBackgroundJeu(BITMAP* ImageTemporaire,int tab[5][10]);
void AfficherLeTerrain(int x, int y, int tab[5][10], BITMAP* ImageTemporaire);
void AfficherPersonnage(struct Personnage Personnage, BITMAP* ImageTemporaire);
#endif //PROJET_MAP_H
