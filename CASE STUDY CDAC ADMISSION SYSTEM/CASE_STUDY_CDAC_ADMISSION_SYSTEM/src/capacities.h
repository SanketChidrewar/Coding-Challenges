/*
 * capacities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CAPACITIES_H_
#define CAPACITIES_H_

#include<iostream>
using namespace std;

class capacities {
private:
	string center_id;
	string course_name;
	int capacity;
	int filled_capacity;

public:
	capacities();
	capacities(string center_id, string course_name, int capacity, int filled_capacity);
	void display_capacities();
	virtual ~capacities();
	int getCapacity() const;
	void setCapacity(int capacity);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	int getFilledCapacity() const;
	void setFilledCapacity(int filledCapacity);

};

#endif /* CAPACITIES_H_ */
