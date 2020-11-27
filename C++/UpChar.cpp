#include <iostream>

class UpChar{
public:
	char c;

	void set_value(char new_c){
		c = new_c;
	}

	char get_value(){
		if(c == '\0'){
			return '_';
		}
		return std::toupper(c);
	}
};
