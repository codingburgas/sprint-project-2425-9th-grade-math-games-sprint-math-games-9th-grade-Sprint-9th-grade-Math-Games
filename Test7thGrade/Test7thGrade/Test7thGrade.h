#pragma once

// Include guard to prevent multiple inclusions of the header file
#include "raylib.h"  // Include the Raylib library for graphical functions and utilities
#include <cstring>   // Include the C string library for string manipulation (e.g., strcmp)

// Structure to represent a question in the quiz
struct Question {
    const char* text;     // Pointer to the question text (e.g., "What is 2+2?")
    const char* answer;   // Pointer to the correct answer text (e.g., "4")
};

// Function prototype for checking if the mouse is over a button
bool IsMouseOverButton(Rectangle button);

