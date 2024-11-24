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

            break;

        case 2:
            // Tutorial on how to play
            cout << "1. Start with a Guess: Enter any valid 5-letter word to gather clues about the hidden word."
                cout << "2. Check the Feedback: Green = correct position, Yellow = wrong position, Gray = not in the word."
                cout << "3. Refine Your Guesses: Use feedback to make smarter guesses; avoid repeating gray letters, position yellows correctly."
                cout << "4. Win or Lose: Guess the word in 6 tries to win; otherwise, the hidden word is revealed."

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
