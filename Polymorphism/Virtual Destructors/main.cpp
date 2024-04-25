#include <iostream>
#include "dog.h"

int main()
{
    /* Dog is in Inheritance Hierarchy. Dog is the derived class of Feline and Feline is the
    derived class of Animal. The order of destructor call: Dog -> Feline -> Animal */
    // Dog dog;


    /* Use pointer to manage the derived classes */
    Animal *animal = new Dog;
    delete animal;
    /* After use virtual */
    /* Output: 
        Dog destructor called
        Feline destructor called
        Animal destructor called
    */
    



    return 0;
}