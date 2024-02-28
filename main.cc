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

        const std::string& dog_info() const;

    private:
        std::string dog_name;
        std::string breed;
        int age;
};

const std::string& Dog::dog_info() const 
{
    std::string a = "con me no";
    return a;
}


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

int main()
{
    Dog dog1("Hmu", "Hme", 2); 

    const std::string &str_ref = dog1.dog_info();
    std::cout << str_ref;




    return 0;
}
