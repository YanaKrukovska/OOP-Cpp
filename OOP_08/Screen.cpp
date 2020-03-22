//
// Created by user on 21.03.2020.
//

#include <iostream>
#include "Screen.h"

using namespace std;

const int Screen::maxHeight = 24;
const int Screen::maxWidth = 80;
const char Screen::_filler = '.';

Screen::Screen(int width, int height, char *screen) :
        _width(width > maxWidth ? maxWidth : width),
        _height(height > maxHeight ? maxHeight : height), _cursor(0) {
    int length;
    if (screen == nullptr) {
        length = 0;
    } else {
        length = strlen(screen);
    }

    if (length > _height * _width) {
        length = _height * _width;
    }

    _wContent = new char[_height * _width + 1];
    _wContent[_height * _width] = '\0';

    int k = 0;
    while (k < length) {
        _wContent[k++] = *screen++;
    }
    while (k < _height * _width) {
        _wContent[k++] = _filler;
    }

#ifndef NDEBUG
    cout << "Created new screen" << endl;
#endif
}

Screen::~Screen() {
    delete[] _wContent;
#ifndef NDEBUG
    cout << "Deleted screen" << endl;
#endif
}

const Screen &Screen::home() const {
    _cursor = 0;
    return *this;
}

Screen &Screen::home() {
    _cursor = 0;
    return *this;
}

const Screen &Screen::move() const {
    if (_cursor >= _width * _height - 1) {
        _cursor = 0;
    } else {
        _cursor += 1;
    }
    return *this;
}

Screen &Screen::move() {
    if (_cursor >= _width * _height - 1) {
        _cursor = 0;
    } else {
        _cursor += 1;
    }
    return *this;
}

const Screen &Screen::back() const {
    if (_cursor > 0) {
        --_cursor;
    }
    return *this;
}

Screen &Screen::back() {
    if (_cursor > 0) {
        --_cursor;
    }
    return *this;
}

Screen &Screen::show() {
    int temp = _cursor;
    home();

    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            showCurrent().move();
        }
        cout << endl;
    }
    _cursor = temp;
    return *this;
}

const Screen &Screen::show() const {
    int temp = _cursor;
    home();
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            showCurrent().move();
        }
        cout << endl;
    }
    _cursor = temp;
    return *this;
}

const Screen &Screen::move(int row, int column) const {
    if (row < _height && column < _width && row >= 0 && column >= 0) {
        _cursor = _width * row + column;
    } else {
        _cursor = 0;
    }
    return *this;
}

Screen &Screen::move(int row, int column) {
    if (row < _height && column < _width && row >= 0 && column >= 0) {
        _cursor = _width * row + column;
    } else {
        _cursor = 0;
    }
    return *this;
}

Screen &Screen::clear() {
    for (int i = 0; i < _height * _width; i++) {
        _wContent[i] = _filler;
    }
    _cursor = 0;
    return *this;
}

const Screen &Screen::showCurrent() const {
    cout << get();
    return *this;
}

char Screen::get() const {
    return _wContent[_cursor];
}

Screen &Screen::set(char element) {
    _wContent[_cursor] = element;
    return *this;
}

ostream &operator<<(ostream &os, const Screen &screen) {
    screen.show();
    return os;
}

void doActionConst(const Screen &screen, ConstAction act, int n) {
    for (int i = 0; i < n; i++) {
        (screen.*act)();
    }
}

void doActionNonConst(Screen &screen, NonConstAction act, int n) {
    for (int i = 0; i < n; i++) {
        (screen.*act)();
    }
}