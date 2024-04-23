#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"


void draw_circle(const Circle &circle);
void draw_oval(const Oval &oval);

int main()
{


    Shape shape1("Shape1");
    // shape1.draw();
    
    Oval oval1(2, 3, "Oval1");
    // oval1.draw();

    Circle cir1(3, "Circle1");
    // cir1.draw();

    /* Base pointer */
    Shape *shape_ptr = &shape1;
    // shape_ptr->draw();
    shape_ptr = &oval1;
    /* What we want: Oval::draw() is called 
       What is actually called: shape::draw() 
       So, this is called default behavior we get and this is static binding. What the compiler is going to do here, it's
       going to look at the type of pointer that we have (Shape)
       */
    // shape_ptr->draw(); // Output: Shape::draw() called. Drawing Oval1
    shape_ptr = &cir1;
    // shape_ptr->draw(); // Output: Shape::draw() called. Drawing Circle1

    /* Base Reference */
    Shape &shape_ref = shape1;
    // shape_ref.draw();
    shape_ref = oval1;
    // shape_ref.draw(); // Shape::draw() called. Drawing Oval1
    shape_ref = cir1;
    // shape_ref.draw(); // Shape::draw() called. Drawing Circle1

    /* Drawing Shape */
    // This is work but it's a bad design
    draw_circle(cir1); // Circle::draw() called. Drawing Circle1 with radius : 3
    draw_oval(oval1); // Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3

    //Shapes stored in collections
    Circle circle_collection[]{cir1,Circle(10.0,"Circle2"),Circle(20.0,"Circle3")};
    Oval oval_collection[]{oval1,Oval(22.3,51.1,"Oval2")};
    //More arrays as you have more shape types, 100? Messy right?

    return 0;
}

void draw_circle(const Circle &circle)
{
    circle.draw();
}

void draw_oval(const Oval &oval)
{
    oval.draw();
}


