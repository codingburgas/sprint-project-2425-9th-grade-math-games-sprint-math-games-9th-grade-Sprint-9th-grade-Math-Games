#include "testsMenu.h"
#include "menu.h"
#include "rules.h"
// Function to check if the mouse is over a button
bool isMouseOverButton(Button button) {
    // Get the current mouse position and check if it is inside the button's bounds
    return CheckCollisionPointRec(GetMousePosition(), button.bounds);
}

// Function to update the button state based on mouse hover and click
bool updateButtonTests(ButtonTests& button) {
    // If the mouse is over the button, change the button's color to the hover color
    if (isMouseOverButton(button)) {
        button.currentColor = button.hoverColor;
        // Return true if the left mouse button is pressed while hovering over the button
        return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }
    // If the mouse is not over the button, return to the normal color
    button.currentColor = button.normalColor;
    return false;  // Return false as no click has been detected
}

// Function to draw a button on the screen
void drawButtonTests(ButtonTests button) {
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


void drawMenuTests() {
    // Initialize the window with the specified screen width, height, and title
    InitWindow(800, 550, "Menu");

    // Load the background image for the menu from the specified path
    Texture2D background = LoadTexture("C:/Users/ewewwewe/sprint-math-games-9th-grade-pixelstorm/assets/1.png");

    // Check if the background image loaded successfully, otherwise exit the program
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_ERROR, "Failed");
        return;  // Exit the program if the image loading failed
    }

    // Define the buttons for the menu (Play, Rules, and Exit) with their properties
   ButtonTests buttons[3] = {
        { {350, 300, 400, 50}, "5 grade", DARKBLUE, BLUE, DARKBLUE },
        { {350, 380, 400, 50}, "6 grade", DARKBLUE, BLUE, DARKBLUE },
        { {350, 460, 400, 50}, "7 grade", DARKBLUE, BLUE, DARKBLUE }
    };


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
        if (updateButtonTests(buttons[0])) {
            fifthGrade();
        }
        if (updateButtonTests(buttons[1])) {

            sixthGrade();
        }
        if (updateButtonTests(buttons[2])) {
            seventhGrade();  // Exit the program when the "Exit" button is clicked
        }

        // Loop through each button and draw it on the screen
        for (int i = 0; i < 3; i++) {
            drawButtonTests(buttons[i]);
        }

        // End drawing for this frame
        EndDrawing();
    }

    // Unload the background texture to free up memory when done
    UnloadTexture(background);

    // Close the window and exit the program
    CloseWindow();
}


