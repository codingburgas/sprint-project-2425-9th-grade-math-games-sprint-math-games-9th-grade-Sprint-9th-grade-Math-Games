#include "Test5thGrade.h" 

// Function to check if the mouse is hovering over a button
bool IsMouseOverButton(Rectangle button) {
    Vector2 mousePosition = GetMousePosition();  // Get the current mouse position
    return CheckCollisionPointRec(mousePosition, button);  // Check if the mouse position is within the button's rectangle
}

int main() {
    const int screenWidth = 800;   // Width of the game window
    const int screenHeight = 550;  // Height of the game window

    // Initialize the window with the specified width, height, and title
    InitWindow(screenWidth, screenHeight, "Test 5th grade");

    // Load the background image from the specified file path
    Texture2D background = LoadTexture("C:/Users/wweewe/sprint-math-games-9th-grade-pixelstorm/assets/tests.png");

    // If the background image fails to load, log a warning
    if (background.width == 0 || background.height == 0) {
        TraceLog(LOG_WARNING, "Background image failed to load. Using plain background.");
    }

    // Set the target frames per second for the game
    SetTargetFPS(60);

    // Questions and answers for the game
    Question questions[] = {
        {"A triangle's angles add up to ___ degrees.", "180"},
        {"The boundary of a circle is called the ___?", "circumference"},
        {"What is the formula for S of a rhombus?", "S=a*a"}
    };

    int currentQuestion = 0;  // Index of the current question
    int questionCount = sizeof(questions) / sizeof(questions[0]);  // Total number of questions
    char userAnswer[64] = "";  // Array to store the user's answer
    int answerIndex = 0;  // Index to track the position in the answer
    const char* message = nullptr;  // Message to display (feedback to the user)

    bool gameFinished = false;  // Flag to indicate if the game is finished

    // Main game loop 
    while (!WindowShouldClose()) {
        // Handle user input
        if (!gameFinished) {
            int key = GetCharPressed();  // Get the key pressed by the user
            while (key > 0) {  // Continue processing until there are no more keys pressed
                // Only allow printable characters (ASCII range 32-125) and check bounds
                if (key >= 32 && key <= 125 && answerIndex < 63) {
                    userAnswer[answerIndex++] = (char)key;  // Append the key to the answer
                    userAnswer[answerIndex] = '\0';  // Null-terminate the string
                }
                key = GetCharPressed();  // Get the next character
            }
            // Handle backspace key to delete characters from the answer
            if (IsKeyPressed(KEY_BACKSPACE) && answerIndex > 0) {
                userAnswer[--answerIndex] = '\0';  // Remove the last character
            }
            // Check if the user pressed Enter to submit their answer
            if (IsKeyPressed(KEY_ENTER)) {
                // Check if the user's answer is correct
                if (strcmp(userAnswer, questions[currentQuestion].answer) == 0) {
                    currentQuestion++;  // Move to the next question
                    if (currentQuestion < questionCount) {
                        message = "Correct! Next question.";  // Provide positive feedback
                    }
                    else {
                        gameFinished = true;  // End the game after all questions are answered
                        message = "Congratulations! You've completed the game!";
                    }
                    answerIndex = 0;  // Reset the answer index
                    userAnswer[0] = '\0';  // Reset the answer string
                }
                else {
                    message = "Incorrect. Try again.";  // Provide feedback for incorrect answers
                }
            }
        }
        else {
            // Check if the "Next" button is clicked after game completion
            Rectangle nextButton = { 300, 400, 200, 50 };  // Define the "Next" button position and size
            if (IsMouseOverButton(nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Reset the game if "Next" button is clicked
                gameFinished = false;
                currentQuestion = 0;
                message = nullptr;
                userAnswer[0] = '\0';
                answerIndex = 0;
            }
        }

        // Start drawing the frame
        BeginDrawing();
        ClearBackground(RAYWHITE);  // Clear the screen with a white background

        // Draw the background image if loaded successfully
        if (background.width > 0 && background.height > 0) {
            DrawTexture(background, 0, 0, WHITE);  // Draw the background texture at position (0, 0)
        }

        if (!gameFinished) {
            // Display the current question, centered on the screen
            const char* questionText = questions[currentQuestion].text;
            int questionWidth = MeasureText(questionText, 30);  // Measure the width of the question text
            DrawText(questionText, (screenWidth - questionWidth) / 2, 100, 30, BLACK);  // Draw the question at the center

            // Display the user's answer input field
            DrawText("Your answer:", 200, 200, 30, BLACK);
            DrawText(userAnswer, 400, 200, 30, BLACK);  // Display the user's answer
        }
        else {
            // Display a congratulatory message when the game is finished
            const char* completeText = "Congratulations! You've completed all the questions!";
            int textWidth = MeasureText(completeText, 30);
            DrawText(completeText, (screenWidth - textWidth) / 2, 200, 30, BLACK);

            // Draw "Next" button
            Rectangle nextButton = { 300, 400, 200, 50 };
            DrawRectangleRec(nextButton, LIGHTGRAY);  // Draw the button background
            DrawText("NEXT", 350, 415, 25, BLACK);  // Draw the button text

            // Highlight the button on hover
            if (IsMouseOverButton(nextButton)) {
                DrawRectangleLinesEx(nextButton, 2, RED);  // Highlight the button with a red border
            }
            else {
                DrawRectangleLinesEx(nextButton, 2, BLACK);  // Default black border
            }
        }

        // Display feedback message (Correct, Incorrect, or Congratulatory)
        if (message) {
            int messageWidth = MeasureText(message, 25);  // Measure the width of the feedback message
            DrawText(message, (screenWidth - messageWidth) / 2, 300, 25, WHITE);  // Draw the message in the center
        }

        EndDrawing();  // End the drawing phase of the frame
    }

    // Unload resources after the game loop ends
    UnloadTexture(background);  // Unload the background image
    CloseWindow();  // Close the game window and clean up resources
}
