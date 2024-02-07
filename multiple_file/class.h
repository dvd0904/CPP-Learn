#ifndef CLASS_H
#define CLASS_H


class Cylinder
{
public:
    // Cylinder();
    Cylinder() = default;
    Cylinder(double r_par, double h_par);
    double volume();

    /* Getter */
    double get_radius();
    double get_height();
    /* Setter */
    void set_radius(double r_par);
    void set_height(double h_par);

private:
    double base_radius, base_height;
};


#endif // CLASS_H