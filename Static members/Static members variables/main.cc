#include <iostream>
#include <string>
#include <string_view>
#include <cstring>
#include "point.h"

int main()
{
    /* Print the point count */
    /* m_point_count is a static member, it is not tied to any object. So, we are able to
       do this before any Point object is created. Static member variables is initialized
       even before the main function runs */
    std::cout << "Point count: " << Point::m_point_count << std::endl; // 0 
    Point p1(10, 20); 
    Point points[] {Point(1, 1), Point(), Point(2)}; /* Array of Point */
    std::cout << "Point count: " << Point::m_point_count << std::endl; // 4
    /* Can use Point::m_point_count if m_point_count is public */
}

