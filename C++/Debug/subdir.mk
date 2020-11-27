################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Complex.cpp \
../UpChar.cpp \
../caesar_cipher.cpp \
../cartesian_polar.cpp \
../checksum.cpp \
../coordinate_conversion.cpp \
../data_conversion.cpp \
../discrete_vel_and_acc.cpp \
../filter_outliers.cpp \
../income_tax.cpp \
../list_primes.cpp \
../matrix_multiply.cpp \
../practice.cpp \
../staircase.cpp \
../sum_matrices.cpp \
../testing.cpp \
../triangle_classification.cpp 

OBJS += \
./Complex.o \
./UpChar.o \
./caesar_cipher.o \
./cartesian_polar.o \
./checksum.o \
./coordinate_conversion.o \
./data_conversion.o \
./discrete_vel_and_acc.o \
./filter_outliers.o \
./income_tax.o \
./list_primes.o \
./matrix_multiply.o \
./practice.o \
./staircase.o \
./sum_matrices.o \
./testing.o \
./triangle_classification.o 

CPP_DEPS += \
./Complex.d \
./UpChar.d \
./caesar_cipher.d \
./cartesian_polar.d \
./checksum.d \
./coordinate_conversion.d \
./data_conversion.d \
./discrete_vel_and_acc.d \
./filter_outliers.d \
./income_tax.d \
./list_primes.d \
./matrix_multiply.d \
./practice.d \
./staircase.d \
./sum_matrices.d \
./testing.d \
./triangle_classification.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


