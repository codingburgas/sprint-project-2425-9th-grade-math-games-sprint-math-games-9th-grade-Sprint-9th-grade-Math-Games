#include "Test7thGrade.h"

bool IsMouseOverButton(Rectangle button) {
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, button);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 550;

    InitWindow(screenWidth, screenHeight, "Test 7th grade");

    Texture2D background = LoadTexture("C://Users//ewewwewe//sprint-math-games-9th-grade-pixelstorm//assets//tests.png");

    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }

    SetTargetFPS(60);

    Question questions[] = {
        {"The value of the expression 1/2 + 1/3 is equal to:", "5/6"},
        {"The sum of 50% of 100 and 50% of 50 is equal to:", "100% of 75"},
        {"The smallest integer less than -5.5 is:", "-6"}
    };

    int currentQuestion = 0;
    int questionCount = sizeof(questions) / sizeof(questions[0]);
    char userAnswer[64] = "";
    int answerIndex = 0;
    const char* message = nullptr;

    bool gameFinished = false;

    while (!WindowShouldClose()) {
        if (!gameFinished) {
            int key = GetCharPressed();
            while (key > 0) {
                if (key >= 32 && key <= 125 && answerIndex < 63) {
                    userAnswer[answerIndex++] = (char)key;
                    userAnswer[answerIndex] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
                userAnswer[--answerIndex] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER)) {
                if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {
                    currentQuestion++;
                    if (currentQuestion < questionCount) {
                        message = "Correct! Next question.";
                    }
                    else {
                        gameFinished = true;
                        message = "Congratulations! You've completed the game!";
                    }
                    answerIndex = 0;
                    userAnswer[0] = '\0';
                }
                else {
                    message = "Incorrect. Try again.";
                }
            }
        }
        else {
            Rectangle retryButton = { 200, 400, 150, 50 };
            Rectangle menuButton = { 450, 400, 150, 50 };

            if (IsMouseOverButton(retryButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                gameFinished = false;
                currentQuestion = 0;
                message = nullptr;
                userAnswer[0] = '\0';
                answerIndex = 0;
            }

            if (IsMouseOverButton(menuButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);
        }

        if (!gameFinished) {
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);
        }
        else {
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            Rectangle retryButton = { 200, 400, 150, 50 };
            Rectangle menuButton = { 450, 400, 150, 50 };

            DrawRectangleRec(retryButton, LIGHTGRAY);
            DrawText("Retry", 230, 415, 25, BLACK);

            if (IsMouseOverButton(retryButton)) {
                DrawRectangleLinesEx(retryButton, 2, RED);
            }
            else {
                DrawRectangleLinesEx(retryButton, 2, BLACK);
            }

            DrawRectangleRec(menuButton, LIGHTGRAY);
            DrawText("Menu", 480, 415, 25, BLACK);

            if (IsMouseOverButton(menuButton)) {
                DrawRectangleLinesEx(menuButton, 2, RED);
            }
            else {
                DrawRectangleLinesEx(menuButton, 2, BLACK);
            }
        }

        if (message) {
            int messageWidth = MeasureText(message, 25);
            DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, WHITE);
        }

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
}
