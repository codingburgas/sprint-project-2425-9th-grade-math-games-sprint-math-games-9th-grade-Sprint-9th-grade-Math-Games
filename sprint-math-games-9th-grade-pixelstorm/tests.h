#pragma once

// Structure to hold a question and its correct answer
struct Question {
    const char* text;   // The question text
    const char* answer; // The correct answer
};

// Function to start and handle the 5th-grade test
void test(Question* question, int questionCount, int grade);