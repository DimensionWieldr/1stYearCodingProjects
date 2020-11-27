#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef MARMOSET_TESTING
int cartesian_polar();
#endif

void cartesian_to_polar(double * coordinate_x, double * coordinate_y);
void polar_to_cartesian(double * coordinate_r, double * coordinate_t);

#ifndef MARMOSET_TESTING
int cartesian_polar(){
	double x{1}, y{-1};
	double * p_x{&x};
	double * p_y{&y};
	cartesian_to_polar(p_x, p_y);
	std::cout << x << " " << y << std::endl;

	double r{std::sqrt(2)}, t{-45};
	double * p_r{&r};
	double * p_t{&t};
	polar_to_cartesian(p_r, p_t);
	std::cout << r << " " << t << std::endl;

	return 0;
}
#endif

void cartesian_to_polar(double * coordinate_x, double * coordinate_y){
	double r{}, t{};
	r = std::hypot(*coordinate_y, *coordinate_x);
	t = std::atan2(*coordinate_y, *coordinate_x);
	*coordinate_x = r;
	*coordinate_y = t/M_PI*180;
}

void polar_to_cartesian(double * coordinate_r, double * coordinate_t){
	double x{}, y{};
	x = *coordinate_r*std::cos(*coordinate_t*M_PI/180);
	y = *coordinate_r*std::sin(*coordinate_t*M_PI/180);
	*coordinate_r = x;
	*coordinate_t = y;
}
