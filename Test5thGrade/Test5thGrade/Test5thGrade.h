#pragma once  // Ensures that the file is included only once during compilation

#include "raylib.h"  
#include <cstring>    // Includes the C standard library for string manipulation functions (e.g., strcmp)

// Structure to hold a question and its answer
struct Question {
    const char* text;     // The text of the question
    const char* answer;   // The correct answer to the question
};


bool IsMouseOverButton(Rectangle button);
