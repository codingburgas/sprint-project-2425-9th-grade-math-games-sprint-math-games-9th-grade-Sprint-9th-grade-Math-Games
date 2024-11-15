#include "Menu.h"

// Function to check if the mouse is over a button
bool IsMouseOverButton(Button button) {
    // Get the current mouse position and check if it is inside the button's bounds
    return CheckCollisionPointRec(GetMousePosition(), button.bounds);
}

// Function to update the button state based on mouse hover and click
bool UpdateButton(Button& button) {
    // If the mouse is over the button, change the button's color to the hover color
    if (IsMouseOverButton(button)) {
        button.currentColor = button.hoverColor;
        // Return true if the left mouse button is pressed while hovering over the button
        return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }
    // If the mouse is not over the button, return to the normal color
    button.currentColor = button.normalColor;
    return false;  // Return false as no click has been detected
}

// Function to draw a button on the screen
void DrawButton(Button button) {
    // Draw the button as a rounded rectangle with the current color
    DrawRectangleRounded(button.bounds, 0.3f, 10, button.currentColor);

    // Measure the width of the text to center it on the button
    int textWidth = MeasureText(button.text, 20);

    // Calculate the x and y positions to center the text within the button
    int xPos = button.bounds.x + (button.bounds.width - textWidth) / 2;
    int yPos = button.bounds.y + (button.bounds.height - 20) / 2;

    // Draw the text in the center of the button with a font size of 20 and color WHITE
    DrawText(button.text, xPos, yPos, 20, WHITE);
}

int main() {
    // Initialize the window with the specified screen width, height, and title
    InitWindow(screenWidth, screenHeight, "Menu");

    // Load the background image for the menu from the specified path
    Texture2D background = LoadTexture("C:\\Users\\wweewe\\sprint-math-games-9th-grade-pixelstorm\\assets\\Menu.png");

    // Check if the background image loaded successfully, otherwise exit the program
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_ERROR, "Failed");  // Log the error
        return 1;  // Exit the program if the image loading failed
    }

    // Define the buttons for the menu (Play, Rules, and Exit) with their properties
    Button buttons[] = {
        { {350, 300, 400, 50}, "Play", DARKBLUE, BLUE, DARKBLUE },
        { {350, 380, 400, 50}, "Rules", DARKBLUE, BLUE, DARKBLUE },
        { {350, 460, 400, 50}, "Exit", DARKGRAY, GRAY, DARKGRAY }
    };

    // Set the frame rate to 60 frames per second
    SetTargetFPS(60);

    // Start the main game loop which continues until the user closes the window
    while (!WindowShouldClose()) {
        // Start drawing to the screen
        BeginDrawing();

        // Clear the screen with a white background
        ClearBackground(RAYWHITE);

        // Draw the background image on the screen at position (0, 0)
        DrawTexture(background, 0, 0, WHITE);

        // Check if any of the buttons are clicked
        // If a button is clicked, handle it here 
        if (UpdateButton(buttons[0])) {
            // Handle the "Play" button click 
        }
        if (UpdateButton(buttons[1])) {
            // Handle the "Rules" button click 
        }
        if (UpdateButton(buttons[2])) {
            break;  // Exit the program when the "Exit" button is clicked
        }

        // Loop through each button and draw it on the screen
        for (int i = 0; i < 3; i++) {
            DrawButton(buttons[i]);
        }

        // End drawing for this frame
        EndDrawing();
    }

    // Unload the background texture to free up memory when done
    UnloadTexture(background);

    // Close the window and exit the program
    CloseWindow();
}
