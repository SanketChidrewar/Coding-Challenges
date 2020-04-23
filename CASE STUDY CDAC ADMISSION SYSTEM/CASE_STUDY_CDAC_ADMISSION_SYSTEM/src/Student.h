/*
 * Student.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */


#ifndef STUDENT_H_
#define STUDENT_H_

#include "preference.h"
#include<iostream>
#include<vector>
using namespace std;

class Student {
private:
	int id;
	string name;
	int rank_a;
	int rank_b;
	int rank_c;
	string degree;
	double degree_marks;
	int allocated_pref;
	string course_name;
	string center_id;
	double payment;
	int reported;
	string prn;
	vector<preference> preferences;

public:

	Student();
	Student(int id, string name, int rank_a, int rank_b, int rank_c, string degree, double degree_marks, int allocated_pref, string course_name, string center_id, double payment, int reported, string prn, vector<preference> preferences);

	int getId() const;
	void setId(int id);

	int getRankA() const;
	void setRankA(int rankA);

	int getRankB() const;
	void setRankB(int rankB);

	int getRankC() const;
	void setRankC(int rankC);

	double getDegreeMarks() const;
	void setDegreeMarks(double degreeMarks);

	double getPayment() const;
	void setPayment(double payment);

	int getReported() const;
	void setReported(int reported);

	const vector<preference>& getPreferences() const;
	void setPreferences(const vector<preference>& preferences);

	void add_preferences(preference p);


	void display_stud();
	void display_only_stud();


	virtual ~Student();

	int getAllocatedPref() const;
	void setAllocatedPref(int allocatedPref);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	const string& getName() const;
	void setName(const string& name);
	const string& getPrn() const;
	void setPrn(const string& prn);
};

#endif /* STUDENT_H_ */
