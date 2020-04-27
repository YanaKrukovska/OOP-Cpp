//
// Created by user on 08.02.2020.
//

#include <iostream>
#include "Point.h"
#include "Segment.h"
#define NDEBUG
#include <cassert>

using namespace std;

int main()
{
    Point point1(1, 3);
    Point point2(5, 6);

    Segment segment1(0, 0, 0, 5);
    Segment segment2(point1, point2);
    Segment segment3(4);
    Segment segment4(segment1);

    cout << segment1 << segment2 << segment3 << segment4;


    Point test1(0, 0);
    Point test2(0, 5);

    assert(segment1.start() == test1);
    assert(segment4.end() == test2);


    assert(segment2.startX() == 1);
    assert(segment2.startY() == 3);
    assert(segment2.endX() == 5);
    assert(segment2.endX() == 6);

    assert(segment3.getID() == 3);

    segment3 = segment1;
    assert(segment3.start() == segment1.start());
    assert(segment3.end() == segment1.end());

    // (5 - 1)^2 + (6 - 3)^2
    assert(segment2.length() == 5);


    Point test3(3, 5);
    Point test4(2, -10);
    assert(segment1.distance(test3) == 5);
    assert(distance(segment4, test3) == -10);


}

