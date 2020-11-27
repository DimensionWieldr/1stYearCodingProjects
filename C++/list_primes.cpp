#include <iostream>

int list_primes();

int list_primes(){
	int low, high;
	bool primeInRange{false};

	std::cout << "List Primes Program" << std::endl;
	std::cout << "Enter first number: ";
	std::cin >> low;
	std::cout << "Enter second number: ";
	std::cin >> high;

	if(low%2 == 0 && low != 2){
		low++;
	}
	if(high%2 == 0 && high != 2){
		high--;
	}
	if(low <= 2 && high >= 2){
		primeInRange = true;
		std::cout << "Primes in range: 2";
	}
	if(low == 2){
		low++;
	}

	bool prime;
	for(int i{low}; i <= high; i+=2){
		prime = true;
		for(int j{3}; j < i; j+=2){
			if(i%j == 0){
				prime = false;
				break;
			}
		}
		if(prime && i != 1){
			if(!primeInRange){
				std::cout << "Primes in range:";
			}
			primeInRange = true;
			std::cout << " " << i;
		}
	}

	if(!primeInRange){
		std::cout << "No primes in range.";
	}

	return 0;
}
