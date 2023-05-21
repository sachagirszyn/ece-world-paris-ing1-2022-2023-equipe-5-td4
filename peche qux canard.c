//
// Created by leona on 21/05/2023.
//

#include "peche qux canard.h"
#include <stdio.h>
#include <allegro.h>
#include <time.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CANARD_WIDTH 64
#define CANARD_HEIGHT 64


BITMAP* canardBitmap;
int score = 0;
int timeRemaining = 60;
BITMAP* screen;

void updateScore() {
    textprintf_ex(screen, font, 10, 10, makecol(255, 255, 255), -1, "Score: %d", score);
}

void updateTime() {
    textprintf_ex(screen, font, SCREEN_WIDTH - 100, 10, makecol(255, 255, 255), -1, "Time: %d", timeRemaining);
}


void updateScreen() {
    clear_bitmap(screen);
    updateScore();
    updateTime();
    show_mouse(screen);
}

int main() {int mouseX, mouseY;
    int canardX, canardY;
    int mousePressed = 0;

    // Initialisation d'Allegro
    allegro_init();
    install_keyboard();
    install_mouse();
    printf("aaaa");

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0) != 0) {
        allegro_message("Erreur lors du passage en mode graphique.");
        return 1;
    }

    // Chargement de l'image du canard
    canardBitmap = load_bitmap("canard.bmp", NULL);
    if (!canardBitmap) {
        allegro_message("Erreur lors du chargement de l'image du canard.");
        return 1;
    }

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Boucle principale du jeu
    while (timeRemaining > 0) {
        updateScreen();

        // Génération de la position du canard
        canardX = rand() % (SCREEN_WIDTH - CANARD_WIDTH);
        canardY = rand() % (SCREEN_HEIGHT - CANARD_HEIGHT);

        // Affichage du canard
        blit(canardBitmap, screen, 0, 0, canardX, canardY, CANARD_WIDTH, CANARD_HEIGHT);

        // Attente d'un clic de souris
        while (!mousePressed) {
            if (mouse_b & 1) {
                mousePressed = 1;
                break;
            }
        }

        // Vérification si le clic est sur le canard
        get_mouse_mickeys(&mouseX, &mouseY);
        if (mouseX >= canardX && mouseX <= canardX + CANARD_WIDTH &&
            mouseY >= canardY && mouseY <= canardY + CANARD_HEIGHT) {
            score++;
        }

        // Réinitialisation des variables
        mousePressed = 0;

        // Mise à jour du temps restant
        rest(1000);  // Attente d'une seconde
        timeRemaining--;
    }

    // Affichage du score final
    updateScreen();
    textprintf_ex(screen, font, SCREEN_WIDTH / 2 - 40, SCREEN_HEIGHT / 2, makecol(255, 255, 255), -1, "Score final: %d", score);
    rest(3000);  // Attente de 3 secondes avant de quitter

    // Libération de la mémoire
    destroy_bitmap(canardBitmap);
    allegro_exit();
    return 0;

}

