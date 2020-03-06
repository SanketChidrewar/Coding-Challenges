/*
 * cylinder.h
 *
 *  Created on: 04-Mar-2020
 *      Author: sunbeam
 */


#ifndef CYLINDER_H_
#define CYLINDER_H_

class Cylinder
{
private:
	const double pi =3.14;
	double radius;
	double height;

public:
	Cylinder();
	Cylinder(double radius, double height);
	void getVolume();
	void printVolume();
};
int menuChoice();

#endif /* CYLINDER_H_ */
