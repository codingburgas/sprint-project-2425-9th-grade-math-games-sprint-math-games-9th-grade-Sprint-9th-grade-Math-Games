#include "button.h"

Button::Button() {}

Button::Button(Rectangle rect, const char* label) : rect(rect), label(label) {}

void Button::draw() {
    DrawRectangleRec(rect, LIGHTGRAY);
    DrawRectangleLinesEx(rect, 2, BLACK);
    DrawText(label.c_str(), rect.x + 10, rect.y + 10, 20, BLACK);
}

bool Button::update() {
    if (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return true;
    }
    return false;
}
