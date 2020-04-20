#include <iostream>
#include "Interface.h"

using namespace std;

void showMainMenu() {
    cout << "1) Start Game" << endl;
    cout << "2) Change size of the field" << endl;
    cout << "Press 0 to exit" << endl;
}

void showExit() {
    system("cls");
    cout << "Game over" << endl;
}

void setNewSizes(int &rows, int &columns) {

    do {
        cout << "Enter a number of rows from 10 to 40: ";
        cin >> rows;
        if (rows < 10 || rows > 40) {
            cout << "Wrong numbers. Try again" << endl;
        }
    } while (rows < 10 || rows > 40);


    do {
        cout << "Enter a number of columns from 10 to 40: ";
        cin >> columns;
        if (columns < 10 || columns > 40) {
            cout << "Wrong numbers. Try again" << endl;
        }
    } while (columns < 10 || columns > 40);
}



