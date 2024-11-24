#include "raylib.h"
#include "rules.h"

void rules() {
    // Placeholder implementation for the rules screen
    while (!WindowShouldClose()) {
        Texture2D Rules = LoadTexture("../../assets/rules.png");

        const int screenWidth = 800;
        const int screenHeight = 550;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(Rules, 0, 0, WHITE);

        if (IsKeyPressed(KEY_ESCAPE)) break;

        EndDrawing();
    }
}
