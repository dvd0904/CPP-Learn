#include <iostream>

int func(int a, int b)
{
    /* this function here is in default global namespace */
    return a + b - 1;
}

namespace myNamespace
{
    int func(int a, int b)
    {
        return a + b;
    }

    void doSth()
    {
        int inside = func(3, 4); /* Call a function inside namespace */
        int outside = ::func(3, 4); /* Call a function outside namespace */
        std::cout << "inside: " << inside << std::endl;  // 7
        std::cout << "outside: " << outside << std::endl; // 6
    }
}

int main()
{
    /* These syntax below is the same thing */
    ::myNamespace::doSth();
    myNamespace::doSth();
}   