#include <iostream>
namespace ABC
{
    void func1()
    {
        std::cout << 1;
    }
    static void func2()
    {
        std::cout << 2;

    }
};

int main()
{
    ABC::func1();
    ABC::func2();

}


