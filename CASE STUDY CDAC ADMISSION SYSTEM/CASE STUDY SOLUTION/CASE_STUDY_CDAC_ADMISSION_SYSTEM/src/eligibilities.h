/*
 * eligibilities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef ELIGIBILITIES_H_
#define ELIGIBILITIES_H_

#include<iostream>
using namespace std;

class eligibilities {
private:
	string course_name;
	string degree;
	double min_per;

public:
	eligibilities();
	eligibilities(string course_name,string degree,double min_per);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	double getMinPer() const;
	void setMinPer(double minPer);

	void display_eligibilities();
	virtual ~eligibilities();

};

#endif /* ELIGIBILITIES_H_ */
