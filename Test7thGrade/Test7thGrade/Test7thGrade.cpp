#include "Test7thGrade.h" // Include the custom header file with the necessary definitions and imports

// Function to check if the mouse is hovering over a specified rectangular button
bool IsMouseOverButton(Rectangle button) {
    Vector2 mousePosition = GetMousePosition(); // Get the current mouse position
    return CheckCollisionPointRec(mousePosition, button); // Check if the mouse is within the rectangle
}

int main() {
    // Define the dimensions of the game window
    const int screenWidth = 800;
    const int screenHeight = 550;

    // Initialize the game window with a title
    InitWindow(screenWidth, screenHeight, "Test 7th grade");

    // Load the background texture from a file
    Texture2D background = LoadTexture("C://Users//ewewwewe//sprint-math-games-9th-grade-pixelstorm//assets//tests.png");

    // Check if the background image failed to load and log a warning if it did
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }

    // Set the game to run at 60 frames per second
    SetTargetFPS(60);

    // Array of questions for the quiz along with their correct answers
    Question questions[] = {
        {"The value of the expression 1/2 + 1/3 is equal to:", "5/6"},
        {"The sum of 50% of 100 and 50% of 50 is equal to:", "100% of 75"},
        {"The smallest integer less than -5.5 is:", "-6"}
    };

    // Initialize variables for game state
    int currentQuestion = 0; // Index to track the current question
    int questionCount = sizeof(questions) / sizeof(questions[0]); // Total number of questions
    char userAnswer[64] = ""; // Buffer to store the user's answer
    int answerIndex = 0; // Index to track the position in the answer buffer
    const char* message = nullptr; // Message to display to the user (feedback)

    bool gameFinished = false; // Flag to check if the game has been completed

    // Main game loop (runs until the user closes the window)
    while (!WindowShouldClose()) {
        if (!gameFinished) {
            // Handle user input for typing answers
            int key = GetCharPressed(); // Get the next pressed character
            while (key > 0) {
                // Check if the key is a valid character and the buffer isn't full
                if (key >= 32 && key <= 125 && answerIndex < 63) {
                    userAnswer[answerIndex++] = (char)key; // Add the character to the buffer
                    userAnswer[answerIndex] = '\0'; // Null-terminate the string
                }
                key = GetCharPressed(); // Check for the next key
            }

            // Handle the Backspace key to remove the last character
            if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
                userAnswer[--answerIndex] = '\0'; // Decrease the buffer index and null-terminate
            }

            // Handle the Enter key to check the user's answer
            if (IsKeyPressed(KEY_ENTER)) {
                // Check if the answer matches the correct answer
                if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {
                    currentQuestion++; // Move to the next question
                    if (currentQuestion < questionCount) {
                        message = "Correct! Next question."; // Positive feedback
                    }
                    else {
                        // If all questions are answered, end the game
                        gameFinished = true;
                        message = "Congratulations! You've completed the game!";
                    }
                    // Reset the answer buffer for the next question
                    answerIndex = 0;
                    userAnswer[0] = '\0';
                }
                else {
                    message = "Incorrect. Try again."; // Feedback for an incorrect answer
                }
            }
        }
        else {
            // Handle buttons on the "game finished" screen
            Rectangle retryButton = { 200, 400, 150, 50 }; // Define the Retry button
            Rectangle menuButton = { 450, 400, 150, 50 };  // Define the Menu button

            // Check if the Retry button is clicked
            if (IsMouseOverButton(retryButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                gameFinished = false; // Reset the game state
                currentQuestion = 0; // Start from the first question
                message = nullptr;   // Clear the message
                userAnswer[0] = '\0'; // Clear the answer buffer
                answerIndex = 0;
            }

            // Check if the Menu button is clicked (exit the game)
            if (IsMouseOverButton(menuButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow(); // Close the window and terminate the program
                return 0;
            }
        }

        // Begin rendering the game frame
        BeginDrawing();
        ClearBackground(RAYWHITE); // Clear the screen with a white background

        // Draw the background image if it loaded successfully
        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);
        }

        if (!gameFinished) {
            // Display the current question text
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30); // Measure the text width for centering
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);

            // Display the answer input prompt and user's current input
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);
        }
        else {
            // Display the completion message
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            // Draw the Retry button
            Rectangle retryButton = { 200, 400, 150, 50 };
            DrawRectangleRec(retryButton, LIGHTGRAY); // Draw button background
            DrawText("Retry", 230, 415, 25, BLACK);   // Draw button label

            // Highlight the Retry button if the mouse is over it
            if (IsMouseOverButton(retryButton)) {
                DrawRectangleLinesEx(retryButton, 2, RED); // Highlight in red
            }
            else {
                DrawRectangleLinesEx(retryButton, 2, BLACK); // Default border
            }

            // Draw the Menu button
            Rectangle menuButton = { 450, 400, 150, 50 };
            DrawRectangleRec(menuButton, LIGHTGRAY); // Draw button background
            DrawText("Menu", 480, 415, 25, BLACK);   // Draw button label

            // Highlight the Menu button if the mouse is over it
            if (IsMouseOverButton(menuButton)) {
                DrawRectangleLinesEx(menuButton, 2, RED); // Highlight in red
            }
            else {
                DrawRectangleLinesEx(menuButton, 2, BLACK); // Default border
            }
        }

        // Display feedback messages (e.g., Correct/Incorrect)
        if (message) {
            int messageWidth = MeasureText(message, 25);
            DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, WHITE);
        }

        EndDrawing(); // End the drawing for this frame
    }

    // Clean up resources when the game ends
    UnloadTexture(background); // Free the background texture
    CloseWindow();             // Close the game window
}
