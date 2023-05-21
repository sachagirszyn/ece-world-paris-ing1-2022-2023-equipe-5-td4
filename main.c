#include<allegro.h>// inclusion de la librairie
#include "map.h"
#include "personnage.h"
#include <stdio.h>
#include "CourseVaisseaux.h"



void VerificationJeux(BITMAP* ImageTemporaire, int tab[5][10],struct Personnage *Personnage){
    if(tab[Personnage->x][Personnage->y]==MAISON){
        JeuxCourseVaisseau();
        BougerPersonnage(0, 1,Personnage,ImageTemporaire,tab);
        AfficherImage(ImageTemporaire);
    }else if(tab[Personnage->x][Personnage->y]==MAISON2){

        BougerPersonnage(0, 1,Personnage,ImageTemporaire,tab);
        AfficherImage(ImageTemporaire);
    }else if(tab[Personnage->x][Personnage->y]==MAISON3){

        BougerPersonnage(0, 1,Personnage,ImageTemporaire,tab);
        AfficherImage(ImageTemporaire);
    }else if(tab[Personnage->x][Personnage->y]==MAISON4){

        BougerPersonnage(0, 1,Personnage,ImageTemporaire,tab);
        AfficherImage(ImageTemporaire);
    }else if(tab[Personnage->x][Personnage->y]==MAISON5){

        BougerPersonnage(0, 1,Personnage,ImageTemporaire,tab);
        AfficherImage(ImageTemporaire);
    }
}

int main(){
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0){
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
    BITMAP* ImageWelcome=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\Welcome.bmp",NULL);
    blit(ImageWelcome,screen,0,0,0,0,800,600);
    rest(2000);


    int tab[5][10];
    int ticket=5;
    BITMAP* ImageTemporaire;
    ImageTemporaire= create_bitmap(800,600);
    RemplirMatrice(tab);
    AfficherBackground(ImageTemporaire,tab);
    struct Personnage Personnage1;
    Personnage1.spriteGauche=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\PersonnageGauche.bmp",NULL);
    Personnage1.spriteDroite=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\PersonnageDroite.bmp",NULL);
    Personnage1.spriteHaut=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\VersleHaut.bmp",NULL);
    Personnage1.spriteBAS=load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\VersleBas.bmp",NULL);
    Personnage1.x=1;
    Personnage1.y=8;
    Personnage1.offset=0;
    Personnage1.vitesse=0;
    Personnage1.DirectionActuelle=DROITE;
    InsererPersonnage(Personnage1,screen);


    while (!key[KEY_ESC]){
        rest(75);
        if(key[KEY_LEFT]){
            Personnage1.DirectionActuelle=GAUCHE;
            BougerPersonnage(0, -1,&Personnage1,ImageTemporaire,tab);

        }else if(key[KEY_RIGHT]){
            Personnage1.DirectionActuelle=DROITE;
            BougerPersonnage(0, 1,&Personnage1,ImageTemporaire,tab);

        }else if(key[KEY_UP]){
            Personnage1.DirectionActuelle=HAUT;
            BougerPersonnage(-1, 0,&Personnage1,ImageTemporaire,tab);

        }else if(key[KEY_DOWN]){
            Personnage1.DirectionActuelle=BAS;
            BougerPersonnage(1, 0,&Personnage1,ImageTemporaire,tab);

        }else if(tab[Personnage1.x][Personnage1.y]==tab[0][9]){
            AfficherImage(ImageFin);
            rest(1000);
            break;
        }
        //NombreDeTickets(tab, ImageTemporaire, 5,Personnage1);
        VerificationJeux(ImageTemporaire,tab,&Personnage1);
    }
    return 0;
} END_OF_MAIN();