#pragma once

#include "raylib.h"
#include <string>

class Button {
public:
    Button();
    Button(Rectangle rect, const char* label);
    void draw();
    bool update();

private:
    Rectangle rect;
    std::string label;
};