#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Dog 
{
    public:
        Dog() = default; 
        /* Explicit keyword tell the compiler is to never use 
        this constructor in implicit conversions */
        explicit Dog(int param1) : param1(param1)
        {
        }

    private:
        int param1;
        int param2;
};


int main()
{   
    Dog dog1;


    return 0;
}
