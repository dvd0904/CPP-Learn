#include <iostream>
#include <string>
#include <cstring>

#define PI 3.14

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double r_par, double h_par)
    {
        r = r_par;
        h = h_par;
    }

    double volume()
    {
        return PI * r * r * h;
    }

    /* Getter */
    double get_radius()
    {
        return r;
    }
    double get_height()
    {
        return h;
    }
    /* Setter */
    void set_radius(double r_par)
    {
        r = r_par;
    }
    void set_height(double h_par)
    {
        h = h_par;
    }

private:
    double r, h;
};

int main()
{
    Cylinder cylinder1(2, 3);
    std::cout << "base radius: " << cylinder1.get_radius() << "\n";
    std::cout << "Volume: " << cylinder1.volume() << "\n";

    cylinder1.set_radius(5);
    std::cout << "base radius: " << cylinder1.get_radius() << "\n";
    std::cout << "Volume: " << cylinder1.volume() << "\n";




    return 0;
}
