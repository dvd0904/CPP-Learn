#include "class.h"
#include "defs.h"
#include <iostream>

// Cylinder::Cylinder()
// {
//     std::cout << "con me no\n";
// }

Cylinder::Cylinder(double radius, double height)
{
    std::cout << "Constructor is called\n";
    base_height = height;
    base_radius = radius;
}

double Cylinder::volume()
{
    return PI * base_height * base_radius * base_radius;
}

void Cylinder::set_height(double height)
{
    base_height = height;
}

void Cylinder::set_radius(double radius)
{
    base_radius = radius;
}

double Cylinder::get_height()
{
    return base_height;
}

double Cylinder::get_radius()
{
    return base_radius;
}

