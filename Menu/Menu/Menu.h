#pragma once
#include "raylib.h"

// Screen dimensions
constexpr int screenWidth = 800;
constexpr int screenHeight = 550;

// Button structure with hover effect
struct Button {
    Rectangle bounds;      // Button's rectangular area
    const char* text;      // Button label text
    Color normalColor;     // Default button color
    Color hoverColor;      // Color when hovered
    Color currentColor;    // Current color based on state
};

// Function declarations
bool IsMouseOverButton(Button button); // Check if mouse is over a button
void DrawButton(Button button);        // Draw a button
