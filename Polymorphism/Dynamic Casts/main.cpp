#include <iostream>
#include "dog.h"


void do_something_with_animal_ptr(Animal* animal)
{
	std::cout<< "In function taking base pointer..." << std::endl;
	Feline* feline_ptr = dynamic_cast<Feline*>(animal);
	
	if(feline_ptr)
		feline_ptr->do_some_feline_thingy();
	else
		std::cout << "Couldn't cast to Feline pointer,Sorry." << std::endl;
}

void do_something_with_animal_ref(Animal & animal)
{
	std::cout << "In function taking base reference..." << std::endl;
	Feline* feline_ptr_1 {dynamic_cast<Feline*>(&animal)};
	if(feline_ptr_1)
		feline_ptr_1->do_some_feline_thingy();
	else
		std::cout << "Couldn't cast to Feline reference,Sorry." << std::endl;
}

int main()
{

	//Base class pointer
	Animal* animal1 = new Feline("stripes","feline1"); /* Don't have Dog information in this Feline object */
	// animal1->do_some_feline_thingy(); // Befor use dynamic casts -> Fail

	//If the cast succeeds, we get a valid pointer back, 
	//if it fails, we get nullptr. So we can check before
	//calling stuff on the returned pointer
	// Dog* dog_ptr = dynamic_cast<Dog*>(animal1); // Work

    // if(dog_ptr)
    //     dog_ptr->do_some_feline_thingy();
    // else
    //     std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl; // This will print

	// Feline* feline_ptr = dynamic_cast<Feline*>(animal1); // Work

	// if(feline_ptr)
    //     feline_ptr->do_some_feline_thingy();
    // else
    //     std::cout << "Couldn't do the transformation from Animal* to Feline*" << std::endl; // This will print

    // std::cout << "-----------" << std::endl;


    //Can do the transformation downstream for references

	//Base class reference
	Feline feline2 ("stripes", "feline2");
	Animal & animal_ref = feline2;
	
	//Calling non virtual methods on animal_ref won't work
	// animal_ref.do_some_feline_thingy(); // Before casting: Fail
	
	// Feline & feline_ref {dynamic_cast<Feline&>(animal_ref)}; // Work
	// Feline  *feline_ptr {dynamic_cast<Feline*>(&animal_ref)}; // Work
	// if(feline_ptr)
	// 	feline_ptr->do_some_feline_thingy(); // This line will print
	// else
	// 	std::cout << "Couldn't cast to Dog reference, Sorry." << std::endl; 

    //Doing proper checks with references
	// Dog* dog_ptr {dynamic_cast<Dog*>(&animal_ref)}; // work at run time -> crash
	// if(dog_ptr)
	// 	dog_ptr->do_some_dog_thingy();
	// else
	// 	std::cout << "Couldn't cast to Dog reference, Sorry." << std::endl; // This line will print
	


    // std::cout << "---------------" << std::endl;
    do_something_with_animal_ptr(animal1);
    do_something_with_animal_ref(animal_ref);
	
	delete animal1;

    std::cout << "----------------" << std::endl;

	/* The output: data_str and the input data_ptr are not in the same polymorphic inheritance hierarchy.
	-> can not use dynamic cast with them. */
    // int data{45};
    // int *data_ptr = &data;
    // std::string data_str = dynamic_cast<std::string *>(data_ptr);
    

    std::cout << "Done!" << std::endl;

    return 0;
}