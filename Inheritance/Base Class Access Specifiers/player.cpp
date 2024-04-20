#include "person.h"
#include "player.h"
#include <iostream>

Player::Player()
{
}

/* A friend of class can access to all part (public, protect, private) of class
this operator function here is in the derived class (public inheritance) of Person.
So, all the public part of base class is public in derived class -> this friend function
can access to them.
*/
std::ostream& operator<<(std::ostream& out, const Player& player)
{    
    out << "Player[Full name : " << player.get_full_name() <<
                    ",age : " << player.get_age() << 
                    ",address : " << player.get_address() << "]";
    return out;
}


Player::~Player()
{
}