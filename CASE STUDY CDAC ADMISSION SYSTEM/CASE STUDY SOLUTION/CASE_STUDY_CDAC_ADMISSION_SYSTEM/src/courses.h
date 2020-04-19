/*
 * courses.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef COURSES_H_
#define COURSES_H_

#include<iostream>
using namespace std;

class courses {
private:
	int id;
	string name;
	double fees;
	string section;
public:
	courses();
	courses(int id, string name, double fees, string section);

	void display_courses();

	virtual ~courses();
	double getFees() const;
	void setFees(double fees);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
//	const string& getSection() const;
//	void setSection(const string& section);
	const string& getSection() const;
	void setSection(const string& section);
};

#endif /* COURSES_H_ */
