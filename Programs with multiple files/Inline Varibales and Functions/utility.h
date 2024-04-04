#include <iostream>

inline double threashold {11.1}; // Definition

//Defintion
inline double add(double a, double b)
{
	if( (a > 11.1) && (b > 11.1))
		return a + b;
	else
		return threashold;
}

/*

// This is error part, without inline. This header file is included in some other file.
So, this will cause multiple definition error => Use inline to solve.

double threashold {11.1}; // Definition

//Defintion
double add(double a, double b)
{
	if( (a > 11.1) && (b > 11.1))
		return a + b;
	else
		return threashold;
}

*/
