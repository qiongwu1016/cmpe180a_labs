################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Node.cpp \
../src/SortedList.cpp \
../src/SortedVector.cpp \
../src/TestDriver.cpp \
../src/TestSuite.cpp \
../src/Timer.cpp 

OBJS += \
./src/Node.o \
./src/SortedList.o \
./src/SortedVector.o \
./src/TestDriver.o \
./src/TestSuite.o \
./src/Timer.o 

CPP_DEPS += \
./src/Node.d \
./src/SortedList.d \
./src/SortedVector.d \
./src/TestDriver.d \
./src/TestSuite.d \
./src/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


