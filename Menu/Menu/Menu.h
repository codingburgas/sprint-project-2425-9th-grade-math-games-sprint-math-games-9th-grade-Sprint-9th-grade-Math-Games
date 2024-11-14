// Menu.h
#ifndef MENU_H
#define MENU_H

#include "raylib.h"

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 550

// Structure for a button with hover effect
struct Button {
    Rectangle bounds;
    const char* text;
    Color normalColor;
    Color hoverColor;
    Color currentColor;
};

// Function declarations
bool IsMouseOverButton(Button button);
void DrawButton(Button button);

#endif // MENU_H
