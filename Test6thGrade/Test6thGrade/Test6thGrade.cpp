#include "Test6thGrade.h"

// Function to check if the mouse is hovering over a button
bool IsMouseOverButton(Rectangle button) {
    Vector2 mousePosition = GetMousePosition();  // Get mouse position
    return CheckCollisionPointRec(mousePosition, button);  // Check if mouse is inside the button rectangle
}

int main() {
    const int screenWidth = 800;  // Screen width
    const int screenHeight = 550; // Screen height

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Test 5th grade");

    // Load background image
    Texture2D background = LoadTexture("C:/Users/wweewe/sprint-math-games-9th-grade-pixelstorm/assets/tests.png");

    // If the image fails to load, print a warning
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }

    SetTargetFPS(60);  // Set the frame rate to 60 FPS

    // Define questions and answers
    Question questions[] = {
        {"what number is -1?", "a rational number"},
        {"What is the longest side of a right triangle called?", "hypotenuse"},
        {"What is the line twice the radius in a circle called?", "diameter"},
    };

    int currentQuestion = 0;  // Start with the first question
    int questionCount = sizeof(questions) / sizeof(questions[0]);  // Total number of questions
    char userAnswer[64] = "";  // Store user answer
    int answerIndex = 0;  // Current position in the answer
    const char* message = nullptr;  // Message for feedback

    bool gameFinished = false;  // Flag to check if the game is finished

    // Main game loop
    while (!WindowShouldClose()) {
        // Input handling (typing)
        if (!gameFinished) {
            int key = GetCharPressed();
            while (key > 0) {
                // If the key is valid, add it to the answer
                if (key >= 32 && key <= 125 && answerIndex < 63) {
                    userAnswer[answerIndex++] = (char)key;
                    userAnswer[answerIndex] = '\0';  // Null-terminate the string
                }
                key = GetCharPressed();
            }

            // Handle backspace (delete last character)
            if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
                userAnswer[--answerIndex] = '\0';
            }

            // Check if Enter key is pressed (submit answer)
            if (IsKeyPressed(KEY_ENTER)) {
                // Check if the answer is correct
                if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {
                    currentQuestion++;  // Go to the next question
                    if (currentQuestion < questionCount) {
                        message = "Correct! Next question.";  // Show correct feedback
                    }
                    else {
                        gameFinished = true;  // End game if all questions are answered
                        message = "Congratulations! You've completed the game!";
                    }
                    answerIndex = 0;  // Reset answer input
                    userAnswer[0] = '\0';  // Clear the answer
                }
                else {
                    message = "Incorrect. Try again.";  // Show incorrect feedback
                }
            }
        }
        else {
            // Handle the "Next" button click to restart the game
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

        // Start drawing the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background image if loaded
        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);
        }

        // If the game is not finished, show the question and user input
        if (!gameFinished) {
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);  // Measure the width of the question text
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);  // Draw the question

            // Draw the user's input
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);
        }
        else {
            // If game is finished, show the congratulatory message
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            // Draw the "Next" button
            Rectangle nextButton = { 300, 400, 200, 50 };
            DrawRectangleRec(nextButton, LIGHTGRAY);
            DrawText("NEXT", 350, 415, 25, BLACK);

            // Highlight the button on hover
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

        EndDrawing();  // End drawing
    }

    // Clean up resources
    UnloadTexture(background);
    CloseWindow();  // Close the window
}
