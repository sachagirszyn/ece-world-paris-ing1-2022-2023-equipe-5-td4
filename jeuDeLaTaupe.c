//
// Created by 33778 on 21/05/2023.
//
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Définition de la structure Castor
typedef struct Castor
{
    int xPos;
    int yPos;
    int estActif;
} Castor;

// Déclaration des fonctions
void initAllegro();
void afficheInfo(char nomJoueur[2][20], int scoreJoueur[2], int joueurActif);
void finDeJeu(char nomJoueur[2][20], int joueurGagnant, BITMAP *bitmapGagnant);
void initCastor(Castor *castor);

// Initialisation des castors
void initCastor(Castor *castor)
{
    int compteur = 0, j;
    while (compteur <= 2)
    {
        int x = rand() % 5;
        int y = rand() % 3;

        int test = 1;
        for (j = 0; j < compteur; j++)
        {
            if (castor[j].xPos == x && castor[j].yPos == y)
            {
                test = 0;
            }
        }
        if (test)
        {
            castor[compteur].xPos = x;
            castor[compteur].yPos = y;
            castor[compteur].estActif = 1;
            compteur++;
        }
    }
}

// Fonction principale
int main()
{
    // Initialise le générateur de nombres aléatoires
    srand(time(NULL));
    char nomJoueur[2][20];
    int scoreJoueur[2] = {0, 0};
    int joueurActif = 0;
    Castor castors[3];
    clock_t debut, fin;
    debut = clock();

    // Initialisation des bitmaps
    BITMAP *bitmapCastor, *vide;
    BITMAP *tampon;
    BITMAP *perdu, *gagne;
    BITMAP *carteJeu;

    printf("Tapez le nom du premier joueur : ");
    scanf("%s", nomJoueur[0]);

    printf("Tapez le nom du deuxième joueur : ");
    scanf("%s", nomJoueur[1]);

    initAllegro();
    initCastor(castors);
    install_keyboard();
    install_mouse();

    BITMAP *sprite_souris = load_bitmap("C:\\allegro_projet\\marteau.png", NULL);
    if (!sprite_souris) {
        allegro_message("Erreur lors du chargement de l'image marteau.png");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    set_mouse_sprite(sprite_souris);
    show_mouse(screen);
    tampon = create_bitmap(SCREEN_W, SCREEN_H);
    carteJeu = load_bitmap("C:\\allegro_projet\\background.bmp", NULL);
    if (!carteJeu) {
        allegro_message("Erreur lors du chargement de l'image background.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    bitmapCastor = load_bitmap("C:\\allegro_projet\\taupe.bmp", NULL);
    if (!bitmapCastor) {
        allegro_message("Erreur lors du chargement de l'image taupe.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    vide = load_bitmap("C:\\allegro_projet\\t.png", NULL);
    if (!vide) {
        allegro_message("Erreur lors du chargement de l'image t.png");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    perdu = load_bitmap("C:\\allegro_projet\\gameover.bmp", NULL);
    if (!perdu) {
        allegro_message("Erreur lors du chargement de l'image gameover.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    gagne = load_bitmap("C:\\allegro_projet\\youwin.bmp", NULL);
    if (!gagne) {
        allegro_message("Erreur lors du chargement de l'image youwin.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int T = 0;
    debut = clock();

    int changement = 0;
    while (!key[KEY_ESC])
    {
        T++;
        clear_bitmap(tampon);
        stretch_blit(carteJeu, tampon, 0, 0, carteJeu->w, carteJeu->h, 0, 0, tampon->w, tampon->h);

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i == castors[0].xPos && j == castors[0].yPos && castors[0].estActif==1) ||
                    (i == castors[1].xPos && j == castors[1].yPos && castors[1].estActif==1) ||
                    (i == castors[2].xPos && j == castors[2].yPos && castors[2].estActif==1))
                {
                    stretch_blit(bitmapCastor, tampon, 0, 0, bitmapCastor->w, bitmapCastor->h, 35 + 150 * i, 120 + 130 * j, bitmapCastor->w, bitmapCastor->h);
                }
                else
                {
                    stretch_blit(vide, tampon, 0, 0, vide->w, vide->h, 35 + 150 * i, 120 + 130 * j, vide->w, vide->h);
                }
            }
        }

        if (mouse_b & 1)
        {
            for (int h = 0; h < 3; h++)
            {
                int cx = 35 + 150 * castors[h].xPos;
                int cy = 120 + 130 * castors[h].yPos;
                if (castors[h].estActif == 1 && mouse_x >= cx && mouse_x <= cx + bitmapCastor->w && mouse_y >= cy && mouse_y <= cy + bitmapCastor->h)
                {
                    castors[h].estActif = 0;
                    scoreJoueur[joueurActif]++;
                    if (scoreJoueur[joueurActif] >= 25)
                    {
                        joueurActif = (joueurActif == 0) ? 1 : 0;
                        if (scoreJoueur[0] != scoreJoueur[1])
                        {
                            int joueurGagnant = (scoreJoueur[0] > scoreJoueur[1]) ? 0 : 1;
                            finDeJeu(nomJoueur, joueurGagnant, gagne);
                            while (!key[KEY_ENTER])
                            {
                            }
                            return 0;
                        }
                    }
                    changement = 1;
                    break;
                }
            }
        }

        afficheInfo(nomJoueur, scoreJoueur, joueurActif);
        stretch_sprite(tampon, sprite_souris, mouse_x, mouse_y, sprite_souris->w, sprite_souris->h);
        blit(tampon, screen, 0, 0, 0, 0, tampon->w, tampon->h);

        if (T >= 150 || changement)
        {
            T = 0;
            initCastor(castors);
            changement = 0;
        }
    }

    return 0;
}

END_OF_MAIN()

// Fonction pour initialiser Allegro
void initAllegro()
{
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    {
        allegro_message(allegro_error);
        exit(EXIT_FAILURE);
    }
}

// Fonction pour afficher les informations du jeu
void afficheInfo(char nomJoueur[2][20], int scoreJoueur[2], int joueurActif)
{
    textprintf_ex(screen, font, 100, 50, makecol(255, 255, 255), -1, "Joueur actif : %s", nomJoueur[joueurActif]);
    textprintf_ex(screen, font, 300, 50, makecol(255, 255, 255), -1, "Score %s : %d", nomJoueur[0], scoreJoueur[0]);
    textprintf_ex(screen, font, 500, 50, makecol(255, 255, 255), -1, "Score %s : %d", nomJoueur[1], scoreJoueur[1]);
}

// Fonction pour afficher l'écran de fin de jeu
void finDeJeu(char nomJoueur[2][20], int joueurGagnant, BITMAP *bitmapGagnant)
{
    clear(screen);
    stretch_sprite(screen, bitmapGagnant, 0, 0, SCREEN_W, SCREEN_H);
    textprintf_centre_ex(screen, font, SCREEN_W / 2, SCREEN_H / 2, makecol(255, 255, 255), -1, "%s a gagné!", nomJoueur[joueurGagnant]);
}

