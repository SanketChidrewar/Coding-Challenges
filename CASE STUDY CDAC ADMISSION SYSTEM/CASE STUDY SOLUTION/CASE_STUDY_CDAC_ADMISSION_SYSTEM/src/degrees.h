/*
 * degrees.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef DEGREES_H_
#define DEGREES_H_

#include<iostream>
using namespace std;

class degrees {
private:
	string degree;

public:
	degrees();
	degrees(string degree);
	void display_degrees();
	virtual ~degrees();
	const string& getDegree() const;
	void setDegree(const string& degree);
};

#endif /* DEGREES_H_ */
