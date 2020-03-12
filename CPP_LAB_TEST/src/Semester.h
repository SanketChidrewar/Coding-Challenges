/*
 * Semester.h
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#ifndef SEMESTER_H_
#define SEMESTER_H_
#include "Health_Club_Membership.h"
#include<iostream>
using namespace std;


class Semester : public Health_Club_Membership{
	private :
	int age;
	float cost;
	float dicount;
public:
	Semester();

	float calculate_cost();
		void Accept();
		void Display();
		int getAge() const;
		void setAge(int age);
		float getCost() const;
		void setCost(float cost);
		float getDicount() const;
		void setDicount(float dicount);

	virtual ~Semester();
};

#endif /* SEMESTER_H_ */
