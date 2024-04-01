#include <iostream>


int add(int a, int b)
{
    return a + b;
}

namespace
{
    int add(int a, int b)
    {
        return a + b - 1;
    }
}


int main()
{
    int res = ::add(1, 3); // 4
    std::cout << res << std::endl;
}



