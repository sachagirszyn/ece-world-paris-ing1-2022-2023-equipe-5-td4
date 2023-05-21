//
// Created by girsz on 21/05/2023.
//
#include "allegro.h"
#include <stdio.h>
#include "map.h"
#include "personnage.h"

void RemplirMatrice(int tab[5][10]){
    for(int i=0;i<5;i++){
        for (int j=0;j<10;j++){
            tab[i][j]=FOND;
        }

    }for (int i=1;i<=9;i++){
        tab[2][i]=FOND;
        tab[1][3]=FOND;
        tab[3][6]=FOND;

    }
    tab[0][3]=MAISON;
    tab[4][2]=MAISON2;
    tab[3][8]=MAISON3;
    tab[1][5]=MAISON4;
    tab[2][0]=MAISON5;
    tab[0][9]=TROUNOIR;
}


void InsererImage(BITMAP* Image , BITMAP* ImageAInserer, int x, int y){
    blit(ImageAInserer, Image, 0, 0, 80*x, 120*y, 80, 120);
}

void AfficherImage(BITMAP* Image){
    blit(Image,screen,0,0,0,0,Image->w,Image->h);
}

void InsererPersonnage(struct Personnage Personnage, BITMAP* ImageTemporaire){
    if(Personnage.DirectionActuelle==DROITE){
        draw_sprite(ImageTemporaire,Personnage.spriteDroite,Personnage.y*80+Personnage.offset,Personnage.x*120+20);
    }else if (Personnage.DirectionActuelle==GAUCHE){
        draw_sprite(ImageTemporaire,Personnage.spriteGauche,Personnage.y*80,Personnage.x*120+20);
    }else if(Personnage.DirectionActuelle==HAUT){
        draw_sprite(ImageTemporaire,Personnage.spriteHaut,Personnage.y*80,Personnage.x*120+20);
    }else if(Personnage.DirectionActuelle==BAS){
        draw_sprite(ImageTemporaire,Personnage.spriteBAS,Personnage.y*80,Personnage.x*120+20);
    }
}
void InsererMaison(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageMaison,x*80,y*120);
}

void InsererMaison2(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageMaison2,x*80,y*120);
}

void InsererMaison3(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageMaison3,x*80,y*120);
}

void InsererMaison4(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageMaison4,x*80,y*120);
}

void InsererMaison5(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageMaison5,x*80,y*120);
}

void InsererTrouNoir(BITMAP* ImageTemporaire , int x, int y){
    blit(ImageGazon,ImageTemporaire,0,0,x*80,y*120,80,120);
    draw_sprite(ImageTemporaire,ImageTrouNoir,x*80,y*120);
}
/*void NombreDeTickets(int tab[5][10], BITMAP* ImageTemporaire, int ticket, struct Personnage Personnage) {

    if ((tab[Personnage.x][Personnage.y] == MAISON || tab[Personnage.x][Personnage.y] == MAISON2 || tab[Personnage.x][Personnage.y] == MAISON3 || tab[Personnage.x][Personnage.y] == MAISON4 || tab[Personnage.x][Personnage.y] == MAISON5)&& ticket!=0) {
        ticket = ticket - 1;
    }else if(ticket==0){
        blit(ImageDefaite,ImageTemporaire,0,0,0,0,800,600);
    }
    char ticketText[20];
    sprintf(ticketText, "Tickets: %d", ticket);
    textout_centre_ex(ImageTemporaire, font, ticketText, 80, 10, makecol(255, 0, 0), -1);
}*/



void BougerPersonnage(int x, int y,struct Personnage* Personnage,BITMAP* ImageTemporaire, int tab[5][10]){
    int AncienPosX=Personnage->x;
    int AncienPosY=Personnage->y;
    if(Personnage->x+x>=5|| Personnage->x+x<0){
        return;
    }else if(Personnage->y+y>=10|| Personnage->y+y<0){
        return;
    }
    Personnage->x+=x;
    Personnage->y+=y;
    InsererPersonnage(*Personnage,ImageTemporaire);
    if(tab[AncienPosX][AncienPosY]==FOND){
        blit(ImageGazon,ImageTemporaire,0,0,AncienPosY*80,AncienPosX*120,80,120);
    }else if (tab[AncienPosX][AncienPosY]==MAISON){
        InsererMaison(ImageTemporaire,AncienPosY,AncienPosX);
        //NombreDeTickets(tab,ImageTemporaire,5,*Personnage);
    }else if (tab[AncienPosX][AncienPosY] == MAISON2) {
        InsererMaison2(ImageTemporaire, AncienPosY, AncienPosX);
    } else if (tab[AncienPosX][AncienPosY] == MAISON3) {
        InsererMaison3(ImageTemporaire, AncienPosY, AncienPosX);
    } else if (tab[AncienPosX][AncienPosY] == MAISON4) {
        InsererMaison4(ImageTemporaire, AncienPosY, AncienPosX);
    } else if (tab[AncienPosX][AncienPosY] == MAISON5) {
        InsererMaison5(ImageTemporaire, AncienPosY, AncienPosX);
    }else if(tab[AncienPosX][AncienPosY] == TROUNOIR){
        InsererTrouNoir(ImageTemporaire, AncienPosY, AncienPosX);
    }
    AfficherImage(ImageTemporaire);
}

void AfficherBackground(BITMAP* ImageTemporaire,int tab[5][10]) {
    ImageGazon = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\fond.bmp", NULL);
    ImageBeton = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Beton2.bmp", NULL);
    ImageMaison=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Maison.bmp", NULL);
    ImageMaison2 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Maison2.bmp", NULL);
    ImageMaison3 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Maison3.bmp", NULL);
    ImageMaison4 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Maison4.bmp", NULL);
    ImageMaison5 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Maison5.bmp", NULL);
    ImageTrouNoir= load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\TrouNoir.bmp",NULL);
    ImageFin=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Fin2.bmp", NULL);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (tab[i][j] == FOND) {
                InsererImage(ImageTemporaire, ImageGazon, j, i);
            } else if (tab[i][j] == BETON) {
                InsererImage(ImageTemporaire, ImageBeton, j, i);
            } else if (tab[i][j] == MAISON) {
                InsererMaison(ImageTemporaire, j, i);
            } else if (tab[i][j] == MAISON2) {
                InsererMaison2(ImageTemporaire, j, i);
            } else if (tab[i][j] == MAISON3) {
                InsererMaison3(ImageTemporaire, j, i);
            } else if (tab[i][j] == MAISON4) {
                InsererMaison4(ImageTemporaire, j, i);
            } else if (tab[i][j] == MAISON5) {
                InsererMaison5(ImageTemporaire, j, i);
            }else if(tab[i][j]==TROUNOIR){
                InsererTrouNoir(ImageTemporaire,j,i);

            }
        }
    }
    AfficherImage(ImageTemporaire);
}

void CreerMatriceJeu(int tab[5][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {tab[i][j] = FOND;}
        tab[0][0]=DEPART;
        tab[1][0]=DEPART2;
        tab[2][0]=DEPART3;
        tab[3][0]=DEPART4;
        tab[4][0]=DEPART5;
        tab[0][9]=FIN;
        tab[1][9]=FIN;
        tab[2][9]=FIN;
        tab[3][9]=FIN;
        tab[4][9]=FIN;
    }
}

void AfficherLeTerrain(int x, int y, int tab[5][10], BITMAP* ImageTemporaire){
    if (tab[x][y] == FOND) {
        InsererImage(ImageTemporaire, ImageFond, y, x);
    } else if (tab[x][y] == DEPART) {
        InsererImage(ImageTemporaire, ImageDepart1, y, x);
    } else if (tab[x][y] == DEPART2) {
        InsererImage(ImageTemporaire, ImageDepart2, y, x);
    } else if (tab[x][y] == DEPART3) {
        InsererImage(ImageTemporaire, ImageDepart3, y, x);
    } else if (tab[x][y] == DEPART4) {
        InsererImage(ImageTemporaire, ImageDepart4, y, x);
    } else if (tab[x][y] == DEPART5) {
        InsererImage(ImageTemporaire, ImageDepart5, y, x);
    }else if (tab[x][y] == FIN) {
        InsererImage(ImageTemporaire, ImageFinDeCourse, y, x);
    }
}

void AfficherBackgroundJeu(BITMAP* ImageTemporaire,int tab[5][10]) {
    ImageFond = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\fondJeu.bmp", NULL);
    ImageDepart1 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Depart1.bmp", NULL);
    ImageDepart2 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Depart2.bmp", NULL);
    ImageDepart3 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Depart3.bmp", NULL);
    ImageDepart4 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Depart4.bmp", NULL);
    ImageDepart5 = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Depart5.bmp", NULL);
    ImageFinDeCourse=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Fin.bmp", NULL);
    ImageFin = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Fin2.bmp", NULL);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            AfficherLeTerrain(i, j, tab, ImageTemporaire);
        }
        AfficherImage(ImageTemporaire);
    }
}

void AfficherPersonnage(struct Personnage Personnage, BITMAP* ImageTemporaire){
    InsererPersonnage(Personnage,ImageTemporaire);
    AfficherImage(ImageTemporaire);
}

