#include "Screen.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Creating new empty screen1:" << endl;
    int width = 20, height = 5;
    Screen screen1(width, height);
    screen1.show();
    cout << endl;

    screen1.move();
    screen1.move();
    cout << "Getting element at position 2: " << screen1.get() << endl;
    cout << "Setting element at position 2" << endl << screen1.set('*');
    cout << "Getting element at position 2: " << screen1.get() << endl;


    cout << endl << "Going back home, moving to certain positions and changing characters" << endl;
    screen1.home();
    screen1.set('1').move(1, 0).set('2').move(2, 0).set('3').move(3, 0).set('4').move(4, 0).set('5').show();

    cout << endl << "Testing back functions" << endl;
    screen1.back().set('!').show();

    cout << endl << "Testing show current: " << endl;
    screen1.showCurrent();
    cout << endl;

    const ConstAction constActions[] = {&Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::showCurrent };

    cout << "CONST ACTIONS TESTER" << endl;
    char constContent[] = "screen 1";
    const Screen constScreen(width, height, constContent);
    int chosenActionNumber, repeatAmount;
    char repeat;
    constScreen.show();
    do {
        cout << "choose action: 0-home, 1-move, 2-back, 3-show, 4-showCurrent: ";
        cin >> chosenActionNumber;
        while (chosenActionNumber < 0 || chosenActionNumber > 4)
        {
            cout << "Wrong user input, try again: ";
            cin >> chosenActionNumber;
        }
        cout << "How many times shall we repeat?: ";
        cin >> repeatAmount;
        while (repeatAmount <= 0)
        {
            cout << "Wrong user input, should be above 0, try again: ";
            cin >> repeatAmount;
        }
        doActionConst(constScreen, constActions[chosenActionNumber], repeatAmount);
        cout << endl <<"Would you like to continue? y/n: ";
        cin >> repeat;
    } while (repeat == 'y');



    cout << endl << "NON CONST ACTIONS TESTER" << endl;

    char nonConstContent[] = "screen 2";
    const NonConstAction nonConst[] = {&Screen::home, &Screen::move, &Screen::back, &Screen::clear, &Screen::show };

     Screen nonConstScreen(width, height, nonConstContent);
     nonConstScreen.show();

     do {
         cout << "choose action: 0-home, 1-move, 2-back, 3-clear, 4-show, 5-move to (i,j), 6-set: ";

         cin >> chosenActionNumber;
         while (chosenActionNumber < 0 || chosenActionNumber > 7)
         {
             cout << "Wrong user input, try again: ";
             cin >> chosenActionNumber;
         }
         switch (chosenActionNumber)
         {
             case 5:
                 int row, column;
                 cout << "Enter the row from 0 to "<< width << ": ";
                 cin >> row;
                 while (row < 0 || row > width)
                 {
                     cout << "Wrong input, try again: ";
                     cin >> row;
                 }
                 cout << "Enter the column from 0 to " << height << ": ";
                 cin >> column;
                 while (column < 0 || column > height)
                 {
                     cout << "Wrong input, try again: ";
                     cin >> column;
                 }
                 nonConstScreen.move(row, column);
                 break;
             case 6:
                 char character;
                 cout << "Enter the character: ";
                 cin >> character;
                 nonConstScreen.set(character);
                 break;
             default:
                 cout << "How many times shall we repeat?: ";
                 cin >> repeatAmount;
                 while (repeatAmount <= 0)
                 {
                     cout << "Wrong user input, should be above 0, try again: ";
                     cin >> repeatAmount;
                 }
                 doActionNonConst(nonConstScreen, nonConst[chosenActionNumber], repeatAmount);
         }
         cout << endl <<"Would you like to continue? y/n: ";
         cin >> repeat;
     } while (repeat == 'y');

    return 0;
}