#pragma once
#include "raylib.h"
#include <cstdlib>
// Screen dimensions

// Button structure with hover effect
struct Button {
    Rectangle bounds;      // Button's rectangular area
    const char* text;      // Button label text
    Color normalColor;     // Default button color
    Color hoverColor;      // Color when hovered
    Color currentColor;    // Current color based on state
};

// Function declarations
bool isMouseOverButton(Button button); // Check if mouse is over a button
bool updateButton(Button& button);
void drawButton(Button button);        // Draw a button
void drawMenu();
