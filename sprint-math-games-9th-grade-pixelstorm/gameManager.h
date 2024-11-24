#pragma once
#include "raylib.h"
#include "menu.h"
#include "testsMenu.h"
#include "tests.h"

class GameManager 
{
	public:
		~GameManager();
		void drawMainLoop();
		GameManager();

    private:

        Question questions5thGrade[3] = {
            {"A triangle's angles add up to ___ degrees.", "180"},
            {"The boundary of a circle is called the ___?", "circumference"},
            {"What is the formula for S of a rhombus?", "S=a*a"}
        
           
        };

        Question questions6thGrade[3] = {
            {"Solve: 3² + 4²", "25"},
            {"Simplify the fraction 20/40.", "1/2"},
            {"What is 15% of 200?", "30"}
        };

        Question questions7thGrade[3] = {
            {"What is the square root of 144?", "12"},
            {"What is 2.5+2.5", "5"},
            {"Simplify: 4x + 5x−3.", "9x-3"}
        };

};