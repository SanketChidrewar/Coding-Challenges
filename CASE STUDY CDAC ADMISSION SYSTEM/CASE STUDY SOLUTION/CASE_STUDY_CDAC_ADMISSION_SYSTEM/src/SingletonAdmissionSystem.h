/*
 * SingletonAdmissionSystem.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef SINGLETONADMISSIONSYSTEM_H_
#define SINGLETONADMISSIONSYSTEM_H_

#include "degrees.h"
#include "courses.h"
#include "eligibilities.h"
#include "centers.h"
#include "capacities.h"
#include "students.h"
#include "preference.h"

#include<vector>
#include<iostream>
using namespace std;

class SingletonAdmissionSystem {
private:
	vector<degrees> degree;
	vector<courses> course;
	vector<eligibilities> eligibilitie;
	vector<centers> center;
	vector<capacities> capacitie;
	vector<students> student;
	vector<preference> preferences;
public:

	SingletonAdmissionSystem();
	SingletonAdmissionSystem(vector<degrees> degree,vector<courses> course,vector<eligibilities> eligibilitie,vector<centers> center,vector<capacities> capacitie,vector<students> student,vector<preference> preferences );

	virtual ~SingletonAdmissionSystem();
};

#endif /* SINGLETONADMISSIONSYSTEM_H_ */