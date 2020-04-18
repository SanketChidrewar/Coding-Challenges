/*
 * Course.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef COURSE_H_
#define COURSE_H_
#include<iostream>
#include<vector>
#include "eligibilities.h"
#include "centers.h"

using namespace std;

class Course {
	int id;
	string name;
	double fees;
	string ccat_section;

	vector<eligibilities> eligible;
	vector<centers> center;

private:

public:
	Course();
	Course(int& id, string& name, double& fees, string& ccat_section,vector<eligibilities> eligible,vector<centers> center);
	const string& getCcatSection() const;
	void setCcatSection(const string& ccatSection);
	const vector<centers>& getCenter() const;
	void setCenter(const vector<centers>& center);
	const vector<eligibilities>& getEligible() const;
	void setEligible(const vector<eligibilities>& eligible);
	double getFees() const;
	void setFees(double fees);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);

	void display_Course_with_eligibilities_and_centers();

	void add_eligibilities(eligibilities& e);
	void add_centers(centers& c);


	virtual ~Course();

};

#endif /* COURSE_H_ */
