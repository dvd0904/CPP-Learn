#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

#define PI 3.14

// class Dog 
// {
//     public:
//         Dog() = default;
//         Dog(std::string_view name_param, std::string_view breed_param, int age_param);
//         ~Dog();

//         Dog& set_name(const std::string &dog_name);
//         void get_name();
//         Dog& set_breed(const std::string &breed);
//         Dog& set_age(int age);

//     private:
//         std::string dog_name;
//         std::string breed;
//         int *p_age{nullptr};
// };

// Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
// {
//     dog_name = name_param;
//     breed = breed_param;
//     p_age = new int;
//     *p_age = age_param;
//     std::cout << "Dog constructor called for: " << dog_name << "constructed at " << this << std::endl;
// }

// Dog::~Dog()
// {
//     delete p_age;
//     std::cout << "Dog destructor called for: " << dog_name << " constructed at " << this << std::endl;
// }

// void Dog::get_name()
// {
//     std::cout << "Dog Name: " << this->dog_name << std::endl;
// }

// Dog& Dog::set_name(const std::string &dog_name)
// {
//     this->dog_name = dog_name;
//     return *this; /* Dereference and return */
// }

// Dog& Dog::set_breed(const std::string &breed)
// {
//     this->breed = breed;
//     return *this;
// }

// Dog& Dog::set_age(int age)
// {
//     if(this->p_age)
//     {
//         *(this->p_age) = age;
//     }
//     return *this;
// } 

class test
{
    void do_sth()
    {

    }

    void print_sth()
    {

    }

    private:
        int x;
        std::string hme{"Dai"};
};

struct Dai
{
    std::string x;
    int a;
};


int main()
{
    // Dog dog1;
    // dog1.set_name("Hu").set_breed("Hi").set_age(2);

    // test test1;
    // std::cout << sizeof(test1) << std::endl;
    Dai dai;
    std::cout << sizeof(dai);


    return 0;
}
