#include "person.h"
#include "nurse.h"
#include <iostream>
Nurse::Nurse()
{
}


/* A friend of class can access to all part (public, protect, private) of class
this operator function here is in the derived class (protected inheritance) of Person.
So, public and protected part of Person class is protected in derived class (Nurse) -> this friend function
can access to them.
*/
std::ostream& operator<<(std::ostream& out , const Nurse& operand)
{
    out << "Nurse [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",practice certificate id : " << operand.practice_certificate_id << "]";
    return out;
}


Nurse::~Nurse()
{
}