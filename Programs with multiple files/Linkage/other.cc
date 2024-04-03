#include <iostream>

// Declaration of some variable defined in some other
// translation unit.
extern int external_var; 
// int external_var = 3;
void print_external_var()
{
    std::cout << "In print_external_var function: " 
    << external_var << " " << &external_var << std::endl;
}


const int const_global_var {6};

void func_in_other_file()
{
    std::cout << "In func_in_other_file function: " << const_global_var << " " << &const_global_var << std::endl;
}









