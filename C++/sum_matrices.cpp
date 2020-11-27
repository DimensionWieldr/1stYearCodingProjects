#include <iostream>

void sum_matrices(double output_matrix[4], double input_matrices[], std::size_t input_cap);

#ifndef MARMOSET_TESTING
int sum_matricess();
#endif

#ifndef MARMOSET_TESTING
int sum_matricess(){
	double output_matrix[4]{};
	double input_matrices[8]{1,2,3,4,5,6,7,8};
	sum_matrices(output_matrix, input_matrices, 8);
	std::cout << output_matrix[0] << std::endl;
	std::cout << output_matrix[1] << std::endl;
	std::cout << output_matrix[2] << std::endl;
	std::cout << output_matrix[3] << std::endl;
    return 0;
}
#endif

void sum_matrices(double output_matrix[4], double input_matrices[], std::size_t input_cap){
	double a{0}, b{0}, c{0}, d{0};
	for(std::size_t i{0}; i < input_cap; i+=4){
		a += input_matrices[i];
	}
	for(std::size_t i{1}; i < input_cap; i+=4){
		b += input_matrices[i];
	}
	for(std::size_t i{2}; i < input_cap; i+=4){
		c += input_matrices[i];
	}
	for(std::size_t i{3}; i < input_cap; i+=4){
		d += input_matrices[i];
	}
	output_matrix[0] = a;
	output_matrix[1] = b;
	output_matrix[2] = c;
	output_matrix[3] = d;
}
