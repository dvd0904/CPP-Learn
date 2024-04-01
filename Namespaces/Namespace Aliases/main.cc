#include <iostream>


namespace level1
{
    namespace level2
    {
        namespace level3
        {
            namespace level4
            {
                int x = 4;
            }
        }
    }
}

int main()
{
    namespace alias = level1::level2::level3::level4;

    /* This is fucking crazy if there are a lot of namespaces. */
    std::cout << level1::level2::level3::level4::x << std::endl; 
    /* Good solution */
    std::cout << alias::x << std::endl;
}

