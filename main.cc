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

        const std::string& dangling_ref() const;
        const int *dangling_pointer() const;

    private:
        std::string dog_name;
        std::string breed;
        int age;
        /* We can not modify anything inside a const member function but if we need to
        modify something => use mutable */
        mutable int count;
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

void Dog::get_name()
{
    std::cout << "Dog Name: " << this->dog_name << std::endl;
    this->age++; /* Work */
}

const std::string& Dog::dangling_ref() const 
{
    std::string ret = "konichiwa";
    return ret; 
    /* At this moment, ret is wiped out from memory because it's local stack object and 
    the reference that is returned here might stay there long after this function is done 
    executing. So, trying to use this reference somewhere later might cause errors */
} 

const int * Dog::dangling_pointer() const
{
    int a = 10;
    return &a;
    /* At this moment, we have a pointer to a variable that is really dead */
}

struct Point
{
    double x;
    double y;
};

int main()
{

    Point point1 {1.2, 3.4};
    /* To use structured bindings, the member variables must be public */
    auto [a, b] = point1; /* a and b are just copies*/

    /* Capturing a structured binding in a lambda function (only in C++ 20) */
    auto func = [a]()
    {
        std::cout << "Have captured: " << a << std::endl; 
    };
    func();










    return 0;
}
