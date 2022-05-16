#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#define WIDTH 900
#define HEIGHT 900

//Predeclaration
void startscreen();

void mapselect();


int main() {
    //TODO: HIGHSCORE!
    //TODO: MAP CHOOSE!
    //TODO: ANIMATION BEFORE CLOSING STARTSCREEN!
    //TOFIX: OTHER FONT/DESIGN ON STARTSCREEN!

    startscreen();

    return EXIT_SUCCESS;
}

void startscreen() {

    InitWindow(WIDTH, HEIGHT, "PacMan");
    SetTargetFPS(60);

    //Theme Music
    InitAudioDevice();
    Music startmusic = LoadMusicStream("../assets/theme.mp3");
    PlayMusicStream(startmusic);

    while (!WindowShouldClose()) {
        BeginDrawing();
        UpdateMusicStream(startmusic);   // Update music buffer with new stream data


        //PACMAN TEXT
        ClearBackground(BLACK);
        DrawText("PACMAN", 240, 150, 100, RED);
        DrawText("PACMAN", 235, 155, 100, YELLOW);

        //PACMAN FIGURE
        Vector2 position = {450, 400};
        DrawCircleSector(position, 100, 125, 415, 1, YELLOW);
        DrawCircle(470, 340, 15, BLACK);

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
