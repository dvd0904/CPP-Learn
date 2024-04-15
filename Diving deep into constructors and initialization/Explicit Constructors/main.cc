#include <iostream>
#include "square.h"

//Is square1 > to square2 ? true or false
bool compare( const Square& square1 ,const Square& square2)
{
    return (square1.surface() > square2.surface()) ? true : false;
}

int main(){

    Square s1(100.0);
    Square s2(20.0);

    std::cout << std::boolalpha;
    std::cout << "s1 > s2 : " << compare(s1,s2) << std::endl; // false

    //Implicit conversions
    // 45.9 Implicit converted to Square(45.9). But if the constructor is explicit,
    // this will cause compiler error. Because Explicit keyword don't allow the constructor
    // set up an implicit conversion.
    std::cout << "s1 > 45.9 : " << compare(s1,45.9) << std::endl; // false


   
    return 0;
}