#include "Sequence.h"
#include <iostream>
#include "cassert"

using namespace std;

int main() {

    try {
        Sequence<int> test1;
        cout << "Test1 array: " << test1 << endl;

        //Testing adding
        test1.add(0);
        test1.add(1);
        test1.add(2);

        cout << "Test1 array: " << test1 << endl;

        //Testing contain, size and capacity
        assert(test1.contains(0) == 1);
        assert(test1.contains(10) == 0);
        assert(test1.size() == 3);
        assert(test1.capacity() == 3);

        //Testing empty and full
        assert(test1.empty() == 0);
        assert(test1.full() == 1);


        //Testing cut
        test1.cut();
        cout << "Test1 array after cut(): " << test1 << endl;
        assert(test1.size() == 2);

        //Testing remove
        test1.remove(2);
        cout << "Test1 array after remove(): " << test1 << endl;

        //Testing insert
        test1.insert(1, 0);
        cout << "Test1 array after insert(): " << test1 << endl;

        //Testing clear() and [] (throw an empty array error)
        cout << "First element: " << test1[0] << endl;
        test1.clear();
        cout << "First element: " << test1[0] << endl;


    }
    catch (const Sequence<int>::BadSeq &b) {
        b.diagnose();
    }


    return 0;
}