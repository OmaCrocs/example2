#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
//https://ibb.co/6wQV27W grüner geist
//https://ibb.co/cDdhQL3 blauer Geist
//https://ibb.co/zFNRQR1

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

    // Define frame rectangle for drawing
    float frameHeight = (float) mute.height / NUM_FRAMES;
    Rectangle sourceRec = {0, 0, (float) mute.width, frameHeight};

    Rectangle btnBounds = {750, 750, 100, 100};
    int btnState = 0;
    bool btnAction = false;
    Vector2 mousePoint = {0.0f, 0.0f};


    //Theme Music
    InitAudioDevice();
    Music startmusic = LoadMusicStream("../assets/theme.mp3");
    PlayMusicStream(startmusic);
    while (!WindowShouldClose()) {
        //Button
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                btnState = 2;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                btnAction = true;
            }
        } else
            btnState = 0;
        sourceRec.y = btnState * frameHeight;


        BeginDrawing();
        DrawTexture(sound, 750, 750, WHITE);

        if (btnAction == true) {
            sound = LoadTexture("../assets/mute-button.png");
            DrawTexture(sound, 750, 750, WHITE);
            StopMusicStream(startmusic);
        }
        //TODO: START MUSIC STREAM AGAIN
        UpdateMusicStream(startmusic);

        //BUTTON


        //PACMAN TEXT
        ClearBackground(BLACK);
        DrawText("PACMAN", 240, 150, 100, RED);
        DrawText("PACMAN", 235, 155, 100, YELLOW);

        //PACMAN FIGURE
        DrawTexture(pacman_start, 100, 50, YELLOW);


        DrawText("Press SPACE to play!", 140, 550, 60, RED);
        DrawText("Press SPACE to play!", 135, 555, 60, YELLOW);


        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            //TODO: BUTTON INSTEAD OF SPACE!

            CloseWindow();
            StopMusicStream(startmusic);
            mapselect();
        }
    }

}

void mapselect() {
    printf("\n\nDONE\n\n");
}
