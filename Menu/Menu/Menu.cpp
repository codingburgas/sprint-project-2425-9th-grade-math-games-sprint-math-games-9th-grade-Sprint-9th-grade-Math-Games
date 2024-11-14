// Menu.cpp
#include "Menu.h"
#include <stdlib.h>
#include <time.h>

// Check if the mouse is over the button
bool IsMouseOverButton(Button button) {
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, button.bounds);
}

// Draw a button with hover effect
void DrawButton(Button button) {
    DrawRectangleRounded(button.bounds, 0.3f, 10, button.currentColor);
    int textWidth = MeasureText(button.text, 20);
    DrawText(button.text, button.bounds.x + (button.bounds.width - textWidth) / 2,
        button.bounds.y + (button.bounds.height - 20) / 2, 20, WHITE);
}

int main() {
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Menu");

    // Load background image from the specified path
    Texture2D background = LoadTexture("C:\\Users\\wweewe\\sprint-math-games-9th-grade-pixelstorm\\assets\\Menu.png");

    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_ERROR, "Failed to load background image!");
        return 1;  // Exit if image failed to load
    }

    // Create buttons with initial settings
    Button playButton = { {350, 300, 400, 50}, "Play", DARKBLUE, BLUE, DARKBLUE };
    Button rulesButton = { {350, 380, 400, 50}, "Rules", DARKBLUE, BLUE, DARKBLUE };
    Button exitButton = { {350, 460, 400, 50}, "Exit", DARKGRAY, GRAY, DARKGRAY };

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update button colors based on mouse hover
        if (IsMouseOverButton(playButton)) {
            playButton.currentColor = playButton.hoverColor;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                TraceLog(LOG_INFO, "Play button clicked!");
            }
        }
        else {
            playButton.currentColor = playButton.normalColor;
        }

        if (IsMouseOverButton(exitButton)) {
            exitButton.currentColor = exitButton.hoverColor;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                break;  // Exit the program when "Exit" is clicked
            }
        }
        else {
            exitButton.currentColor = exitButton.normalColor;
        }

        if (IsMouseOverButton(rulesButton)) {
            rulesButton.currentColor = rulesButton.hoverColor;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                TraceLog(LOG_INFO, "Rules button clicked!");
            }
        }
        else {
            rulesButton.currentColor = rulesButton.normalColor;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw background image
        DrawTexture(background, 0, 0, WHITE);

        // Draw buttons
        DrawButton(playButton);
        DrawButton(rulesButton);
        DrawButton(exitButton);

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(background);
    CloseWindow();
    
}
