#include <iostream>
#include "dog.h"


void taking_dog_p(const Dog *p_dog)
{

}

int main()
{
    const Dog dog1("Fluffy", "Shepherd", 2);

    taking_dog_p(&dog1);

}


