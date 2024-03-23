#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Dog
{
    public:
        Dog(std::string_view dog_name, int dog_age);
        /* By doing this, now Cat class can access to private or public member variables of
           Dog class*/
        friend class Cat;
        
    private:
        std::string dog_name;
        int dog_age;
};

class Cat
{
    public:
        Cat(std::string_view cat_name);

        void show_dog_info(const Dog &dog) const 
        {
            std::cout << "dog name: " << dog.dog_name << std::endl; /* Work */
            /* Can not access directly because Cat is really not member of Dog class*/
            std::cout << "dog name: " << dog_name << std::endl; 
            /* Can not use "this" pointer of Dog class */
            std::cout << "dog name: " << this.dog_name << std::endl; 
        }

    private:
        std::string cat_name;
};

int main()
{

}