/*
 * students.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_
#include "preference.h"
#include<iostream>
using namespace std;

class students {
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
public:
	students();
	students(int id, string name, int rank_a, int rank_b, int rank_c, string degree, double degree_marks, int allocated_pref, string course_name, string center_id, double payment, int reported, string prn);

	int getAllocatedPref() const;
	void setAllocatedPref(int allocatedPref);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	double getDegreeMarks() const;
	void setDegreeMarks(double degreeMarks);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	double getPayment() const;
	void setPayment(double payment);
	const string& getPrn() const;
	void setPrn(const string& prn);
	int getRankA() const;
	void setRankA(int rankA);
	int getRankB() const;
	void setRankB(int rankB);
	int getRankC() const;
	void setRankC(int rankC);
	int getReported() const;
	void setReported(int reported);

	void display_students();


	virtual ~students();

};

#endif /* STUDENTS_H_ */
