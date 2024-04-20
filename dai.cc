#include <iostream>
#include "dog.h"


class A
{
    public:
        int plus(int b)
        {
            static int c = 3;
            c += b;
            return c;
        }
};

int func(int a)
{
    static int x = 2;
    x += a;
    return x;
}

int main()
{

    // A obj;
    // obj.plus(2);
    // int x = obj.plus(2);
    // std::cout << x;

    int a = func(2);
    a = func(2);
    std::cout << a;

}


