#include <iostream>

#ifndef MARMOSET_TESTING
int multiply();
#endif

void matrix_multiply(double matrixA[2][2], double matrixB[2][2]);

#ifndef MARMOSET_TESTING
int multiply(){
	double matrixA[2][2]{{5,6},{0,3}};
	double matrixB[2][2]{{9,3},{7,0}};
	matrix_multiply(matrixA, matrixB);
	std::cout << matrixA[0][0] << matrixA[0][1] << matrixA[1][0] << matrixA[1][1];
	return 0;
}
#endif

void matrix_multiply(double matrixA[2][2], double matrixB[2][2]){
	double i = matrixA[0][0]*matrixB[0][0] + matrixA[0][1]*matrixB[1][0];
	double k = matrixA[1][0]*matrixB[0][0] + matrixA[1][1]*matrixB[1][0];
	double j = matrixA[0][0]*matrixB[0][1] + matrixA[0][1]*matrixB[1][1];
	double m = matrixA[1][0]*matrixB[0][1] + matrixA[1][1]*matrixB[1][1];
	matrixA[0][0] = i;
	matrixA[0][1] = j;
	matrixA[1][0] = k;
	matrixA[1][1] = m;
}
