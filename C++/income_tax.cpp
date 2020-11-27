#include <iostream>
#include <cassert>

#ifndef MARMOSET_TESTING
int income_tax();
#endif

double income_tax(double income);

#ifndef MARMOSET_TESTING
int income_tax(){

	std::cout << "24000 will be taxed: $" << income_tax(24000) << std::endl;
	std::cout << "67000 will be taxed: $" << income_tax(67000) << std::endl;
	std::cout << "285000 will be taxed: $" << income_tax(285000) << std::endl;

	return 0;
}
#endif

double income_tax(double income){

	double tax{0};

	assert(income > 0);

	if(income > 210371){
		tax += 47630*0.15 + 47629*0.205 + 52408*0.26 + 62704*0.29 + (income - 210371)*0.33;
	}else if(income > 147667){
		tax += 47630*0.15 + 47629*0.205 + 52408*0.26 + (income - 147667)*0.29;
	}else if(income > 95259){
		tax += 47630*0.15 + 47629*0.205 + (income - 95259)*0.26;
	}else if(income > 47630){
		tax += 47630*0.15 + (income - 47630)*0.205;
	}else{
		tax += income*0.15;
	}

	return tax;
}
