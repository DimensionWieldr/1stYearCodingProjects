#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef MARMOSET_TESTING
int triangle_classification();
#endif

char classify_triangle(int x, int y, int z);

#ifndef MARMOSET_TESTING
int triangle_classification(){

	std::cout << "Side lengths: " << 7 << ", " << 7 << ", " << 7 << std::endl;
	std::cout << "Classification: " << classify_triangle(7, 7, 7) << std::endl;
	std::cout << "Side lengths: " << 12 << ", " << 5 << ", " << 13 << std::endl;
	std::cout << "Classification: " << classify_triangle(12, 5, 13) << std::endl;
	std::cout << "Side lengths: " << 8 << ", " << 8 << ", " << 18 << std::endl;
	std::cout << "Classification: " << classify_triangle(8, 8, 18) << std::endl;

	return 0;
}
#endif

char classify_triangle(int x, int y, int z){
	int temp;

	//to ensure x <= y <= z
	if(y <= x && x <= z){
		temp = x;
		x = y;
		y = temp;
	}else if(y <= z && z <= x){
		temp = x;
		x = y;
		y = z;
		z = temp;
	}else if(z <= x && x <= y){
		temp = y;
		y = x;
		x = z;
		z = temp;
	}else if(z <= y && y <= x){
		temp = x;
		x = z;
		z = temp;
	}else if(x <= z && z <= y){
		temp = y;
		y = z;
		z = temp;
	}

	//not triangle
	if((x == 0 || y == 0 || z == 0) || (x + y <= z)){
		return 'N';
	}

	//equilateral
	if(x == y && y == z){
		return 'E';
	}

	//right angle
	if(x*x + y*y == z*z){
		return 'R';
	}

	//iscosceles
	if(x == y || y == z){
		return 'I';
	}

	//scalene
	return 'S';
}
