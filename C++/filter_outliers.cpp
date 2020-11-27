#include <iostream>

void filter_outliers(int * & data_set, std::size_t & qty_data, int min_value, int max_value);

void filter_outliers(int * & data_set, std::size_t & qty_data, int min_value, int max_value){
	std::size_t count{0};
	for(std::size_t i{0}; i < qty_data; i++){
		if(data_set[i] >= min_value && data_set[i] <= max_value){
			count++;
		}
	}
	int * new_data_set{new int[count]{}};
	count = 0;
	for(std::size_t i{0}; i < qty_data; i++){
		if(data_set[i] >= min_value && data_set[i] <= max_value){
			new_data_set[count] = data_set[i];
			count++;
		}
	}
	qty_data = count;
	delete[] data_set;
	data_set = new_data_set;
}
