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

        Dog& set_name(const std::string &dog_name);
        Dog& set_breed(const std::string &breed);
        Dog& set_age(int age);
        void get_name();

    private:
        std::string dog_name;
        std::string breed;
        int *p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    dog_name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for: " << dog_name << "constructed at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for: " << dog_name << " constructed at " << this << std::endl;
}

void Dog::get_name()
{
    std::cout << "Dog Name: " << this->dog_name << std::endl;
}

Dog& Dog::set_name(const std::string &dog_name)
{
    this->dog_name = dog_name;
    return *this; /* Dereference and return */
}

Dog& Dog::set_breed(const std::string &breed)
{
    this->breed = breed;
    return *this;
}

Dog& Dog::set_age(int age)
{
    if(this->p_age)
    {
        *(this->p_age) = age;
    }
    return *this;
} 



int main()
{
    const Dog dog1("Hmu", "Hme", 2);

    Dog *pd = &dog1; /* Invalid conversion from const Dog* to Dog* */
    Dog &rd = dog1;  /* Can't convert from const Dog& to Dog& */

    const Dog *pcd = &dog1;
    pcd->set_name("a"); /* Compiler Error */
    pcd->get_name();    /* Compiler Error */

    const Dog &rcd = dog1;
    rcd.set_name("b");  /* Compiler Error */
    rcd.get_name();     /* Compiler Error */
     




    return 0;
}
