#pragma once
#include "raylib.h"
#include <cstring>

// Structure to hold a question and its answer
struct Question {
    const char* text;
    const char* answer;
};

// Function prototypes
bool IsMouseOverButton(Rectangle button);
