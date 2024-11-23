#pragma once

#include "raylib.h"  
#include <cstring>    // Includes the C standard library for string manipulation functions (e.g., strcmp)

// Structure to hold a question and its answer
struct Question {
    const char* text;     // The text of the question
    const char* answer;   // The correct answer to the question
};


bool isMouseOverButton(Rectangle button);
void drawMenu();



