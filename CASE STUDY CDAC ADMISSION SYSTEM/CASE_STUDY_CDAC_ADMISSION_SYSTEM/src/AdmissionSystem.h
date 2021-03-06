/*
 * AdmissionSystem.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef ADMISSIONSYSTEM_H_
#define ADMISSIONSYSTEM_H_

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

class AdmissionSystem {
public:
	vector<degrees> degree;
	vector<courses> course;
	vector<eligibilities> eligibilitie;
	vector<centers> center;
	vector<capacities> capacitie;
	vector<students> student;
	vector<preference> preferences;
public:

	AdmissionSystem();
	AdmissionSystem(vector<degrees> degree,vector<courses> course,vector<eligibilities> eligibilitie,vector<centers> center,vector<capacities> capacitie,vector<students> student,vector<preference> preferences );

	virtual ~AdmissionSystem();
	const vector<capacities>& getCapacitie() const;
	void setCapacitie(const vector<capacities>& capacitie);
	const vector<centers>& getCenter() const;
	void setCenter(const vector<centers>& center);
	const vector<courses>& getCourse() const;
	void setCourse(const vector<courses>& course);
	const vector<degrees>& getDegree() const;
	void setDegree(const vector<degrees>& degree);
	const vector<eligibilities>& getEligibilitie() const;
	void setEligibilitie(const vector<eligibilities>& eligibilitie);
	const vector<preference>& getPreferences() const;
	void setPreferences(const vector<preference>& preferences);
	const vector<students>& getStudent() const;
	void setStudent(const vector<students>& student);

	void display_degrees();
	void display_courses();
	void display_eligibilities();
	void display_centers();
	void display_capacities();
	void display_students();
	void display_preference();

	void load_Files(AdmissionSystem & a);

	int is_seats_are_full(string id,string course);
	void increment_capacity_size_by_one(string id,string course);



};
#endif /* ADMISSIONSYSTEM_H_ */
