#include "raylib.h"
#include "testsMenu.h"
#include "tests.h"

void drawMenuTests(TestScreen& currentScreen) {
    Texture2D testsMenu = LoadTexture("../../assets/testsMenu.png");
    
    const int screenWidth = 800;
    const int screenHeight = 550;

    Rectangle fifthGradeButton = { screenWidth / 2 - 100, 150, 400, 50 };
    Rectangle sixthGradeButton = { screenWidth / 2 - 100, 250, 400, 50 };
    Rectangle seventhGradeButton = { screenWidth / 2 - 100, 350, 400, 50 };

    while (!WindowShouldClose() && currentScreen == TESTS_MENU) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePoint = GetMousePosition();
            if (CheckCollisionPointRec(mousePoint, fifthGradeButton)) {
                currentScreen = FIFTH_GRADE_TEST;
            }
            if (CheckCollisionPointRec(mousePoint, sixthGradeButton)) {
                currentScreen = SIXTH_GRADE_TEST;
            }
            if (CheckCollisionPointRec(mousePoint, seventhGradeButton)) {
                currentScreen = SEVENTH_GRADE_TEST;
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(testsMenu, 0, 0, WHITE);


        DrawRectangleRec(fifthGradeButton, LIGHTGRAY);
        DrawRectangleLinesEx(fifthGradeButton, 2, BLACK);
        DrawText("5th Grade", fifthGradeButton.x + 25, fifthGradeButton.y + 10, 30, BLACK);

        DrawRectangleRec(sixthGradeButton, LIGHTGRAY);
        DrawRectangleLinesEx(sixthGradeButton, 2, BLACK);
        DrawText("6th Grade", sixthGradeButton.x + 25, sixthGradeButton.y + 10, 30, BLACK);

        DrawRectangleRec(seventhGradeButton, LIGHTGRAY);
        DrawRectangleLinesEx(seventhGradeButton, 2, BLACK);
        DrawText("7th Grade", seventhGradeButton.x + 25, seventhGradeButton.y + 10, 30, BLACK);

        EndDrawing();
    }
}
