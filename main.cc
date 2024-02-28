#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Dog 
{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();

        void set_name(const std::string void_name);
        void set_breed(const std::string breed);
        void set_age(int age);
        void get_name();

    private:
        std::string dog_name;
        std::string breed;
        int age;
};


Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    dog_name = name_param;
    breed = breed_param;
    age = age_param;
    std::cout << "Dog constructor called for: " << dog_name << "constructed at " << this << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called for: " << dog_name << " constructed at " << this << std::endl;
}

void Dog::set_name(const std::string dog_name)
{
    this->dog_name = dog_name;
}

void Dog::set_breed(const std::string breed)
{
    this->breed = breed;
}

void Dog::set_age(int age)
{
    this->age = age;
} 


void pass_by_value(Dog dog)
{
    dog.set_name("123");
    dog.get_name();
}

void pass_by_ref(Dog &dog)
{
}


void pass_by_pointer_to_non_const(Dog *dog)
{
    /* This function here is taking its parameter clearly as a non const and this
    pointer potentially modify the object -> compiler error */
}

void pass_by_pointer_to_const(const Dog *dog)
{
    /* This is not going to work because trying to modify the const object through 
    a pointer to const is not allowed */
    // dog->set_name("Hme");
    /* Like pass by const reference, the compiler doesn't know the get_name() here 
    isn't modifying the object through a pointer to const -> compiler error */
    // dog->get_name();
}

void pass_by_const_ref(const Dog &dog)
{
    /* This is going to work because the compiler know that the get_name() is never
    going to modify the object. */
    dog.get_name();
}

/* Marking the function become the const member function, this is how compiler know that
this function will never modify the object */
void Dog::get_name() const
{
    std::cout << "Dog Name: " << this->dog_name << std::endl;
    /* Can't modify anything about the class */
    this->age++; /* Not work */
}

/* It's possible to overload member function */
void Dog::get_name()
{
    std::cout << "Dog Name: " << this->dog_name << std::endl;
    this->age++; /* Work */
}

int main()
{
    Dog dog1("Hmu", "Hme", 2); /* non const object */
    pass_by_const_ref(dog1);

    /* This function receives a non const reference, so it could potentially be used
    to modify the parameter that is passed to this function and the compiler is going 
    to prevent anything from doing this. -> Compiler Error */
    // pass_by_ref(dog1);

    /* This causes no problem because this const object is passed by value
    -> the one being used here is a copy -> Do not affect to the original object */
    // pass_by_value(dog1);
     




    return 0;
}
