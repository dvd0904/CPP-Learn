#include <iostream>

namespace Outer
{
    int outer_var = 1;

    namespace Inner
    {
        int inner_var = 2;

        void printSth()
        {
            /* Inner namespace can directly access the outer variable without 
            specifying the outer namespace name. */
            std::cout << "Outer: " << outer_var << std::endl;
            std::cout << "Inner: " << inner_var << std::endl;
        }
    }

    void doSth()
    {
        std::cout << "Outer: " << outer_var << std::endl;
        /* Outer can not directly access to the inner variable, 
        it must access through Inner namespace name. */
        std::cout << "Inner: " << Inner::inner_var << std::endl;
    }
}

int main()
{
    Outer::doSth();
    Outer::Inner::printSth();
}