#pragma once
#include "raylib.h"

enum TestScreen { MENU, TESTS_MENU, FIFTH_GRADE_TEST, SIXTH_GRADE_TEST, SEVENTH_GRADE_TEST };

void drawMenuTests(TestScreen& currentScreen);
