//
// Created by user on 25.03.2020.
//

#include <iostream>
#include "QueueArray.h"
#include "QueueList.h"
#include "cassert"

using namespace std;

int main() {

    cout << "TESTING QUEUE BASED ON ARRAY" << endl;
    QueueArray<int> queueArrayInt(3);
    assert(queueArrayInt.size() == 0);
    assert(queueArrayInt.empty() == 1);
    assert(queueArrayInt.full() == 0);
    assert(queueArrayInt.capacity() == 3);

    queueArrayInt.put(3);
    queueArrayInt.put(2);
    queueArrayInt.put(1);

    assert(queueArrayInt.size() == 3);

    //Won't add because queue is full
    queueArrayInt.put(0);
    assert(queueArrayInt.full() == 1);


    //Remove first element (3)
    queueArrayInt.pop();
    assert(queueArrayInt.size() == 2);
    assert(queueArrayInt.front() == 2);

    queueArrayInt.pop();
    queueArrayInt.pop();
    //Won't  pop because queue is empty
    queueArrayInt.pop();


    cout << endl << "TESTING QUEUE BASED ON LINKED LIST" << endl;


    QueueList<char> queueListChar;
    assert(queueListChar.size() == 0);
    assert(queueListChar.empty() == 1);
    assert(queueListChar.full() == 0);

    queueListChar.put('c');
    queueListChar.put('b');
    queueListChar.put('a');

    assert(queueListChar.size() == 3);
    assert(queueListChar.full() == 0);

    //Remove first element (c)
    queueListChar.pop();
    assert(queueListChar.size() == 2);
    assert(queueListChar.front() == 'b');

    queueListChar.pop();
    queueListChar.pop();
    //Won't pop because queue is empty
    queueListChar.pop();

    return 0;
}