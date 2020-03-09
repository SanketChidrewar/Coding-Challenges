/*
 * salesman.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#ifndef SALESMAN_H_
#define SALESMAN_H_
#include"employee.h"

class salesman : public employee
{
private:
	float comm;
public:
	salesman();

	salesman(int id,float sal,float comm);
	int get_Comm();
	void set_Comm(float comm);
	virtual void display();
	void accept();

	void display_Salesman();
	void accept_Salesman();

    ~salesman();
};

#endif /* SALESMAN_H_ */
