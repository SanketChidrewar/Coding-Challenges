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
	char name[50];
	int rank_a;
	int rank_b;
	int rank_c;
	char degree[50];
	double degree_marks;
	char course_name[50];
	char center_id[10];
	double payment;
	int reported;
	char prn[50];

	vector<preference> preferences;

public:

	Student();
	Student(int id, char* name, int rank_a, int rank_b, int rank_c, char* degree, double degree_marks, char* course_name, char* center_id, double payment, int reported, char* prn, vector<preference> preferences);

	int getId() const;
	void setId(int id);

	const char* getName() const;
	void setName(char* name);

	int getRankA() const;
	void setRankA(int rankA);

	int getRankB() const;
	void setRankB(int rankB);

	int getRankC() const;
	void setRankC(int rankC);

	const char* getDegree() const;
	void setDegree(char* degree);

	double getDegreeMarks() const;
	void setDegreeMarks(double degreeMarks);

	const char* getCourseName() const;
	void setCourseName(char* course_name);

	const char* getCenterId() const;
	void setCenterId(char* center_id);

	double getPayment() const;
	void setPayment(double payment);

	int getReported() const;
	void setReported(int reported);

	const char* getPrn() const;
	void setPrn(char* prn);

	const vector<preference>& getPreferences() const;
	void setPreferences(const vector<preference>& preferences);

	void display_stud();

	virtual ~Student();

};

#endif /* STUDENT_H_ */
