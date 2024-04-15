
#include <iostream>
#include "point.h"
class Number
{
    friend std::ostream& operator<<(std::ostream& out , const Number& number);

    //Arithmetic operators
    friend Number operator+(const Number& left_operand, const Number& right_operand);
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);
		
public:
	Number() = default;
	Number(int value );

    /* Type conversion. Can only be done as member function */
    // Don't need to put the return type here
    explicit operator double()const
    {
        std::cout << "Using type conversion from Number to double\n";
        return (static_cast <double> (m_wrapped_int));
    }

    explicit operator Point() const
    {
        std::cout << "Custom conversion from Number to Point" << std::endl;
        return Point(static_cast<double>(m_wrapped_int),
                        static_cast<double>(m_wrapped_int));
    }

    /* Don't use explicit */
    // operator double()const
    // {
    //     std::cout << "Using type conversion from Number to double\n";
    //     return (static_cast <double> (m_wrapped_int));
    // }
    // operator Point() const
    // {
    //     std::cout << "Custom conversion from Number to Point" << std::endl;
    //     return Point(static_cast<double>(m_wrapped_int),
    //                     static_cast<double>(m_wrapped_int));
    // }
 
    //getter
    int get_wrapped_int() const
    {
        return m_wrapped_int;
    }
     
    ~Number();
    
private : 
    int m_wrapped_int{0};
};