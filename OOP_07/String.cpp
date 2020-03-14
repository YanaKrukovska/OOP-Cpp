#include "String.h"

String::String() : _allocator(new char[1]), _len(0) {
    _allocator[0] = '\0';

#ifndef NDEBUG
    cout << "Created new string: " << *this << endl;
#endif
}

String::String(const char *source) {
    if (source == nullptr) {
        throw BadString("null string");
    }
    _len = strlen(source);
    _allocator = new char[_len + 1];
    strcpy(_allocator, source);

#ifndef NDEBUG
    cout << "Created new string: " << *this << endl;
#endif
}

String::String(const char c) :
        _len(1) {
    _allocator = new char[2];
    _allocator[0] = c;
    _allocator[1] = '\0';

#ifndef NDEBUG
    cout << "Created new string with char: " << *this << endl;
#endif
    return;
}

String::String(const string &s) :
        _allocator(new char[s.length() + 1]),
        _len(s.length()) {
    strcpy(_allocator, s.c_str());

#ifndef NDEBUG
    cout << "Created new string: " << *this << endl;
#endif
    return;
}

String::String(const String &source, int multiplayer) :
        _len(source._len * multiplayer), _allocator(new char[_len + 1]) {

    char *target = _allocator;
    for (int i = 0; i < multiplayer; i++) {
        strcpy(target, source._allocator);
        target += source._len;
    }

#ifndef NDEBUG
    cout << "Copied string: " << *this << endl;
#endif
};

String::~String() {
    _allocator = nullptr;
    delete[] _allocator;

#ifndef NDEBUG
    cout << "Deleted string: " << *this << endl;
#endif
    return;
};

const string String::STL_string() const {
    return string(c_str());
}

const char *String::c_str() const {
    return _allocator;
}

size_t String::length() const {
    return _len;
}

bool String::empty() const {
    return _len == 0;
}

void String::clear() {
    delete[] _allocator;
    _len = 0;
    _allocator = new char[1];
    _allocator[0] = '\0';
}

char &String::operator[](size_t position) {
    if (position >= _len) {
        throw BadIndex(position);
    }
    return _allocator[position];
}

const char String::operator[](size_t position) const {
    if (position >= _len) {
        throw BadIndex(position);
    }
    return _allocator[position];
}

bool String::operator==(const String &anotherString) const {
    bool areEqual = _len == anotherString.length();
    for (size_t i = 0; (i < _len) && areEqual; i++) {
        areEqual = (_allocator[i] == anotherString[i]);
    }
    return areEqual;
}

bool String::operator!=(const String &anotherString) const {
    return !(*this == anotherString);
}

bool String::operator<(const String &anotherString) const {

    bool areEqual = true;
    size_t i = 0;
    while (areEqual && (i < _len) && (i < anotherString._len)) {
        areEqual = areEqual && (_allocator[i] == anotherString[i]);
        i++;
    }
    if (areEqual) {
        return _len < anotherString.length();
    }
    i--;
    return _allocator[i] == anotherString[i];
}

bool String::operator<=(const String &anotherString) const {
    if (*this == anotherString) {
        return true;
    }
    return *this < anotherString;

}

bool String::operator>(const String &anotherString) const {
    return !(*this <= anotherString);
}

bool String::operator>=(const String &anotherString) const {
    if (*this == anotherString) {
        return true;
    }
    return *this > anotherString;
}

String String::operator+(const String &anotherString) const {
    String res(*this);
    return res += anotherString;
}

String &String::operator+=(const char *source) {
    if (source == nullptr) {
        return *this;
    }
    size_t length = strlen(source);
    char *newAllocator = new char[length + _len + 1];
    strcpy(newAllocator, _allocator);
    delete[] _allocator;

    _allocator = newAllocator;
    strcpy(_allocator + _len, source);
    _len += length;

    return *this;
}

String &String::operator+=(const String &anotherString) {
    size_t length = _len + anotherString.length();
    char *new_alloc = new char[length + 1];
    strcpy(new_alloc, _allocator);
    delete[] _allocator;

    _allocator = new_alloc;
    strcpy(_allocator + _len, anotherString._allocator);
    _len = length;

    return *this;
}

String &String::operator+=(const string &anotherString) {
    size_t length = _len + anotherString.length();
    char *new_alloc = new char[length + 1];
    strcpy(new_alloc, _allocator);
    delete[] _allocator;

    _allocator = new_alloc;
    strcpy(_allocator + _len, anotherString.c_str());
    _len = length;

    return *this;
}


String &String::operator=(const String &anotherString) {
    if (this == &anotherString) {
        return *this;
    }
    delete[] _allocator;

    _len = anotherString.length();
    _allocator = new char[_len + 1];
    strcpy(_allocator, anotherString.c_str());

    return *this;
}

String &String::operator=(const string &anotherString) {
    *this = String(anotherString);
    return *this;
}

String &String::operator=(const char *anotherString) {
    *this = String(anotherString);
    return *this;
}

String &String::operator=(const char anotherString) {
    *this = String(anotherString);
    return *this;
}

ostream &operator<<(ostream &out, const String &source) {
    if (source.c_str() != nullptr) {
        return out << source.c_str();
    } else {
        return out << "null";
    }
}

