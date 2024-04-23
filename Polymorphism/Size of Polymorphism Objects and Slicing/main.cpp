#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(){

    //Comparing object sizes
    /* With dynamic binding, the objects are going to be much larger because the compiler has to keep track of the information 
    that allows it to dynamically resolve virtual function. So, YOU ARE NOT USING POLYMORPHISM FOR FREE. */
    // std::cout << "sizeof(Shape) : " << sizeof(Shape) << std::endl; // using virtual : 40 | non virtual: 32
    // std::cout << "sizeof(Oval) : " << sizeof(Oval) << std::endl; // using virtual : 56 | non virtual: 48
    // std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl; // using virtual : 56 | non virtual: 48



    //Slicing
    Circle circle1(3.3,"Circle1");
    /* In Inheritance Hierarchy, the circle object is larger than shape object, but this assignment still work.
    Because the compiler is going to slice off Circle and Oval information. */
    Shape shape = circle1;
    /* NOTE: In here, we don't use base pointer or base reference. So, It's not Dynamic Polymorphism here.
    The compiler just slicing the Oval and Circle information */
    shape.draw(); //Shape::draw is called not Circle::draw()

    return 0;
}