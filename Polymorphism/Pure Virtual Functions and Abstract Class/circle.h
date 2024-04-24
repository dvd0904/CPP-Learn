#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius , std::string_view  description);
    virtual ~Circle()= default;
    

    /* perimeter() and surface() are the pure virtual function from base class. The derived lass are 
    forced to override and implement all this pure virtual functions from the base class that they
    inherit from. Example: you don't implement the surface() here, this Circle class will become
    an abstract class and you won't be able to create object of Circle. */
    virtual double perimeter() const 
    {
        return (2 * PI * m_radius);
    }
    virtual double surface() const 
    {
        return PI * m_radius* m_radius;
    }

    
private: 
    double m_radius{0.0};
    
    inline static double PI{3.14159265};
};

#endif // CIRCLE_H
