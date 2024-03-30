#include <iostream>

namespace test
{
    int add(int x);
}

namespace test
{
    int add(int x)
    {
        return x * 2;
    }
}

namespace test2
{
    int sub(int x);
}

namespace test2
{
    int sub(int x)
    {
        return x / 2;
    }
}

int main()
{
    int a = test::add(2);
    std::cout << a;
}



