#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#define WIDTH 900
#define HEIGHT 900
#define NUM_FRAMES 1

//Predeclaration
void startscreen();

void mapselect();


int main() {
    //TODO: HIGHSCORE!
    //TODO: MAP CHOOSE!
    //TODO: ANIMATION BEFORE CLOSING STARTSCREEN!
    //TOFIX: OTHER FONT/DESIGN ON STARTSCREEN!
    //ME MINIMALZIEL: 1 MAP

    //TODO: MUTE BUTTON WITH PIXELCREATOR

    startscreen();

    return EXIT_SUCCESS;
}

void startscreen() {

    InitWindow(WIDTH, HEIGHT, "PacMan");
    SetTargetFPS(60);

    //Buttons
    Texture2D mute = LoadTexture("../assets/mute-mute.png");
    Texture2D sound = LoadTexture("../assets/sound-button.png");
    Texture2D pacman_start = LoadTexture("../assets/pacman-start.png");
    Texture2D play = LoadTexture("../assets/play-button.png");
    Texture2D logo = LoadTexture("../assets/logo.png");

    // Define frame rectangle for drawing
    float frameHeight = (float) mute.height / NUM_FRAMES;
    Rectangle sourceRec = {0, 0, (float) mute.width, frameHeight};

    Rectangle btnBoundsSound = {750, 750, 100, 100};
    Rectangle btnBoundsPlay = {350, 600, 200, 200};
    int btnState = 0;
    bool btnActionSound = false;
    bool btnActionPlay = false;
    Vector2 mousePoint = {0.0f, 0.0f};


    //Theme Music
    InitAudioDevice();
    Music startmusic = LoadMusicStream("../assets/theme.mp3");
    PlayMusicStream(startmusic);
    while (!WindowShouldClose()) {
        //Button
        mousePoint = GetMousePosition();
        btnActionSound = false;
        btnActionPlay = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsSound)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                btnState = 2;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                btnActionSound = true;
            }
        } else if (CheckCollisionPointRec(mousePoint, btnBoundsPlay)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                btnState = 2;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                btnActionPlay = true;
            }
        }
        btnState = 0;
        sourceRec.y = btnState * frameHeight;


        BeginDrawing();
        DrawTexture(sound, 750, 750, WHITE);
        DrawTexture(play, 350, 600, WHITE);
        DrawTexture(logo, 100, 100, WHITE);

        if (btnActionPlay == true) {
            mapselect();
        }

        if (btnActionSound == true) {
            sound = LoadTexture("../assets/mute-button.png");
            DrawTexture(sound, 750, 750, WHITE);
            StopMusicStream(startmusic);
        }
        //TODO: START MUSIC STREAM AGAIN
        UpdateMusicStream(startmusic);

        //BUTTON


        //PACMAN TEXT
        ClearBackground(BLACK);

        //PACMAN FIGURE
        DrawTexture(pacman_start, 270, 215, YELLOW);


        EndDrawing();

    }

}

void mapselect() {
    printf("\n\nDONE\n\n");
}
