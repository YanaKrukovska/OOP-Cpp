//
// Created by user on 03.04.2020.
//

#pragma once

#include "Array.h"
#include <cassert>
#include <string>

#define NDEBUG

#ifndef C_SEQUENCE_H
#define C_SEQUENCE_H

template<class Elem>
class Sequence {
public:
    class BadSeq;

    explicit Sequence(const size_t capacity = _default);

    ~Sequence();

    size_t capacity() const;

    size_t size() const;

    bool empty() const;

    bool full() const;

    const Elem &last() const;

    Sequence &clear();

    const Elem &operator[](const size_t index) const;

    Elem &operator[](const size_t index);

    Sequence &add(const Elem &elem);

    Sequence &insert(const Elem &elem, const size_t index);

    Sequence &cut();

    Sequence &remove(const size_t index);

    bool contains(const Elem &elem);

private:
    size_t _size;
    static const size_t _default = 0;
    Array<Elem> *_allocator;

    void reduce();

    void enlarge(const size_t times = 2);

    Sequence &doInsert(const Elem &elem, const size_t index);

    Sequence &doRemove(const size_t index);

    Sequence(const Sequence &);

    Sequence &operator=(const Sequence &);
};


template<class Elem>
class Sequence<Elem>::BadSeq {
private:
    string _reason;
public:
    explicit BadSeq(const string reason = "Error not found 404") : _reason(reason) {
#ifndef NDEBUG
        cout << "Threw error" << endl;
#endif
    }

    ~BadSeq() {
#ifndef NDEBUG
        cout << "Deleted error" << endl;
#endif
    }

    void diagnose() const {
        cerr << _reason << endl;
    }
};


template<class Elem>
Sequence<Elem>::Sequence(const size_t capacity) :
        _size(0), _allocator(new Array<Elem>(capacity)) {
#ifndef NDEBUG
    cout << "Created sequence, capacity = " << capacity << endl;
#endif
}

template<class Elem>
Sequence<Elem>::~Sequence() {
#ifndef NDEBUG
    cout << "Deleted sequence, capacity = " << capacity() << endl;
#endif
    delete _allocator;
}

template<class Elem>
size_t Sequence<Elem>::capacity() const {
    return _allocator->size();
}

template<class Elem>
size_t Sequence<Elem>::size() const {
    return _size;
}

template<class Elem>
bool Sequence<Elem>::empty() const {
    return (size() == 0);
}

template<class Elem>
bool Sequence<Elem>::full() const {
    return size() == capacity();
}

template<class Elem>
Sequence<Elem> &Sequence<Elem>::clear() {
#ifndef NDEBUG
    cout << "Cleared sequence" << endl;
#endif
    _size = 0;
    return *this;
}


template<class Elem>
const Elem &Sequence<Elem>::operator[](const size_t index) const {
    if (empty()) {
        throw BadSeq("Empty sequence");
    }
    if (index > _size) {
        throw BadSeq("Index out of bounds");
    }
    return (*_allocator)[index];
}

template<class Elem>
Elem &Sequence<Elem>::operator[](const size_t index) {
    if (empty()) {
        throw BadSeq("Empty sequence");
    }
    if (index > _size) {
        throw BadSeq("Index out of bounds");
    }
    return (*_allocator)[index];
}


template<class Elem>
Sequence<Elem> &Sequence<Elem>::add(const Elem &elem) {
    return doInsert(elem, _size);
}

template<class Elem>
Sequence<Elem> &Sequence<Elem>::insert(const Elem &elem, const size_t index) {
    if (size() < index) {
        throw BadSeq("Index out of bounds");
    }
    return doInsert(elem, index);
}

template<class Elem>
Sequence<Elem> &Sequence<Elem>::doInsert(const Elem &elem, const size_t index) {
    assert(index <= _size);
    if (_size <= capacity() / 4) {
        reduce();
    }
    if (_size + 1 > capacity()) {

        enlarge();
    }
    ++_size;
    for (size_t i = _size - 1; i > index; --i) {
        operator[](i) = operator[](i - 1);

    }
    operator[](index) = elem;
#ifndef NDEBUG
    cout << "Added [" << index << "] = " << elem << endl;

#endif
    return *this;
}

template<class Elem>
Sequence<Elem> &Sequence<Elem>::cut() {
    return doRemove(_size);
}

template<class Elem>
Sequence<Elem> &Sequence<Elem>::remove(const size_t index) {
    if ((_size < index) || (index == 0)) {
        throw BadSeq("Index out bounds");
    }
    return doRemove(index);
}


template<class Elem>
Sequence<Elem> &Sequence<Elem>::doRemove(const size_t index) {
    assert(index <= _size);
    if (empty()) {
        throw BadSeq("Error! Attempt to manipulate an empty sequence");

    }
    if (_size <= capacity() / 4) {
        reduce();

    }
    --_size;
    for (size_t i = index; (i <= _size) && (i > 0); ++i) {
        operator[](i - 1) = operator[](i);
    }
#ifndef NDEBUG
    cout << "Deleted element [" << index << "]" << endl;
#endif
    return *this;
}


template<class Elem>
bool Sequence<Elem>::contains(const Elem &elem) {
    for (size_t i = 0; i < _size; i++) {
        if (elem == (*_allocator)[i]) {
            return true;
        }
    }
    return false;
}

template<class Elem>
void Sequence<Elem>::enlarge(const size_t times) {
    Array<Elem> *newArray = new Array<Elem>(capacity() * 2 + 1);
    for (size_t i = 0; i < _size; ++i) {
        (*newArray)[i] = operator[](i);
    }
    delete _allocator;
    _allocator = newArray;

#ifndef NDEBUG
    cout << "Enlarged sequence to the capacity of " << capacity() << endl;
#endif
}

template<class Elem>
void Sequence<Elem>::reduce() {
    Array<Elem> *newArray = new Array<Elem>(capacity() / 2 + 1);
    for (size_t i = 0; i < _size; ++i) {
        (*newArray)[i] = operator[](i);

    }
    delete _allocator;
    _allocator = newArray;
#ifndef NDEBUG
    cout << "Reduced sequence to the capacity of " << capacity() << endl;
#endif
}


template<class Elem>
ostream &operator<<(ostream &os, const Sequence<Elem> &sequence) {
    os << "[";
    if (!sequence.empty()) {
        for (size_t i = 0; i < sequence.size(); ++i) {
            os << sequence[i] << (i != sequence.size() - 1 ? ", " : "");
        }
    }
    return os << "]";
}

#endif //C_SEQUENCE_H