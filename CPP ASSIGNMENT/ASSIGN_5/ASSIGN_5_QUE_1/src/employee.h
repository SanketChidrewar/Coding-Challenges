/*
 * employee.h
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include"date.h"
#include"person.h"



class employee
{
	int id;
	float sal;
	char dept[24];
	date joining;
public:
	employee();
	employee(int id,float sal,char * dept,date& joining);

	const char* get_Dept() const;
	void set_Dept(char * dept);
	int get_Id() const;
	void set_Id(int id);
	const date& get_Joining() const;
	void set_Joining(const date& joining);
	float get_Sal() const;
	void set_Sal(float sal);

	void display();
	void accept();
    ~employee();

};

#endif /* EMPLOYEE_H_ */
