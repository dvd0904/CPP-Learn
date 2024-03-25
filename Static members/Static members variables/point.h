#ifndef POINT_H
#define POINT_H

#include <iostream>


class Point
{
    public:
    /* Constructors */
    Point(double x, double y);
    Point (double xy_coord); 
    Point();
    Point(const Point &point); /* Copy constructor */
    ~Point(); /* Destructor */
    double length() const; /* Calculate distance */

    size_t get_point_count() const
    {
        ++m_point_count;
        return m_point_count;
    }

    void print_info() const 
    {
        std::cout << "Point [ &m_y: " << &m_x << ", &m_y: " << &m_y << " ]" << std::endl;
    }

    private:
        double m_x;
        double m_y;

    public:
        /* Can not initialize a static member like this */
        // static size_t m_point_count{}; /* Error */
        static size_t m_point_count;



};

#endif