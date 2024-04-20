#include <iostream>
#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

int main(){

    Person person1("Daniel Gray",27,"Blue Sky St 233 #56");
    std::cout << "person1 : " << person1 << std::endl;

    std::cout << "----------------\n";

    /* Player is public inheritance of the Person class */
    Player player;
    player.m_full_name = "Nguyen Dinh Dai";
    /* m_age is protected part of base class -> Can only be accessed inside the derived class 
    -> error */
    // player.m_age = 23; 
    // player.m_address = "HaNoi"; /* m_address is private part -> Error */
   
    std::cout << "----------------\n";


    /* Nurse is the protect inheritance of the Person class */
    Nurse nurse;
    /* Error here, because m_full_name is public part of base class, but nurse is protected inheritance 
    -> m_full_name in derived class is protected -> So, it can't be accessed outside the derived class. */
    // nurse.m_full_name = "Monkey D Luf"; // Error (public -> protected)
    // nurse.m_age = 23; // Error (protected -> protected)
    // nurse.m_address = "Hanoi"; // Error (private -> private)

    std::cout << "----------------\n";

    /* Nurse is the private inheritance of the Person class */
    Engineer eng;
    // /* m_full_name is now private to the Engineer class -> Error */
    // eng.m_full_name = "Dai Nguyen";
    // // /* m_age is now private to the Engineer class -> Error */
    // eng.m_age = 23; 
    // /* m_address is private to the base class, so we can't access it from a derived class directly,
    // we can't even access that from the outside */
    // eng.m_address = "HaNoi";




    return 0;
}