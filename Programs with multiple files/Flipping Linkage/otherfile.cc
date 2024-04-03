#include <iostream>

extern const int internal_to_external{1};

void printSth()
{
    std::cout << "internal_to_external in other file: " << internal_to_external
    << " - Addr: " << &internal_to_external << std::endl;
}

/* External to internal */

// Solution 1
// static void otherFunc()
// {
//     std::cout << __FILE__ << std:: endl;
// }

// Solution 2
namespace
{
    static void otherFunc()
    {
        std::cout << __FILE__ << std:: endl;
    }
}