#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>
class Person
{
    friend std::ostream& operator<<(std::ostream& , const Person& person);
public:
    Person() ;
    Person(std::string_view fullname, int age, const std::string address);
    ~Person();
    
public:
    std::string m_full_name{"None"};
protected: 
    int m_age{0};
private : 
    std::string m_address{"None"};
};


#endif // PERSON_H