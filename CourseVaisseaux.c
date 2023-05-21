//
// Created by girsz on 21/05/2023.
//
#include "allegro.h"
#include "CourseVaisseaux.h"
#include <stdio.h>
#include "map.h"
#include "personnage.h"



int DeplacementVaisseau(struct Personnage* Personnage,int tab [5][10],BITMAP *ImageTemporaire){
    AfficherLeTerrain(Personnage->x,Personnage->y,tab,ImageTemporaire);
    AfficherLeTerrain(Personnage->x,Personnage->y+1,tab,ImageTemporaire);
    Personnage->offset+=Personnage->vitesse;
    if(Personnage->offset>=80){
        Personnage->y+=1;
        Personnage->offset%=80;
    }
    //printf("%d %d %d\n",Personnage->x,Personnage->y,Personnage->offset);
    InsererPersonnage(*Personnage,ImageTemporaire);
    return Personnage->y>=8 && Personnage->offset>14;
}

void AssignerVitesse(struct Personnage *Personnages[5]){
    int IndexGagnant=rand()%5;
    Personnages[IndexGagnant]->vitesse=10;
    for (int i=0;i<=4;i++){
        if(i==IndexGagnant){
            continue;
        }
        Personnages[i]->vitesse=rand()%10+7;
    }
}

void demandeParier(int* nbTickets, int* numChevaux, BITMAP* ImageTemporaire, struct Personnage *Personnages[5]) {


    clear_to_color(ImageTemporaire, makecol(255, 255, 255));
    textout_centre_ex(ImageTemporaire, font, "Combien de tickets souhaitez-vous parier ?", SCREEN_W / 2, SCREEN_H / 2 - 20, makecol(0, 0, 0), -1);
    textout_centre_ex(ImageTemporaire, font, "Appuyez sur Entrée pour valider.", SCREEN_W / 2, SCREEN_H / 2 + 20, makecol(0, 0, 0), -1);

    while (!key[KEY_ENTER]) {
        poll_keyboard();

        if (key[KEY_0]) {
            *nbTickets = 0;
        }
        else if (key[KEY_1]) {
            *nbTickets = 1;
        }
        else if (key[KEY_2]) {
            *nbTickets = 2;
        }
        else if (key[KEY_3]) {
            *nbTickets = 3;
        }
        else if (key[KEY_4]) {
            *nbTickets = 4;
        }
        else if (key[KEY_5]) {
            *nbTickets = 5;
        }

        if (key[KEY_6]) {
            *numChevaux = 1;
        }
        else if (key[KEY_7]) {
            *numChevaux = 2;
        }
        else if (key[KEY_8]) {
            *numChevaux = 3;
        }
        else if (key[KEY_9]) {
            *numChevaux = 4;
        }
        else if (key[KEY_0]) {
            *numChevaux = 5;
        }

        rest(10);
    }

    clear_to_color(ImageTemporaire, makecol(255, 255, 255));
    textprintf_centre_ex(ImageTemporaire, font, SCREEN_W / 2, SCREEN_H / 2, makecol(0, 0, 0), -1, "Vous avez choisi de parier sur %d ticket(s) et le cheval numéro %d.", *nbTickets, *numChevaux);
    rest(2000);
}




void JeuxCourseVaisseau(){
    int tab[5][10];
    int nbTickets=0;
    int numChevaux=0;
    BITMAP *ImageTemporaire;
    ImageTemporaire = create_bitmap(800, 600);
    struct Personnage Personnage1;
    struct Personnage Personnage2;
    struct Personnage Personnage3;
    struct Personnage Personnage4;
    struct Personnage Personnage5;
    struct Personnage *Personnages[5] = {&Personnage1, &Personnage2, &Personnage3, &Personnage4, &Personnage5,};

    CreerMatriceJeu(tab);
    //demandeParier(&nbTickets,&numChevaux,ImageTemporaire,Personnages);
    AfficherBackgroundJeu(ImageTemporaire, tab);


    Personnage1.spriteDroite = load_bitmap("C:\\Users\\girsz\\CLionProjects\\Allegro2\\Texture\\PersonnageDroite.bmp", NULL);
    Personnage1.x = 0;
    Personnage1.y = 0;
    Personnage1.offset = 0;
    Personnage1.vitesse = rand() % 11 + 7;
    Personnage1.DirectionActuelle = DROITE;
    AfficherPersonnage(Personnage1, ImageTemporaire);

    Personnage2.spriteDroite = Personnage1.spriteDroite;
    Personnage2.x = 1;
    Personnage2.y = 0;
    Personnage2.offset = 0;
    Personnage2.vitesse = rand() % 11 + 7;
    Personnage2.DirectionActuelle = DROITE;
    AfficherPersonnage(Personnage2, ImageTemporaire);

    Personnage3.spriteDroite = Personnage1.spriteDroite;
    Personnage3.x = 2;
    Personnage3.y = 0;
    Personnage3.offset = 0;
    Personnage3.vitesse = rand() % 11 + 7;;
    Personnage3.DirectionActuelle = DROITE;
    AfficherPersonnage(Personnage3, ImageTemporaire);

    Personnage4.spriteDroite = Personnage1.spriteDroite;
    Personnage4.x = 3;
    Personnage4.y = 0;
    Personnage4.offset = 0;
    Personnage4.vitesse = rand() % 11 + 7;;
    Personnage4.DirectionActuelle = DROITE;
    AfficherPersonnage(Personnage4, ImageTemporaire);

    Personnage5.spriteDroite = Personnage1.spriteDroite;
    Personnage5.x = 4;
    Personnage5.y = 0;
    Personnage5.offset = 0;
    Personnage5.vitesse = rand() % 11 + 7;
    Personnage5.DirectionActuelle = DROITE;
    AfficherPersonnage(Personnage5, ImageTemporaire);


    AssignerVitesse(Personnages);
    while (1){
        rest(100);
        if (DeplacementVaisseau(&Personnage1,tab,ImageTemporaire)){
            blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);
            break;

        }if (DeplacementVaisseau(&Personnage2,tab,ImageTemporaire)){
            blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);

            break;
        }if (DeplacementVaisseau(&Personnage3,tab,ImageTemporaire)){
            blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);

            break;
        }if (DeplacementVaisseau(&Personnage4,tab,ImageTemporaire)){
            blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);

            break;
        }if (DeplacementVaisseau(&Personnage5,tab,ImageTemporaire)){
            blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);

            break;
        }
        blit(ImageTemporaire, screen,0, 0, 0, 0, 800, 600);
    }

}
