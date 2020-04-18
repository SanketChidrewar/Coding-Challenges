################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdmissionSystem.cpp \
../src/Center.cpp \
../src/Course.cpp \
../src/Student.cpp \
../src/capacities.cpp \
../src/centers.cpp \
../src/courses.cpp \
../src/degrees.cpp \
../src/eligibilities.cpp \
../src/main.cpp \
../src/preference.cpp \
../src/students.cpp 

OBJS += \
./src/AdmissionSystem.o \
./src/Center.o \
./src/Course.o \
./src/Student.o \
./src/capacities.o \
./src/centers.o \
./src/courses.o \
./src/degrees.o \
./src/eligibilities.o \
./src/main.o \
./src/preference.o \
./src/students.o 

CPP_DEPS += \
./src/AdmissionSystem.d \
./src/Center.d \
./src/Course.d \
./src/Student.d \
./src/capacities.d \
./src/centers.d \
./src/courses.d \
./src/degrees.d \
./src/eligibilities.d \
./src/main.d \
./src/preference.d \
./src/students.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


