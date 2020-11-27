#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int checksum();
#endif

unsigned int calculate_checksum(unsigned int n);

unsigned int add_checksum(unsigned int n);

void add_checksum(unsigned int array[], std::size_t capacity);

bool verify_checksum(unsigned int n);

unsigned int remove_checksum(unsigned int n);

void remove_checksum(unsigned int array[], std::size_t capacity);

#ifndef MARMOSET_TESTING
int checksum() {
	std::cout << add_checksum(90829446);

	return 0;
}
#endif

unsigned int calculate_checksum(unsigned int n){
	unsigned int divisor{1};
	unsigned int digit[9]{};

	//save digits of n in array
	for(unsigned int i{0}; i <= 7; i++){
		if(i > 0){
			divisor *= 10;
		}
		if(n/divisor%10 == 0){
			digit[7-i] = 0;
		}else{
			digit[7-i] = n/divisor%10;
		}
	}

	//double every other value & sum digits of each value
	for(unsigned int i{1}; i <= 7; i+=2){
		digit[i] *= 2;
		if(digit[i] > 9){
			digit[i] = digit[i]%10 + digit[i]/10;
		}
	}

	unsigned int checksum{0};

	//calculate checksum
	for(unsigned int i{0}; i <= 7; i++){
		checksum += digit[i];
	}
	checksum = checksum*9%10;

	return checksum;
}

unsigned int add_checksum(unsigned int n){
	if(n > 99999999){
		return UINT_MAX;
	}

	return n*10 + calculate_checksum(n);
}

void add_checksum(unsigned int array[], std::size_t capacity){
	for(unsigned int i{0}; i < capacity; i++){
		array[i] = add_checksum(array[i]);
	}
}

bool verify_checksum(unsigned int n){
	if(n > 999999999){
		return false;
	}

	return n%10 == calculate_checksum(n/10);
}

unsigned int remove_checksum(unsigned int n){
	if(n > 999999999 || !verify_checksum(n)){
		return UINT_MAX;
	}

	return n/10;
}

void remove_checksum(unsigned int array[], std::size_t capacity){
	for(unsigned int i{0}; i < capacity; i++){
		array[i] = remove_checksum(array[i]);
	}
}
