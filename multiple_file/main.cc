#include <iostream>
#include "class.h"

int main()
{
    // Cylinder c1;
    Cylinder cy1(2, 3); 
    std::cout << cy1.volume() << "\n";

    /* Manage a stack object through pointer */
    Cylinder *cy2 = &cy1;
    std::cout << cy2->volume() << "\n";

    /* Create a heap object */
    Cylinder *cy3 = new Cylinder(1, 1); /* Heap object */
    std::cout << cy3->volume() << "\n"; 
    delete cy3;


}