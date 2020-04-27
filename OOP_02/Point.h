//
// Created by user on 08.02.2020.
//


#ifndef C_POINT_H
#define C_POINT_H

#pragma warning(disable: 4700)

#include <iostream>

using namespace std;

class Point

{

private:

    static int freeID;

    const int pointID;

    double _x;

    double _y;

public:

    explicit Point(double x = 0, double y = 0);

    Point(const Point&);

    ~Point();

    Point& operator=(const Point&);

    double& x();

    double& y();

    const double& x()const;

    const double& y()const;

    const int getID() const {
        return pointID;
    };

    static int amount() { return freeID; };

};


ostream & operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

bool operator==(const Point& u, const Point& v);

bool operator!=(const Point& u, const Point& v);



#endif //C_POINT_H
