#pragma once

#include <iostream>
#define NDEBUG

using namespace std;

template<size_t n, class T>
class Array {
private:
    T* _alloc;
    size_t _length;

public:
    class BadArray;

    explicit Array() : _length(n) {
        _alloc = new T[_length]();
#ifndef NDEBUG
        cout << "Created new array: " << endl;
#endif
    }

    Array(const Array& source) : _length(source.length()) {
        delete[] _alloc;
        _alloc = nullptr;
        _alloc = new T[_length]();
        for (size_t i = 0; i < _length; i++) {
            _alloc[i] = source[i];
        }
#ifndef NDEBUG
        cout << "Copied array: " << endl;
#endif
    }

    ~Array() {
        delete[] _alloc;
        _alloc = nullptr;
#ifndef NDEBUG
        cout << "Deleted array: " << endl;
#endif
    }


    const T& operator[](const size_t index) const {

        if (index < _length) {
            return _alloc[index];
        }
        else {
            throw BadArray("index out of bounds: ", index);
        }
    }

    T& operator[](const size_t index) {
        if (index < _length) {
            return _alloc[index];
        }
        else {
            throw BadArray("index out of bounds ", index);
        }
    }

    Array& operator=(const Array& anotherArray) {
        delete[] _alloc;
        _alloc = nullptr;
        _alloc = new T[anotherArray.length()]();
        for (size_t i = 0; i < anotherArray.length(); i++) {
                _alloc[i] = anotherArray[i];
        }
        return *this;
    }

    const size_t length() const {
        return _length;
    }

};

template<size_t n, class T>
class Array<n, T>::BadArray {
private:
    string _reason;
    size_t _index;
public:

    explicit BadArray(string reason = "", const size_t index = 0) {
        _reason = reason;
        _index = index;
#ifndef NDEBUG
        cout << "Threw bad array: " << endl;
#endif
    }

    ~BadArray() {
#ifndef NDEBUG
        cout << "Deleted bad array: " << endl;
#endif
    }

    void diagnose() const {
        cerr << "Reason: " << _reason << endl << "Index: " << _index << endl;
    }

};

template<size_t n, class T>
ostream& operator<<(ostream& os, const Array<n, T>& array) {
    os << "{";
    for (size_t i = 0; i < array.length(); i++) {
        os << array[i] << ", ";
    }
    return os << "}";
};
