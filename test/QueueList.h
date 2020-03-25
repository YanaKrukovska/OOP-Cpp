#pragma once

#include "Queue.h"

using namespace std;

template<class T>
class QueueList : public Queue<T> {
private:
    struct Node {
        T value;
        Node* next;

        explicit Node(T data) {
            value = data;
            next = NULL;
        }
    };


public:

    size_t _size;
    Node* _front, * _rear;

    QueueList(): _size(0) {
        _front = _rear = NULL;
    }

    ~QueueList() {}

    const T& front() const {
        return _front->value;
    }


    void put(const T& value) {

        Node* temp = new Node(value);
        if (_rear == NULL) {
            _front = _rear = temp;
            _size++;
            return;
        }

        _rear->next = temp;
        _rear = temp;
        _size++;
    }


    void pop() {

        if (_front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Deleted " <<  _front->value << endl;

        Node* temp = _front;
        _front = _front->next;

        if (_front == NULL)
            _rear = NULL;

        _size--;
        delete (temp);

    }

    //Unlimited
    bool full() const {
        return false;
    }


    bool empty() const {
        return _size == 0;
    }

    size_t size() const {
        return _size;
    }

    //No implementation. No need to check capacity
    size_t capacity() const {
        return -1;
    }


};