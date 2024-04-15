#include <iostream>
#include "point.h"
#include "number.h"


double sum(double a, double b)
{
    return a + b;
}

void use_point(const Point& p)
{
    std::cout << "Printing the point from use_point func : " << p << std::endl;
}

int main()
{
    Number n1(22);
    Number n2(10);

    /* We want the code like this work, so we need to transform number to point and number
    to double otherwise we cause a compiler error */
    // double a = sum(n1, n2);
    // use_point(n1);
    /* After transform by using type conversion operator, this code works properly. But it is
    going to cause compile error if the operator use explicit keyword */
    


    /* If we use explicit keyword, we need to use explicit conversion like here, because compiler
    does not allow you to use implicit conversion in this case. */
    double result = sum(static_cast<double>(n1),static_cast<double>(n2));
    std::cout << "result : " << result <<  std::endl;
    use_point(static_cast<Point>(n1));

    return 0;
}