#include <iostream>

int data_conversion();

int data_conversion() {

  std::cout << "3.1 KB is " << 3.1*1000*8 << " bits." << std::endl;
  std::cout << "3.1 GB of data can be stored with " << 3.1*1000/700 << " CDs." << std::endl;
  std::cout << "421.2 hours of music can be stored with " << 421.2*60/80 << " CDs." << std::endl;
  std::cout << "51 CDs will take " << (51*700)/(75.4/8)/60/60 << " hours to fill." << std::endl;

  return 0;
}
