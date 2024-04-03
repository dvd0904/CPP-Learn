#include <iostream>

// const int const_global_var {6}; // Internal linkage by default
// /* Here is function declaration, it can be declared here and define in another 
// translation unit */
// void func_in_other_file(); 

int external_var = 3;
// extern int external_var; 
void print_external_var();

int main()
{
    std::cout << "In main function: " << external_var 
    << " " << &external_var << std::endl; // 3 0x7ff646a38010
    print_external_var(); // 3 0x7ff646a38010


    // std::cout << "In main function: " << const_global_var << " " << &const_global_var << std::endl;
    // func_in_other_file();
}

