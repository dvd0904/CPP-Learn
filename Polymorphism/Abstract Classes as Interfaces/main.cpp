#include <iostream>
#include <memory>
#include "stream_insertable.h"
#include "animal.h"
#include "feline.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "pigeon.h"
#include "crow.h"

class Point : public StreamInsertable{
public : 
    Point() = default;
    Point(double x , double y)
        : m_x(x), m_y(y)
    {
    }
    /* If we don't implement this virtual function, Point class will become an abstract class. 
       This function here is going to be picked up by our Interface when we get call the output
       stream operator. Notice that we are calling this POLYMORPHICALLY. */
    virtual void stream_insert(std::ostream& out)const override
    {
        out << "Point [x: " << m_x << ",y: " << m_y << "]";
    }

private : 
    double m_x;
    double m_y;
};

int main(){

    Point p1(10,20);
    /* Point class DOESN"T have an output stream operator BUT we still CAN PRINT IT with std::cout. Why?
       So, this is the magic of Interfaces. We are attaching the StreamInsertable INterface to the Point 
       class and this is going to give our class the powers (that powers come from Interface), and one of 
       the powers is to use the output stream operator we get from the INTERFACE. We can even print the
       entire Inheritance Hierarchy. */
    std::cout << "p1 : " << p1 << std::endl; // Output: p1 : Point [x: 10,y: 20]
    // operator << (std::cout, p1); // This is behind the scene, the compiler is going to take the above line 
                                 // and turn that into this line here 


    std::cout << "------------" << std::endl;

    std::unique_ptr<Animal> animal0 = std::make_unique<Dog>("stripes","dog1");
    std::cout << *animal0 << std::endl;

    std::unique_ptr<Animal> animal1 = std::make_unique<Bird>("white","bird1");
    std::cout << *animal1 << std::endl;


    std::cout << "--------------" << std::endl;
    //Can even put animals in an array and print them polymorphically.
    std::shared_ptr<Animal> animals[] 
    {
        std::make_shared<Dog>("stripes","dog2"),
        std::make_shared<Cat>("black stripes","cat2"),
        std::make_shared<Crow>("black wings","crow2"),
        std::make_shared<Pigeon>("white wings","pigeon2")
    };
	std::cout << std::endl;
    std::cout << "Printing out animals array : " << std::endl;
    for(const auto& a : animals)
    {
        std::cout << *a << std::endl;
    }
    
    return 0;
}