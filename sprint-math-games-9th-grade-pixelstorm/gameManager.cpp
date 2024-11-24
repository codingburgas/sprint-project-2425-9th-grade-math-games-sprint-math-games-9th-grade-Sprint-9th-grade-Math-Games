#include "gameManager.h"


GameManager::GameManager()
{
    // Initialize window and settings
    InitWindow(800, 550, "PixelStorm");
    SetTargetFPS(60);
}

void GameManager::drawMainLoop()
{
    Menu menu;
    TestScreen currentScreen = MENU; // Start at the main menu

    // Main game loop
    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case MENU:
            BeginDrawing();
            ClearBackground(RAYWHITE);
            menu.drawMenu(currentScreen); // Pass the current screen by reference
            EndDrawing();
            break;

        case TESTS_MENU:
            drawMenuTests(currentScreen); // Show the tests menu
            break;

        case FIFTH_GRADE_TEST:
            test(questions5thGrade, 3, 5); // Call 5th-grade test
            currentScreen = TESTS_MENU; // Return to the tests menu after completion
            break;

        case SIXTH_GRADE_TEST:
            test(questions6thGrade, 3, 6); // Call 6th-grade test
            currentScreen = TESTS_MENU; // Return to the tests menu after completion
            break;

        case SEVENTH_GRADE_TEST:
            test(questions7thGrade, 3, 7); // Call 6th-grade test
            currentScreen = TESTS_MENU; // Return to the tests menu after completion
            break;
        }
    }
}

GameManager::~GameManager()
{
    CloseWindow(); // De-initialize and close window
}