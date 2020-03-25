
#include "Queue.h"

using namespace std;

template<class T>
class QueueArray : public Queue<T> {
private:
    int _front;
    int _rear;

public:
    T *arr;
    size_t _capacity;
    size_t _size;
    static int max;


explicit QueueArray(int maxCapacity): _capacity(maxCapacity), _size(0), _front(0), _rear(-1) {
    arr = new T[maxCapacity];
}


~QueueArray() {
    delete[] arr;
}

const T &front() const {
    return arr[_front];
}


void put(const T &value) {
    if (full()) {
        cout << "Queue is full" << endl;
        return;
    } else {
        _rear = (_rear + 1) % _capacity;
        arr[_rear] = value;
        _size++;
    }

}


void pop() {
    if (empty()) {
       cout << "Queue is empty" << endl;
       return;
    }

    cout << "Deleted " <<  arr[_front] << endl;

    _front++;
    _size--;
}


bool empty() const {
    return _size == 0;
}

bool full() const {
    return _capacity == _size;
}

size_t size() const {
    return _size;
}

size_t capacity() const {
    return _capacity;
}


};
