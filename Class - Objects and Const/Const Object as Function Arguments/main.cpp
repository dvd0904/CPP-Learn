#include <iostream>
#include "dog.h"

/*This causes no problem because we are working with a copy inside the function */
void function_taking_dog(Dog dog)
{
	dog.set_name("Internal dog");
	dog.print_info();
}

//Parameter by reference
void function_taking_dog_ref(Dog& dog_ref)
{
	//Compiler won't allow passing const object as argument
}

//Parameter by const reference
void function_taking_const_dog_ref(const Dog& const_dog_ref)
{
	// const_dog_ref.set_name("Hillo"); // Compiler Error 
	// const_dog_ref.print_info();  // Compiler Error 

}

//Pointer to non const as parameter
void function_taking_dog_p(Dog* p_dog)
{
	//Compiler won't allow passing const Dog objects as arguments
}

//Parameter passed as pointer to const
void function_taking_pointer_to_const_dog(const Dog* const_p_dog)
{
	// const_p_dog->set_name("Hillo"); // Compiler Error 
	// const_p_dog->print_info(); // Compiler Error 
}


int main(){

    const Dog dog1("Fluffy","Shepherd",2);
    std::cout << "address of object : " << &dog1 << std::endl;

    // Function taking parameter by value : WORKS
    // function_taking_dog(dog1);

    /* This cause compiler error, because if compiler allow this behavior to compile,
    the parameter is non const reference and it can be used to modify the data of const object. */
    // function_taking_dog_ref(dog1); // Compiler error in this line

    /* This is allowed to compile because the parameter of this function is const reference and this 
    const reference is going to protect the const Dog object as argument here (because we can't go through 
    it and modify the object.) */
    /* But this can cause compiler error because inside the function, we call the method that can be used to
    modify the const object. */
    // function_taking_const_dog_ref(dog1);  // Compiler error inside the function

    /* This is the same as taking by reference because the parameter is a pointer -> you can use this pointer
    to modify the const object. */
    // function_taking_dog_p(&dog1); // Compiler error in this line

    /* This is the same as taking by pointer to reference, compiler allow this line to compile because the 
    parameter is a pointer to const, so it can protect the cont Dog object from modifying the data. But the 
    compiler error occur inside this function because we call the methods that can be used to modify the data
    of const object. */
    function_taking_pointer_to_const_dog(&dog1); // Compiler error inside the function


    return 0;
}