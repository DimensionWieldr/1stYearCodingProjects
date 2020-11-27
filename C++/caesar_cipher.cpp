#include <iostream>
#include <string>

int caesar_cipher();
std::string read();
std::string encrypt(int shift, std::string input);

int caesar_cipher() {
	unsigned char command;
	int shift{0};
	std::string s{""}, answer{""};

	while(true){
		std::cout << "Enter command: ";
		std::cin >> command;
		if(command == 'S'){
			std::cin >> shift;
			shift %= 26;
			s = read();
			answer = encrypt(shift, s);
			std::cout << answer << std::endl;
		}else{
			break;
		}
	}

	return 0;
}

std::string read(){
	std::string s;

	std::cin >> s;
	s = s.substr(0, s.length() - 1);

	return s;
}

std::string encrypt(int shift, std::string s){
	for(unsigned int i{0}; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			if(s[i] + shift < 'A'){
				s[i] += 26;
			}else if(s[i] + shift > 'Z'){
				s[i] -= 26;
			}
		}else{
			if(s[i] + shift < 'a'){
				s[i] += 26;
			}else if(s[i] + shift > 'z'){
				s[i] -= 26;
			}
		}
	}

	for(unsigned int i{0}; i < s.length(); i++){
		s[i] += shift;
	}

	return s;
}
