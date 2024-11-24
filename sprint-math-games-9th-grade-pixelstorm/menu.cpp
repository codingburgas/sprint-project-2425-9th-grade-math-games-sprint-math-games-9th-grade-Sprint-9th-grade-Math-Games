#include "menu.h"

Menu::~Menu() {
    UnloadTexture(background);
}

Menu::Menu() {
    background = LoadTexture("../../assets/menu.png");
    // Define buttons (you can adjust positions and sizes)
    buttons[0] = Button({ 350, 300, 400, 50 }, "Play");
    buttons[1] = Button({ 350, 380, 400, 50 }, "Rules");
    buttons[2] = Button({ 350, 460, 400, 50 }, "Exit");
}

void Menu::drawMenu(TestScreen& currentScreen) {
    DrawTexture(background, 0, 0, WHITE);

    if (buttons[0].update()) {
        currentScreen = TESTS_MENU; // Switch to tests menu
    }
    if (buttons[1].update()) {
        rules(); // Show rules screen
    }
    if (buttons[2].update()) {
        exit(0); // Exit the program
    }

    for (int i = 0; i < 3; i++) {
        buttons[i].draw();
    }
}
