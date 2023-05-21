//
// Created by Julien on 21/05/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


#define MAX_BALLOONS 20
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct {
    int x;
    int y;
    bool active;
} Balloon;

typedef struct {
    int x;
    int y;
} Playerr;
typedef struct {
    int x;
    int y;
} Player;

Playerr player1;
Player player2;

Balloon balloons[MAX_BALLOONS];
Player player;

void initializeGame() {
    // Initialiser les ballons
    for (int i = 0; i < MAX_BALLOONS; i++) {
        balloons[i].x = rand() % (WINDOW_WIDTH - 2) + 1;
        balloons[i].y = rand() % (WINDOW_HEIGHT - 2) + 1;
        balloons[i].active = true;
    }

    // Initialiser les joueurs
    player1.x = WINDOW_WIDTH / 4;
    player1.y = WINDOW_HEIGHT - 1;

    player2.x = 3 * WINDOW_WIDTH / 4;
    player2.y = WINDOW_HEIGHT - 1;
}



void drawGame() {
    system("cls");  // Effacer l'écran

    // Dessiner les ballons
    for (int i = 0; i < MAX_BALLOONS; i++) {
        if (balloons[i].active) {
            COORD coord;
            coord.X = balloons[i].x;
            coord.Y = balloons[i].y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            printf("@");  // Afficher le ballon
        }
    }

    // Dessiner les joueurs
    COORD player1Coord;
    player1Coord.X = player1.x;
    player1Coord.Y = player1.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), player1Coord);
    printf("^");  // Afficher le joueur 1

    COORD player2Coord;
    player2Coord.X = player2.x;
    player2Coord.Y = player2.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), player2Coord);
    printf("V");  // Afficher le joueur 2
}


bool checkCollision(int x, int y) {
    for (int i = 0; i < MAX_BALLOONS; i++) {
        if (balloons[i].active && balloons[i].x == x && balloons[i].y == y) {
            if (checkBallonCollision(i)) {
                return false;
            }
            balloons[i].active = false;
            return true;
        }
    }
    return false;
}

bool checkBallonCollision(int index) {
    for (int i = 0; i < MAX_BALLOONS; i++) {
        if (i != index && balloons[i].active) {
            if (balloons[i].x == balloons[index].x && balloons[i].y == balloons[index].y) {
                return true;
            }
        }
    }
    return false;
}



int main() {
    srand(time(NULL));  // Initialiser le générateur de nombres aléatoires

    al_init();
    al_init_image_addon();

    ALLEGRO_DISPLAY *display = al_create_display(800, 600);

    ALLEGRO_BITMAP *image = al_load_bitmap(
            "C:\\Users\\Julien\\CLionProjects\\ECE_world\\ballon-de-baudruche-rouge.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(image, 100, 100, 0);
    al_flip_display();

    al_rest(3.0);  // Attendre 3 secondes

    al_destroy_bitmap(image);
    al_destroy_display(display);


    initializeGame();
    drawGame();

    int points = 0;
    int player1Points = 0;
    int player2Points = 0;

    while (points < MAX_BALLOONS) {
        if (_kbhit()) {
            int keyPressed = getch();

            // Vérifier les touches des joueurs pour détruire les ballons
            if (keyPressed == 'a' || keyPressed == 'A') {
                if (checkCollision(player1.x, player1.y - 1)) {
                    player1Points++;
                    points++;
                }
            }

            if (keyPressed == 'l' || keyPressed == 'L') {
                if (checkCollision(player2.x, player2.y - 1)) {
                    player2Points++;
                    points++;
                }
            }


            system("cls");
            printf("Vous avez détruit tous les ballons !\n");
            printf("Points: %d\n", points);
            printf("Joueur 1 : %d points\n", player1Points);
            printf("Joueur 2 : %d points\n", player2Points);

            return 0;
        }
    }
}
