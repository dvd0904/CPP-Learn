#include <iostream>
#include "point.h"

int main()
{ 
    Point p1(1, 2); // The constructor with 2 parameters is used normally.
    p1.print_info();

    Point p2; // The constructor with no parameter is delete -> can not use.
    Point p3(p1); // The copy constructor is deleted -> can not use
    Point p4(std::move(Point(2, 4))); // The move constructor is deleted -> can not use


    return 0;
}