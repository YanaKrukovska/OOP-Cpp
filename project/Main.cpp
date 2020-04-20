#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Snake.h"
#include "Interface.h"
#include "GameException.h"

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

using namespace std;

int main() {


    int rows = 10, columns = 10;
    int snakeSpeed = 300;

    Field *field;
    Snake *snake;
    Point head;
    char userAnswer;
    int keyPressed;
    Direction direction;

    try {


        do {
            showMainMenu();
            cin >> userAnswer;
            system("cls");

            switch (userAnswer) {
                case '0':
                    cout << "Leaving..." << endl;;
                    break;
                case '1':

                    head.y = rows / 2;
                    head.x = columns / 2;
                    direction = Direction::UP;

                    field = new Field(rows, columns);
                    snake = new Snake(field, head);

                    while (!snake->hasDied()) {
                        if (_kbhit()) {
                            keyPressed = _getch();


                            switch (keyPressed) {
                                case 'w':
                                case 'W':
                                    direction = Direction::UP;
                                    break;
                                case 's':
                                case 'S':
                                    direction = Direction::DOWN;

                                    break;
                                case 'a':
                                case 'A':
                                    direction = Direction::LEFT;
                                    break;
                                case 'd':
                                case 'D':
                                    direction = Direction::RIGHT;

                                    break;
                            }
                        }


                        switch (direction) {
                            case UP:
                                head.y--;
                                break;
                            case DOWN:
                                head.y++;
                                break;
                            case LEFT:
                                head.x--;
                                break;
                            case RIGHT:
                                head.x++;
                                break;
                        }


                        snake->move(field, head);
                        field->showField();
                        cout << "Points: " << snake->getPoints() << "\n";
                        Sleep(snakeSpeed);
                        system("cls");
                    }

                    showExit();

                    delete snake;
                    delete field;
                    break;

                case '2':
                    cout << "New field size is rows = " << rows << ", columns = " << columns << endl;
                    setNewSizes(rows, columns);
                    system("cls");
                    break;
                default:
                    cout << "Wrong input. Try again" << endl;
                    break;
            }

        } while (userAnswer != '0');
    }
    catch (const GameException &ex) {
        system("cls");
        ex.show();
    }

    return 0;
}