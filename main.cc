#include <iostream>
#include <string>

template <typename TEMP> 
TEMP func(TEMP a, TEMP b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 5, b = 6;
    double c = 4.6, d = 5.3;
    std::string e{"dai"}, f{"nguyen"};
    func(a, b); /* int type deduction */
    func(c, d); /* double type deduction */
    func(e, f); /* string type deduction */

    func<double>(c, d); /* Explicit say that use the double type */
    func<double>(a, c); /*  a and c are not the same type but it's work. There is an 
                            implicit conversion from int to double for the first parameter. */
    func<double>(a, e); /* Error: can not convert std::string to double (second parameter) */

    return 0;
}

