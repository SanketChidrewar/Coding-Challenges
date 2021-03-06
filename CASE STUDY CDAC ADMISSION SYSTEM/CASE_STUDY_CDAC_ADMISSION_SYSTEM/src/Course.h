/*
 * Course.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <string>
#include <vector>
#include "AdmissionSystem.h"


#include "eligibilities.h"

class centers;

using namespace std;

class Course {
	int id;
	string name;
	double fees;
	string ccat_section;

	vector<eligibilities> eligible;
	multimap<int,int> centers_of_respective_courses;

private:

public:
	Course();
	Course(int& id, string& name, double& fees, string& ccat_section,vector<eligibilities> eligible,multimap<int,int> centers_of_respective_courses);
	const string& getCcatSection() const;
	void setCcatSection(const string& ccatSection);

	const vector<eligibilities>& getEligible() const;
	void setEligible(const vector<eligibilities>& eligible);
	double getFees() const;
	void setFees(double fees);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);

	void display_Course_with_eligibilities_and_centers(AdmissionSystem& a);
	void display_Course_with_eligibilities();
	void display_Course_with_centers(AdmissionSystem& a);



	void add_eligibilities(eligibilities& e);
	void add_centers(int id, int pos);


	virtual ~Course();
	const multimap<int, int>& getCentersOfRespectiveCourses() const;
	void setCentersOfRespectiveCourses(
			const multimap<int, int>& centersOfRespectiveCourses);
};

#endif /* COURSE_H_ */
