#include "person.h"
#include <iostream>

Person::Person(){
    std::cout << "Default constructor for Person called..." << std::endl;
}

Person::Person(std::string_view fullname, int age,
    const std::string address) 
        : m_full_name{fullname}, m_age{age},
            m_address{address}
{
}


Person::~Person()
{
}


