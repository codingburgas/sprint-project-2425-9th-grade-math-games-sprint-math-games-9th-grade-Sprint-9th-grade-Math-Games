#pragma once 
#include "raylib.h"
#include "button.h"
#include "rules.h"
#include "testsMenu.h"

class Menu {
public:
    Menu();
    ~Menu();
    void drawMenu(TestScreen& currentScreen);

private:
    Texture2D background;
    Button buttons[3];
};
