#include <iostream>

class Complex{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double new_real, double new_imaginary);
	void add_value(double add_real, double add_imaginary);
	void add_value(Complex add_complex);
	void get_value(double &real_val, double &imaginary_val);
	double get_real() const;
	double get_imaginary() const;
};

Complex::Complex(){
	real = 0;
	imaginary = 0;
}

Complex::Complex(double new_real, double new_imaginary){
	real = new_real;
	imaginary = new_imaginary;
}

void Complex::add_value(double add_real, double add_imaginary){
	real += add_real;
	imaginary += add_imaginary;
}

void Complex::add_value(Complex add_complex){
	real += add_complex.get_real();
	imaginary += add_complex.get_imaginary();
}

void Complex::get_value(double &real_val, double &imaginary_val){
	real_val = real;
	imaginary_val = imaginary;
}

double Complex::get_real() const{
	return real;
}

double Complex::get_imaginary() const{
	return imaginary;
}
