#include <iostream>
 
class Person
{
public:
    Person(const std::string &names_param, int age_param);
    void print_info() const
    {
        std::cout << "name : " << full_name << " , age : " << age << std::endl;
    }
 
private:
    std::string full_name;
    int age;
 
public:
    static int person_count;
};
 
int main()
{
    Person p1("John",22);
    std::cout << "The sky is blue" << std::endl;
    return 0;
}