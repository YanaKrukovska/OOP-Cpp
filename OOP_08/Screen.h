//
// Created by user on 21.03.2020.
//

#ifndef C_SCREEN_H
#define C_SCREEN_H

#include "ostream"

using namespace std;

class Screen {

public:
    explicit Screen(int = maxHeight, int = maxWidth, char *screen = nullptr);

    ~Screen();

    const Screen &home() const;

    Screen &home();

    const Screen &move() const;

    Screen &move();

    const Screen &back() const;

    Screen &back();

    const Screen &show() const;

    Screen &show();

    const Screen &move(int, int) const;

    Screen &move(int, int);

    Screen &clear();

    const Screen &showCurrent() const;

    char get() const;

    Screen &set(char);

private:
    static const int maxHeight;
    static const int maxWidth;
    static const char _filler;

    int _height;
    int _width;

    char *_wContent;
    mutable int _cursor;

    //No implementation
    Screen(const Screen &);

    Screen &operator=(const Screen &);
};


ostream &operator<<(ostream &, const Screen &);

typedef const Screen &(Screen::* const ConstAction)() const;

typedef Screen &(Screen::* const NonConstAction)();

void doActionConst(const Screen &screen, ConstAction act, int n);

void doActionNonConst(Screen &screen, NonConstAction act, int n);


#endif //C_SCREEN_H
