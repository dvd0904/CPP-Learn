#include <iostream>


void print_age_1();
void print_age_2();

void print_distance_1();
void print_distance_2();

int main(){

    /* Addresses here are in the same memory address */
    print_age_1(); 
    print_age_2();

    std::cout << "----" << std::endl;

    /* Addresses here are in different memory address */
    print_distance_1();
    print_distance_2();
   
    return 0;
}