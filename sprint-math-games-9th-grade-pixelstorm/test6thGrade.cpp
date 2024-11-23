#include "test6thGrade.h"
#include "menu.h"
// Check if the mouse is hovering over a button
bool isMouseOverButton(Button button) {
    Vector2 mousePosition = GetMousePosition();  // Get mouse position
    return CheckCollisionPointRec(GetMousePosition(), button.bounds); // Check if mouse is over the button
}

void sixthGrade() {
    const int screenWidth = 800;   // Game window width
    const int screenHeight = 550;  // Game window height

    // Initialize the game window with a title
    InitWindow(screenWidth, screenHeight, "Test 5th Grade");

    // Load the background image
    Texture2D background = LoadTexture("C://Users//ewewwewe//sprint-math-games-9th-grade-pixelstorm//assets//tests.png");

    // Warn if the background image couldn't be loaded
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }



    // Define the game questions and answers
    Question questions[7] = {
        {"A triangle's angles add up to ___ degrees.", "180"},
        {"The boundary of a circle is called the ___?", "circumference"},
        {"What is the formula for S of a rhombus?", "S=a*a"},
        {"Convert 0.5 to a fraction.", "1/2"},
        {"How many degrees are in a full circle?", "360"},
        {"What is 3/5 of 25?", "15"},
        {"What is 5/8 + 3/8?", "1"},
    };

    int currentQuestion = 0;  // Index of the current question
    int questionCount = sizeof(questions) / sizeof(questions[0]);  // Total number of questions
    char userAnswer[64] = "";  // Store the user's answer
    int answerIndex = 0;  // Track the position in the answer
    const char* message = nullptr;  // Feedback message for the user

    bool gameFinished = false;  // Flag to track if the game is over

    // Game loop
    while (!WindowShouldClose()) {
        // Handle user input
        if (!gameFinished) {
            int key = GetCharPressed();  // Check for keyboard input
            while (key > 0) {  // Process all keypresses
                if (key >= 32 && key <= 125 && answerIndex < 63) {  // Allow printable characters
                    userAnswer[answerIndex++] = (char)key;  // Add the character to the answer
                    userAnswer[answerIndex] = '\0';  // Null-terminate the string
                }
                key = GetCharPressed();  // Get the next keypress
            }

            // Handle backspace to delete characters
            if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
                userAnswer[--answerIndex] = '\0';  // Remove the last character
            }

            // Check if the user presses Enter to submit their answer
            if (IsKeyPressed(KEY_ENTER)) {
                if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {  // Check if the answer is correct
                    currentQuestion++;  // Move to the next question
                    if (currentQuestion < questionCount) {
                        message = "Correct! Next question.";
                    }
                    else {
                        gameFinished = true;  // End the game if all questions are answered
                        message = "Congratulations! You've completed the game!";
                    }
                    answerIndex = 0;  // Reset the answer input
                    userAnswer[0] = '\0';
                }
                else {
                    message = "Incorrect. Try again.";  // Feedback for wrong answers
                }
            }
        }
        else {
            // Handle the "Next" button after completing the game
            Rectangle nextButton = { 300, 400, 200, 50 };  // Define button size and position
            if (isMouseOverButton(nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Reset the game
                gameFinished = false;
                currentQuestion = 0;
                message = nullptr;
                userAnswer[0] = '\0';
                answerIndex = 0;
            }
        }

        // Draw the game screen
        BeginDrawing();
        ClearBackground(RAYWHITE);  // Set the background color

        // Draw the background image if it loaded successfully
        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);
        }

        if (!gameFinished) {
            // Show the current question centered on the screen
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);  // Measure text width
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);

            // Show the user's answer input
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);
        }
        else {
            // Show a congratulatory message
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            // Draw the "Next" button
            Rectangle nextButton = { 300, 400, 200, 50 };
            DrawRectangleRec(nextButton, LIGHTGRAY);  // Button background
            DrawText("NEXT", 350, 415, 25, BLACK);  // Button text

            // Highlight button if hovered
            if (isMouseOverButton(nextButton)) {
                DrawRectangleLinesEx(nextButton, 2, RED);
            }
            else {
                DrawRectangleLinesEx(nextButton, 2, BLACK);
            }
        }

        // Show feedback message (e.g., Correct, Incorrect)
        if (message) {
            int messageWidth = MeasureText(message, 25);
            DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, WHITE);
        }

        EndDrawing();  // Finish the frame
    }

    // Clean up resources
    UnloadTexture(background);  // Free the background texture
    CloseWindow();  // Close the game window
}
