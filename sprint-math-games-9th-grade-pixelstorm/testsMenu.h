#pragma once
#include "raylib.h"
// Screen dimensions

// Button structure with hover effect
struct ButtonTests {
    Rectangle bounds;      // Button's rectangular area
    const char* text;      // Button label text
    Color normalColor;     // Default button color
    Color hoverColor;      // Color when hovered
    Color currentColor;    // Current color based on state
};

// Function declarations
bool isMouseOverButton(ButtonTests button); // Check if mouse is over a button
bool updateButtonTests(ButtonTests& button);
void drawButtonTests(ButtonTests button);        // Draw a button
void drawMenuTests();
void fifthGrade();
void sixthGrade();

