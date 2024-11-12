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

string Words[about, other, which, their, there, would, could, these, every, after, think, being, those, never, where, shall, world, under, still, great, right, place, again, small, found, given, white, state, house, might, night, often, water, since, early, until, among, later, sense, began, least, human, power, point, asked, money, study, young, known, times, heart, group, whole, words, means, above, light, white, order, class, bring, today, large, story, among, music, field, worth, works, below, black, happy, words, lives, terms, makes, month, clear, truth, quite, court, mind, heard, learn, south, north, build, trade, peace, shows, helps, check, claim, dream, based, reach, event, style, wrong, force, focus, local, stage, broke, wrote, calls];
//All the possible words that can be 
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
