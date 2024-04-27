#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main()
{
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");

    // Shape shape("hehe");
    // shape.draw(33);

    oval1.draw();
    oval1.draw(44); 

    circle1.draw();
    circle1.draw(33);

    Shape *shape_p = new Circle(10, "circle2");

    shape_p->draw(33);

    delete shape_p;
    
    return 0;
}





