
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

CivilEngineer::CivilEngineer()
{
}

/* This operator is the friend of CivilEngineer class, so it should have access to anything we have in our
CivilEngineer class. But in here, the get_full_name and get_age (public part of Person class) are private in 
Engineer class (because Engineer class is the private inheritance of Person class) so we can't access them.
contract_count is private part of Engineer class, so CivilEngineer can not access it.
Even if this operator is friend of CivilEngineer class, it has access to anything in the Civil (include public,
protected and private). But, we can't call any of these members (get_full_name, get_age, contract_count ...).
*/
std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand)
{    
    //  out << "CivilEngineer [Full name : " << operand.get_full_name() <<
    //                 ",age : " << operand.get_age() << 
    //                 //",address : " << operand.get_address() <<
    //                 ",contract_count : " << operand.contract_count <<
    //                 ",speciality : " << operand.m_speciality << "]";
				
    return out;  
}


CivilEngineer::~CivilEngineer()
{
}
