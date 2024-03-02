#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Person
{
    private:
        std::string first_name{};
        std::string last_name{};
        int *age{};

    public:
        /* Constructor */
        Person() = default;
        Person(const std::string &first_name_par, const std::string &last_name_par, int age_par);
        Person(const std::string &first_name_par, const std::string &last_name_par);
        Person(const std::string &first_name_par);

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

Person::Person(const std::string& first_name)
	: Person(first_name, "") /* Constructor delegation */
{
}
Person::Person(const std::string &first_name_par, const std::string &last_name_par)
	: Person(first_name_par, last_name_par, 0) /* Constructor delegation */
{
}
Person::Person(const std::string& first_name_param, const std::string& last_name_param, int age_param)
	:   first_name(first_name_param), last_name(last_name_param), age(new int(age_param))
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
    std::cout << "Copy constructor called for: " << this->last_name << std::endl;
}

void Person::print_info()
{
    std::cout << "Person object at: " << this 
              << " [ First name: " << this->first_name
              << ". Last name: " << this->last_name 
              << ". Age: " << *(this->age)
              << ". Age Address: " << this->age << " ]" 
              << std::endl;
}

int main()
{   
    Person p1("John1", "Snow1", 25); 
    Person p2("John2", "Snow2", 25); 
    Person p3("John3", "Snow3", 25); 
    std::cout << "-------------------\n";
    p1.print_info();
    p2.print_info();
    p3.print_info();
    std::cout << "-------------------\n";
    Person students[] = {p1, p2, p3}; /* p1, p2, p3 will be copied here */
    std::cout << "-------------------\n";
    for(Person s : students) /* s is not a reference, so s here is copied by each element in array */
        s.print_info();
    std::cout << "-------------------\n";
    for(Person &s : students) /* Avoid unnecessary copy */
        s.print_info();

    return 0;
}
