#include <iostream>

void output_velocity_and_acceleration(double position_measurements[], std::size_t qty_measurements);
void velocity(double position_measurements[], std::size_t qty_measurements);
void acceleration(double position_measurements[], std::size_t qty_measurements);

#ifndef MARMOSET_TESTING
int discrete_vel_and_acc();
#endif

#ifndef MARMOSET_TESTING
int discrete_vel_and_acc() {
	double position_measurements[]{1.3, 1.4, 1.6, 1.7, 1.8, 1.8};
	output_velocity_and_acceleration(position_measurements, 6);
	return 0;
}
#endif

void output_velocity_and_acceleration(double position_measurements[], std::size_t qty_measurements){
	if(qty_measurements < 2){
		std::cout << "Insufficient measurements for velocity calculation." << std::endl;
		std::cout << "Insufficient measurements for acceleration calculation." << std::endl;
		return;
	}
	if(qty_measurements < 3){
		std::cout << "Velocity calculations [m/s]:" << std::endl;
		velocity(position_measurements, qty_measurements);
		std::cout << "Insufficient measurements for acceleration calculation." << std::endl;
		return;
	}
	std::cout << "Velocity calculations [m/s]:" << std::endl;
	velocity(position_measurements, qty_measurements);
	std::cout << "Acceleration calculations [m/s^2]:" << std::endl;
	acceleration(position_measurements, qty_measurements);
}

void velocity(double position_measurements[], std::size_t qty_measurements){
	for(unsigned int i{1}; i < qty_measurements; i++){
		std::cout << position_measurements[i] - position_measurements[i-1] << " ";
	}
	std::cout << std::endl;
}

void acceleration(double position_measurements[], std::size_t qty_measurements){
	double velocity_measurements[qty_measurements-1]{};

	for(unsigned int i{1}; i < qty_measurements; i++){
		velocity_measurements[i-1] = position_measurements[i] - position_measurements[i-1];
	}

	for(unsigned int i{1}; i < qty_measurements-1; i++){
		std::cout << velocity_measurements[i] - velocity_measurements[i-1] << " ";
	}
	std::cout << std::endl;
}
