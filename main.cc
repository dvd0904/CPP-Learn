#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Person
{
    private:
        std::string last_name{};
        std::string first_name{};
        int *age{};

    public:
        /* Constructor */
        Person() = default;
        Person(const std::string &last_name_par, const std::string &first_name_par, int age_par);
        Person(const std::string &last_name_par, const std::string &first_name_par);
        Person(const std::string &last_name_par);

        /* Copy Constructor*/
        /* Can not set a copy constructor like this (pass by value), because this is going to cause a chain
        of endless copy constructor call, because the copy constructor is going to call a copy constructor
        -> C++ designer disallowed this kind of syntax */
        // Person(const Person sourcPerson); /* BAD: Potential for an endless chain of copy constructor calls */
        Person(const Person& sourcPerson);

        /* Destructor */
        ~Person();


        /* Setters */
        void set_first_name(const std::string& first_name) {this->first_name = first_name;}
        void set_last_name(const std::string& last_name) {this->last_name = last_name;}
        void set_age(int age) {*(this->age) = age;}

        /* Getters */
        std::string get_first_name() const {return this->first_name;}
        std::string get_last_name() const {return this->last_name;}
        int *get_age() const {return this->age;}

        void print_info();

};

Person::~Person()
{
    // std::cout << "Destructor called for: " << this << std::endl;
	delete age; 
}

Person::Person(const std::string& last_name)
	: Person(last_name, "") /* Constructor delegation */
{
}
Person::Person(const std::string& last_name_param, const std::string& first_name_param)
	: Person(last_name_param, first_name_param, 0) /* Constructor delegation */
{
}
Person::Person(const std::string& last_name_param, const std::string& first_name_param, int age_param)
	: 	last_name(last_name_param), first_name(first_name_param), age(new int(age_param))
{
}

/* Copy constructor */
// Person::Person(const Person& sourcPerson)
//     : last_name{sourcPerson.get_last_name()}, first_name{sourcPerson.get_first_name()}, age{new int(*(sourcPerson.get_age()))}
// {
// }

/* Copy constructor using delegate */
Person::Person(const Person& sourcPerson)
    : Person(sourcPerson.get_first_name(), sourcPerson.get_last_name(), *(sourcPerson.get_age()))
{
}

void Person::print_info()
{
    std::cout << "Person object at: " << this 
              << " [ Last name: " << this->last_name
              << ". First name: " << this->first_name 
              << ". Age: " << *(this->age)
              << ". Age Address: " << this->age << " ]" 
              << std::endl;
}

int main()
{   

    /* The member variable "age" is a pointer */
    Person p1("John", "Snow", 25); 
    Person p2(p1); /* This line does a wise copy member variable one by one from p1 to p2 by default copy constructor */
    std::cout << "Before p1 set age.\n";
    p1.print_info();  /* Age of p1 is 25 */
    p2.print_info();  /* Age of p2 is 25 */
    p1.set_age(30); /* Set new age to p1 */
    std::cout << "After p1 set age.\n";
    p1.print_info(); /* Age of p1 is 30 */
    p2.print_info(); /* Age of p1 is 30, this is affected by p1 */


    return 0;
}
