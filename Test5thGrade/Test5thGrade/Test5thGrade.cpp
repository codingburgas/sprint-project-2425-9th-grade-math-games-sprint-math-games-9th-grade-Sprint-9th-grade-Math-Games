#include "raylib.h"
#include <cstring>

// Question structure: Holds a question and its correct answer.
struct Question {
    const char* text;    // The question text
    const char* answer;  // The correct answer
};

int main() {
    // Initialize the game window
    InitWindow(800, 550, "Math Game");
    SetTargetFPS(60); // Set the frame rate

    // Define questions and answers
    Question questions[] = {
        {"What is 2 + 2?", "4"},
        {"What is 5 - 3?", "2"},
        {"What is 3 + 3?", "6"},
        {"What is 10 - 7?", "3"}
    };
    int questionCount = sizeof(questions) / sizeof(questions[0]);
    int currentQuestion = 0; // Start with the first question

    char userAnswer[64] = ""; // Store the user's input
    int answerIndex = 0;      // Current typing position
    const char* message = nullptr; // Message for feedback

    // Main game loop
    while (!WindowShouldClose()) {
        // Handle user typing input
        int key = GetCharPressed();
        while (key > 0) {
            if (key >= 32 && key <= 125 && answerIndex < 63) { // Valid characters
                userAnswer[answerIndex++] = (char)key;
                userAnswer[answerIndex] = '\0'; // Null-terminate string
            }
            key = GetCharPressed();
        }

        // Handle Enter key to check the answer
        if (IsKeyPressed(KEY_ENTER)) {
            if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {
                // Correct answer
                currentQuestion++;
                if (currentQuestion >= questionCount) {
                    message = "Great job! You've finished the game!";
                }
                else {
                    message = "Correct! Next question.";
                }
                memset(userAnswer, 0, sizeof(userAnswer)); // Clear answer
                answerIndex = 0;
            }
            else {
                // Incorrect answer
                message = "Oops! Try again.";
            }
        }

        // Handle Backspace key to delete the last character
        if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
            userAnswer[--answerIndex] = '\0';
        }

        // Drawing on the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentQuestion < questionCount) {
            // Show the current question and user input
            DrawText(questions[currentQuestion].text, 20, 50, 20, BLACK);
            DrawText("Your answer: ", 20, 100, 20, DARKBLUE);
            DrawText(userAnswer, 150, 100, 20, DARKGREEN);
        }
        else {
            // Game over message
            DrawText("Congratulations! You've answered all the questions!", 20, 50, 20, DARKGREEN);
        }

        // Show feedback message
        if (message) {
            DrawText(message, 20, 150, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow(); // Close the window
;
}