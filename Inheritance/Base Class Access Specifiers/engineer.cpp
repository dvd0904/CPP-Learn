#include "person.h"
#include "engineer.h"
#include <iostream>

Engineer::Engineer()
{
}


/* A friend of class can access to all part (public, protect, private) of class
this operator function here is in the derived class (private inheritance) of Person.
So, all part of Person class is private in derived class (Engineer) -> this friend function
can access to them.
*/
std::ostream& operator<<(std::ostream& out , const Engineer& operand)
{
     out << "Engineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count << "]";
    return out;   
}


Engineer::~Engineer()
{
}


