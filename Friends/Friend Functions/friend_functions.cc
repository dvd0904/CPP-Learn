#include <iostream>
#include <string>
#include <string_view>
#include <cstring>


class FRIEND
{
    public:
        friend void func(const FRIEND &f);
        friend void func2();

    private:
        int private_var {4};
};

/* Now, these functions are work because they are friend functions, so they can access 
   anything from FRIEND class */
void func(const FRIEND &f)
{
    std::cout << f.private_var << std::endl;
}

void func2()
{
    FRIEND f;
    std::cout << f.private_var << std::endl;
}


int main()
{
    FRIEND f1;
    func(f1);
    func2();
}