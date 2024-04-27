#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Point
{
    private:
        double* x{};
        double* y{};

        void invalidate()
        {
            x = nullptr;
            y = nullptr;
        }

    public:
        Point() = default;
        Point(double x_par, double y_par);
        ~Point();

        /* Copy constructor */
        Point(const Point& srcPoint);

        /* Move constructor */
        Point(Point&& srcPoint);

        void set_x(double x) {*(this->x) = x;}
        void set_y(double y) {*(this->y) = y;}

        double* get_x() const {return this->x;}
        double* get_y() const {return this->y;}

        double* steal_x();
        double* steal_y();

        void print_info() const;

};

Point::Point(double x_par, double y_par)
    : x{new double(x_par)}, y{new double(y_par)}
{
    std::cout << "Point constructed at: " << this << std::endl;
}

/* Copy constructor */
Point::Point(const Point& srcPoint)
    : x(new double(*(srcPoint.get_x()))), y(new double(*(srcPoint.get_y())))
{
    std::cout << "Copy constructor called for: " << this << "\n";
}

/* Move constructor: solution1 */
Point::Point(Point&& srcPoint)
    : x(srcPoint.get_x()), y(srcPoint.get_y())
{
    srcPoint.invalidate(); /* this method assigns the pointer to nullptr */
    std::cout << "Move constructor called." << "\n";
}

/* Move constructor: solution2 */
// Point::Point(Point&& srcPoint)
//     : x(srcPoint.steal_x()), y(srcPoint.steal_y())
// {
//     std::cout << "Move constructor called." << "\n";
// }


Point::~Point()
{
    delete this->x;
    delete this->y;
} 

double* Point::steal_x()
{
    double *new_x = x;
    x  = nullptr;
    return new_x;
}
double* Point::steal_y()
{
    double *new_y = y;
    y = nullptr;
    return new_y;
}

void Point::print_info() const
{
    std::cout << "Point [ x: " << *(this->x) << ", y: " << *(this->y) << " ]" << std::endl;
}

int main()
{   

    // Point p1(10, 15);
    // p1.print_info();

    /* Create a copy from a temporary */
    /* "std::move": force the compiler to treat the parameter is passed as a temporary, telling
    the compiler that "the parameter is going to be destroyed anyway, steal from it if you can". */
    /* By this way, the copy constructor is still called. But we don't really want to use a copy 
    constructor here because it is going to do a lot of work (allocate new memory location, copy data,...).

    We are using std::move, so this parameter here is a temporary object and it's going to be thrown 
    away. So why not steal data that is inside the temporary to avoid doing a lot of work? This is going
    to become attractive if the pointers we have in our member variables are pointing to something really 
    large, because allocating or copying from it is not good. So, we can steal it if we can to avoid all 
    that hard work. WE NEED TO DO THAT THROUGH A MOVE CONSTRUCTOR */
    Point p2(std::move(Point(20, 35))); 
    p2.print_info();



    return 0;
}
