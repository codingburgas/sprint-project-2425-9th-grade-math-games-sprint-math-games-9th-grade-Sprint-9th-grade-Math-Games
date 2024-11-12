#include <iostream>
using namespace std;

void Menu() {
//Function which prints the game name and menu options
cout << " /$$      /$$                           /$$ /$$          " << endl;
cout << "| $$  /$ | $$                          | $$| $$          " << endl;
cout << "| $$ /$$$| $$  /$$$$$$   /$$$$$$   /$$$$$$$| $$  /$$$$$$ " << endl;
cout << "| $$/$$ $$ $$ /$$__  $$ /$$__  $$ /$$__  $$| $$ /$$__  $$" << endl;
cout << "| $$$$_  $$$$| $$  | $$| $$  |__/| $$  | $$| $$| $$$$$$$$" << endl;
cout << "| $$$/ |  $$$| $$  | $$| $$      | $$  | $$| $$| $$_____/" << endl;
cout << "| $$/   |  $$|  $$$$$$/| $$      |  $$$$$$$| $$|  $$$$$$$" << endl;
cout << "|__/     |__/ \______/ |__/       |_______/|__/ |_______/" << endl;

int choice;

do 
{
cout << "   1. Play\n   2. How To Play\n    3. Exit" << endl;
cin >> choice;

switch(choice) 
{

case 1:
//play
break;

case 2:
//Tutorial how to play
cout << "\n";
break;

case 3:
//exit
return 0;
cout << "Bye\n";
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
