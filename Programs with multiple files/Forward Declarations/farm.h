#ifndef FARM_H
#define FARM_H

#include "dog.h" // Include -> waste compile time
// class Dog; // Forward declaration

class Farm
{
public:
	Farm();
	~Farm();

    // Doesn't require the definition of Dog object because we don't use it in the header file
	void use_dog(const Dog& dog_param); 

    void do_something(const Dog& dog_param)
    {
        /* Forward declaration won't work here, if you want to use it, you need to include dog header file */
        dog_param.print_info(); 
    }
private : 
    /* Forward declaration won't work here, if you want to use it, you need to include dog header file */
    Dog dog_member; 
};

#endif // FARM_H
