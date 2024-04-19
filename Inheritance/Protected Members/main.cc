#include <iostream>
#include "player.h"


int main(){

    // Player p1("Basketball");
    // p1.set_first_name("John");
    // p1.set_last_name("Snow");
    Player p1("Basketball", "Dai", "Nguyen");

    /* This will cause compiler error, first_name here is protected member.
       So, it can not be accessed outside of the derived class and base class. */
    // p1.first_name = "Hme"; 
    std::cout << "player : " << p1 << std::endl;
   
    return 0;
}