#include <iostream>

using namespace std;

void Menu() {
    // Function which prints the game name and menu options
    cout << " /$$      /$$                           /$$ /$$          " << endl;
    cout << "| $$  /$ | $$                          | $$| $$          " << endl;
    cout << "| $$ /$$$| $$  /$$$$$$   /$$$$$$   /$$$$$$$| $$  /$$$$$$ " << endl;
    cout << "| $$/$$ $$ $$ /$$__  $$ /$$__  $$ /$$__  $$| $$ /$$__  $$" << endl;
    cout << "| $$$$_  $$$$| $$  | $$| $$  |__/| $$  | $$| $$| $$$$$$$$" << endl;
    cout << "| $$$/ |  $$$| $$  | $$| $$      | $$  | $$| $$| $$_____/ " << endl;
    cout << "| $$/   |  $$|  $$$$$$/| $$      |  $$$$$$$| $$|  $$$$$$$ " << endl;
    cout << "|__/     |__/ \______/ |__/       |_______/|__/ |_______/ " << endl;

    int choice;

    do {
        cout << "   1. Play\n   2. How To Play\n    3. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            // Play the game
            char word[6] = "Apple"; // Скритата дума
    char guess[6]; // Написаната дума от играча
    int maxTries = 6; // Опитите

    // Инструкции
    cout << "Welcome to Wordle! You have " << maxTries << " attempts to guess the word.\n";
    cout << "Hints: '*' means correct letter and position, '+' means correct letter but wrong position.\n";
    cout << "Hint for the word: This is a fruit and the word is with capital letters" << endl;

    // Цикъл за опитите
    for (int attempt = 1; attempt <= maxTries; ++attempt) {
        cout << "Attempt " << attempt << endl << " Enter your 5-letter word: ";
        cin >> guess; // Написаната дума от играча

        // Дължината на думата
        int length = 0; 
        while (guess[length]) length++; 

        // Ако е прекалено дълга
        if (length != 5) {
            cout << "Please enter a 5-letter word." << endl;
            attempt--; // Намаляваме опитите на играча
            continue; // Пропускаме останалата част от цикъла
        }

        // Обратна връзка (за всяка буква: '*', '+', или '-')
        char feedback[6] ; // '-' е грешна буква

        // Думата дали е позната
        bool correct = true;

        // Проверява буквите в думата
        for (int i = 0; i < 5; ++i) {
            if (guess[i] == word[i]) {
                feedback[i] = '*'; // '*' при правилна и на правилно място буква
            } else {
                // Буквата има ли я в думата ако не е на правилното място
                bool found = false;
                for (int j = 0; j < 5; ++j) {
                    if (guess[i] == word[j] && i != j) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    feedback[i] = '+'; // Буквата е правилна, но на грешна позиция
                    correct = false; // Думата не е правилна
                } else {
                    feedback[i] = '-'; // Буквата не съществува в думата
                    correct = false;
                }
            }
        }

        // Добавяме терминатор '\0' за обратната връзка, за да е валиден низ
        feedback[5] = '\0';

        // Резултат
        cout << "Feedback: " << feedback << endl;

        if (correct) {
            cout << "Congratulations! You've guessed the word: " << word << "!\n";
            return 0;
        }
    }

    // Какво се изписва щом не познаеш думата
    cout << "Sorry! You've used all your attempts. The word was: " << word << ". Better luck next time!" << endl;
    return 0; 


            break;

        case 2:
            // Tutorial on how to play
            cout << "1. Start with a Guess: Enter any valid 5-letter word to gather clues about the hidden word.";
                cout << "2. Check the Feedback: Green = correct position, Yellow = wrong position, Gray = not in the word.";
                cout << "3. Refine Your Guesses: Use feedback to make smarter guesses; avoid repeating gray letters, position yellows correctly.";
                cout << "4. Win or Lose: Guess the word in 6 tries to win; otherwise, the hidden word is revealed.";

                break;

        case 3:
            // Exit the game
            cout << "Bye\n";
            return;  // Exit the Menu function
            break;

        default:
            cout << "Invalid option\n";
            break;
        }
    } while (choice != 3);
}


int main() {
Menu();

}
