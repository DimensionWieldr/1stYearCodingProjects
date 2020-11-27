#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef MARMOSET_TESTING
int coordinate_conversion();
#endif

double polar_radius(double x, double y);
double polar_angle(double x, double y);
void print_polar(double x, double y);

#ifndef MARMOSET_TESTING
int coordinate_conversion(){
	print_polar(2, 2);
	print_polar(-0.5, std::sqrt(3)/2);
	print_polar(-2, -2*std::sqrt(3));
	print_polar(1, -std::sqrt(3));
	print_polar(0, 1);
	print_polar(5,-18);

	return 0;
}
#endif

double polar_radius(double x, double y){
	return std::hypot(x, y);
}

double polar_angle(double x, double y){

	double quotient{y/x};

	if(quotient < 0){
		quotient *= -1;
	}

	double angle{std::atan(quotient) / M_PI * 180};

	if(x < 0 && y > 0){
		angle = 180 - angle;
	}else if(x < 0 && y < 0){
		angle += 180;
	}else if(x > 0 && y < 0){
		angle = 360 - angle;
	}

	return angle;
}

void print_polar(double x, double y){
	std::cout << "(" << x << "," << y << ") in polar form is: (" << polar_radius(x, y) << "," << polar_angle(x, y) << ")" << std::endl;
}
