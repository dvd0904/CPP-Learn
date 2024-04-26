#include <iostream>
#include "dog.h"


int main()
{

    /* Non const */
    // Dog dog1("Fluffy","Shepherd",2);
    // dog1.print_info(); 
    // dog1.set_name("Milou");
    // dog1.print_info();

    /* const */
    // Direct access

    const Dog dog2("Fluffy", "Shepherd", 2);
    // dog2.set_name("Milou"); // Compiler error because can not modify the variable of const object 
    
    /* The print_info does not work even if it just read the data and no modify the data, but the
    the compiler doesn't know and there is nothing to tell the compiler that you don't modify the 
    data, then the compiler will prevent this behavior.
    */
    // dog2.print_info(); // Compiler error.

    // Pointer to non const
    /* You can go through the pointer to modify the data -> compiler prevent this behavior. */
    // Dog *p_dog = &dog2; // error: invalid conversion from 'const Dog*' to 'Dog*'

    // Non const reference
    /* You could go through this reference to modify this object -> compiler prevent this behavior. */
    // Dog &dog_ref = dog2; // error: binding reference of type 'Dog&' to 'const Dog' discards qualifiers

    // Pointer to const 
    /* You can go through the pointer to modify the data -> compiler prevent this behavior. */
    // const Dog *const_dog_p = &dog2;
    // const_dog_p->set_name("Milou"); // Compiler error
    // const_dog_p->get_name(); // Compiler error

    // Const reference
    /* You could go through this reference to modify this object -> compiler prevent this behavior. */
    // const Dog& const_dog_ref = dog2;
    // const_dog_ref.set_name("Molou"); // Compiler error 
    // const_dog_ref.get_name(); // Compiler error 



    return 0;
}