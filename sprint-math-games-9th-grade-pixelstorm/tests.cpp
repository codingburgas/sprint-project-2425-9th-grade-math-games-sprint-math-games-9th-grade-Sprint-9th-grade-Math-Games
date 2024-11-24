#include "tests.h"
#include "raylib.h"
#include <cstring> // For strcmp

void test(Question* questions, int questionCount, int grade) {
    Texture2D testBackground = LoadTexture("../../assets/tests.png");
    
    const int screenWidth = 800;
    const int screenHeight = 550;

    int currentQuestion = 0;
    char userAnswer[64] = "";
    int answerIndex = 0;
    const char* message = nullptr;
    bool gameFinished = false;

    while (!WindowShouldClose()) {
        // Input handling
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
                        gameFinished = true; // End game after the last question
                        message = "Congratulations! You've completed all questions!";
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
            // Check for ESC to return to the menu
            if (IsKeyPressed(KEY_Q)) break;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(testBackground, 0, 0, WHITE);

        if (!gameFinished) {
            // Draw the current question
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, WHITE);

            // Draw the user's input
            DrawText("Your answer:", 200, 200, 30, WHITE);
            DrawText(userAnswer, 400, 200, 30, WHITE);

            // Draw feedback message
            if (message) {
                int messageWidth = MeasureText(message, 25);
                DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, DARKGREEN);
            }
        }
        else {
            // Draw completion message
            const char* completeText = TextFormat("You have finished the %dth-grade test!", grade);
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, WHITE);
            DrawText("Press [Q] to go back to the menu", 200, 300, 20, GRAY);
        }

        EndDrawing();
    }
}
