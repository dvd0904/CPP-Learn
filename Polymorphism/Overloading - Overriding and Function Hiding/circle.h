#ifndef CIRCLE_H
#define CIRCLE_H
#include "oval.h"


class Circle : public Oval
{
public:
    Circle() = default;
    Circle(double radius,std::string_view description);
    ~Circle();
    
 
    virtual void draw() const override
    {
        std::cout << "Circle::draw() called. Drawing " << m_description <<
            " with radius : " << get_x_rad() << std::endl;        
    }

    virtual void draw(int color_depth) const override
    {
		std::cout << "Circle::Drawing with color depth : " << color_depth << std::endl;
	}
  

};

#endif // CIRCLE_H
