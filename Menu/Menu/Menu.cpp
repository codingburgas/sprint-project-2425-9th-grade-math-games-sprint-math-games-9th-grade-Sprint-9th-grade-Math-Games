#include "raylib.h"

int main() {
    // Initialize the Raylib window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Start and Exit Buttons with Background");

    // Load the background image
    Texture2D background = LoadTexture("../.png");  // Replace with your image file

    // Set the button dimensions
    Rectangle startButton = { screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50 };
    Rectangle exitButton = { screenWidth / 2 - 100, screenHeight / 2 + 20, 200, 50 };

    // Define colors for normal and hover states
    Color normalColor = SKYBLUE;
    Color hoverColor = SKYBLUE;

    // Set the FPS
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Check if mouse is over the Start button and if clicked
        bool startButtonHovered = CheckCollisionPointRec(GetMousePosition(), startButton);
        bool exitButtonHovered = CheckCollisionPointRec(GetMousePosition(), exitButton);

        // Start button action
        if (startButtonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Replace with actual game start logic
            TraceLog(LOG_INFO, "Game Started!");
        }

        // Exit button action
        if (exitButtonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            CloseWindow();  // Close the window and exit the game
        }

        // Begin drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background image
        DrawTexture(background, 0, 0, WHITE);

        // Draw the Start button
        DrawRectangleRec(startButton, startButtonHovered ? hoverColor : normalColor);
        DrawText("START", startButton.x + 65, startButton.y + 18, 20, BLACK);

        // Draw the Exit button
        DrawRectangleRec(exitButton, exitButtonHovered ? hoverColor : normalColor);
        DrawText("EXIT", exitButton.x + 75, exitButton.y + 15, 20, BLACK);

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(background);  // Unload the background texture
    CloseWindow();

    
}
