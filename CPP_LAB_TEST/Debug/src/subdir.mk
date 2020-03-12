################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Annual.cpp \
../src/Date.cpp \
../src/HealthClubMembership.cpp \
../src/Monthly.cpp \
../src/Semester.cpp \
../src/main.cpp 

OBJS += \
./src/Annual.o \
./src/Date.o \
./src/HealthClubMembership.o \
./src/Monthly.o \
./src/Semester.o \
./src/main.o 

CPP_DEPS += \
./src/Annual.d \
./src/Date.d \
./src/HealthClubMembership.d \
./src/Monthly.d \
./src/Semester.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


