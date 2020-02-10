#include <iostream>
#include "Triangle.h"
#include "Segment.h"
#include "Point.h"
#include "cassert"
#include "cmath"

using namespace std;

int main() {

    Triangle triangle1(0, 0, 0, 2, 3, 0);
    cout << triangle1 << endl;

    double sideA = sqrt(pow(triangle1.length_b(), 2) + pow(triangle1.length_c(), 2));
    assert(triangle1.length_a() == sideA);
    assert(triangle1.length_b() == 3);
    assert(triangle1.length_c() == 2);
    assert(triangle1.perimeter() == (sideA + triangle1.length_b() + triangle1.length_c()));
    assert(triangle1.area() == sqrt(triangle1.perimeter() / 2 * (triangle1.perimeter() / 2 - triangle1.length_a()) *
                                    (triangle1.perimeter() / 2 - triangle1.length_b()) *
                                    (triangle1.perimeter() / 2 - triangle1.length_c())));

    Point apexA(2, 2);
    Point apexB(0, 0);
    Point apexC(0, 4);
    Triangle triangle2(apexA, apexB, apexC);
    assert(triangle2.apexA() == apexA);
    assert(triangle2.apexB() == apexB);
    assert(triangle2.apexC() == apexC);

    triangle2 = triangle1;
    assert(triangle2.perimeter() == triangle1.perimeter());

    assert(triangle2.median_a().start() == Triangle::Segment(Point(0, 0), Point(1.5, 1)).start());
    assert(triangle2.median_a().end() ==  Triangle::Segment(Point(0, 0), Point(1.5, 1)).end());

    return 0;
}