#include <iostream>

extern const int internal_to_external;

void printSth();

static void otherFunc();

int main()
{
    std::cout << "internal_to_external in main(): " << internal_to_external
    << " - Addr: " << &internal_to_external << std::endl;
    printSth();
    otherFunc();
}

