#ifndef NURSE_H
#define NURSE_H

#include "person.h"

//Nurse will do protected inheritance
class Nurse : protected Person
{
	friend std::ostream& operator<<(std::ostream& , const Nurse& operand);
public:
	Nurse();
	~Nurse();
	
    /* Protected Inheritance */
    void treat_unwell_person()
    {
        m_full_name = "John Snow"; // public -> OK
        m_age = 23; // protected -> OK
        // m_address = "897-78-723"; // private -> Compiler error
    }
    
private : 
    int practice_certificate_id{0};
};

#endif // NURSE_H
