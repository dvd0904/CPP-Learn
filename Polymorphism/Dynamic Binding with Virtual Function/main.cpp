#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_shape(Shape * s);
void draw_shape_v1(const Shape& s_r);


int main(){

    Shape shape1("Shape1");
    //shape1.draw();
    Oval oval1(2.0,3.5,"Oval1");
    //oval1.draw();
    Circle circle1(3.3,"Circle1");
    //circle1.draw();

    //Base pointers (the same with base reference)
    /* With virtual function, we are telling the compiler that don't look at the type of the base pointer
    instead look at THE TYPE OF ACTUAL OBJECT THAT THE POINTER IS MANAGING. This is the same with base
    reference. */
    Shape * shape_ptr = &shape1;

    /* Expect: Shape::draw() call
       Output: Shape::draw() called. Drawing Shape1 -> true */
    // shape_ptr->draw(); 

    /* Expect: Oval::draw() call
       Output: Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5 -> true */
    shape_ptr = &oval1;
    // shape_ptr->draw();

    /* Expect: Oval::draw() call
       Output: Circle::draw() called. Drawing Circle1 with radius : 3.3 -> true */
    shape_ptr = &circle1;
    // shape_ptr->draw(); 

    //Base references
    Shape& shape_ref = circle1;
    // shape_ref.draw(); // Circle::draw()

    // Drawing Shape (we can use these function to draw any kind of shape in our Inheritance Hierarchy)
    // draw_shape(&oval1);
    // draw_shape_v1(circle1);

    // Raw pointers
    shape_ptr = &oval1;
    /* Suppose get_x_rad() is the public method of Oval object and we want to call this get_x_rad() method 
    by using dynamic binding, we mark this method as virtual function. So, this behavior cause compiler 
    error. If we don't mark this method as virtual, static binding is going to use by default, the compiler
    will look at the type of base pointer (in this case is Shape) and Shape class doesn't have any method 
    called get_x_rad() -> compiler error */
    // shape_ptr->get_x_rad();


    //Shapes stored in collections
    Shape* shape_collection[]{ &shape1, &oval1, &circle1 }; 
    for(Shape* s_ptr : shape_collection)
        s_ptr->draw();


    return 0;
}

void draw_shape(Shape * s)
{
    s->draw();
}

void draw_shape_v1(const Shape& s_r)
{
    s_r.draw();
}
