#include <iostream>

int staircase();

int staircase() {
  double x{};

  std::cout << "Enter value of x: ";
  std::cin >> x;

  int stair{};
  int MAX{2147483647}, MIN{-2147483648};

  //stair function calculations
  if(x >= MAX){
	  //technically not correct for huge values of x, but int has its limits -_-
	  stair = MAX;
  }else if(x < MIN){
	  //once again, technically incorrect, but oh well :)
	  stair = MIN;
  }else{
	  for(int i{MIN}; i <= MAX; ++i){
	  	  if(i > x){
	  		  stair = i - 1;
	  		  break;
	  	  }
	  }
  }

  std::cout << "The value of stair(x) is: ";
  std::cout << stair;
  std::cout << std::endl;

  return 0;
}
