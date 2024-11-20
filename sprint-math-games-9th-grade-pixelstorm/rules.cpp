#include "rules.h"
#include "menu.h"
// Function to check if the mouse is over the button
bool isMouseOverButton(Rectangle buttonBounds) {
    return CheckCollisionPointRec(GetMousePosition(), buttonBounds);  // Returns true if mouse is over button
}

void rules() {

    // Initialize window with screen size
    InitWindow( 800, 550, "Rules");

    // Load background image
    //Texture2D background = LoadTexture("C:\\Users\\wweewe\\sprint-math-games-9th-grade-pixelstorm\\assets\\rules.png");
    Texture2D background = LoadTexture("assets/tests.png");
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_ERROR, "Failed");  // Log error if the image is not loaded
        return;  // Exit if the image is not found
    }

    // Define button position, size, and colors
    Rectangle buttonBounds = { (float)(800 - 750), 450, 130, 50 };
    const char* buttonText = "Menu";
    Color buttonColor = DARKBROWN;
    Color hoverColor = DARKBROWN;

    // Main game loop
    while (!WindowShouldClose()) {
        // Check if the mouse is hovering over the button
        bool isHovered = isMouseOverButton(buttonBounds);
        if (isHovered) buttonColor = hoverColor;  // Change color when hovered
        else buttonColor = BEIGE;  // Set normal color when not hovered

        // If button is clicked, log the message
        if (isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            TraceLog(LOG_INFO, "Menu Button Clicked");
            drawMenu();
        }

        // Begin drawing everything on screen
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);  // Draw the background image

        // Draw the button as a rounded rectangle
        DrawRectangleRounded(buttonBounds, 0.3f, 10, buttonColor);

        // Calculate text position to center it on the button
        int textWidth = MeasureText(buttonText, 20);
        int xPos = buttonBounds.x + (buttonBounds.width - textWidth) / 2;
        int yPos = buttonBounds.y + (buttonBounds.height - 20) / 2;
        DrawText(buttonText, xPos, yPos, 20, WHITE);  // Draw the button text

        EndDrawing();  // End the drawing for this frame
    }

    // Clean up resources
    UnloadTexture(background);  // Unload the background image
    CloseWindow();  // Close the window and OpenGL context

}
