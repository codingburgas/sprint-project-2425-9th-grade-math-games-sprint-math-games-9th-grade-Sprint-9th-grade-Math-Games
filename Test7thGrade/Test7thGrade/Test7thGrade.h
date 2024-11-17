#pragma once

#include "raylib.h"  
#include <cstring>    


struct Question {
    const char* text;     
    const char* answer;   
};


bool IsMouseOverButton(Rectangle button);
