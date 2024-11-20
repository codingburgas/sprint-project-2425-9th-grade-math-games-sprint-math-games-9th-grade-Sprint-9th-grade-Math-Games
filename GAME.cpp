#include <iostream> 
using namespace std;

int main() {
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
}