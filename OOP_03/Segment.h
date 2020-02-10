#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

class Segment
{
private:
    const Point _a;
    const Point _b;
    static int _freeID;
    int _myId;

    Segment(const Segment &);
    Segment &operator=(const Segment &);

public:

    Segment(const Point &start, const Point &end):_a(start),_b(end), _myId(_freeID++){};

    ~Segment();

    const Point &start() const { return _a; };
    const Point &end() const { return _b; };

    int getID() const { return _myId; };
};

inline ostream &operator<<(ostream & os, const Segment & segment)
{
    os << " Segment [" << segment.start() << ", " << segment.end() << "], ID = " << segment.getID() << endl;
    return os;
}