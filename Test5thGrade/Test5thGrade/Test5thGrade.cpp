#include "Test5thGrade.h"

// Check if the mouse is hovering over a button
bool IsMouseOverButton(Rectangle button) {
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, button);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 550;

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Test 5th grade");

    // Load the background image
    Texture2D background = LoadTexture("C:/Users/wweewe/sprint-math-games-9th-grade-pixelstorm/assets/tests.png");

    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }

    SetTargetFPS(60);

    // Questions and answers
    Question questions[] = {
        {"A triangle's angles add up to ___ degrees.", "180"},
        {"The boundary of a circle is called the ___?", "circumference"},
        {"What is the formula for S of a rhombus?", "S=a*a"}
    };

    int currentQuestion = 0;
    int questionCount = sizeof(questions) / sizeof(questions[0]);
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
                        gameFinished = true; // End game
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
            // Check if the "Next" button is clicked
            Rectangle nextButton = { 300, 400, 200, 50 };
            if (IsMouseOverButton(nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Reset the game
                gameFinished = false;
                currentQuestion = 0;
                message = nullptr;
                userAnswer[0] = '\0';
                answerIndex = 0;
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background image
        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);
        }

        if (!gameFinished) {
            // Center the question text
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);

            // Draw the user's input and feedback
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);
        }
        else {
            // Draw congratulatory message
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            // Draw "Next" button
            Rectangle nextButton = { 300, 400, 200, 50 };
            DrawRectangleRec(nextButton, LIGHTGRAY);
            DrawText("NEXT", 350, 415, 25, BLACK);

            // Highlight button on hover
            if (IsMouseOverButton(nextButton)) {
                DrawRectangleLinesEx(nextButton, 2, RED);
            }
            else {
                DrawRectangleLinesEx(nextButton, 2, BLACK);
            }
        }

        // Draw the feedback message
        if (message) {
            int messageWidth = MeasureText(message, 25);
            DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, WHITE);
        }

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(background);
    CloseWindow();
}
