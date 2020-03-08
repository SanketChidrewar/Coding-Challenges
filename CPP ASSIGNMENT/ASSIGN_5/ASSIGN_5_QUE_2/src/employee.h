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



class employee : public person
{
	int id;
	float sal;
	char dept[24];
	date joining;
public:
	employee();
	employee(char* name,char* addr,date& birth_date,int id,float sal,char * dept,date& joining);

	int get_Id() const;
	void set_Id(int id);
	float get_Sal() const;
	void set_Sal(float sal);
	const char* get_Dept() const;
	void set_Dept(char * dept);
	const date& get_Joining() const;
	void set_Joining(const date& joining);

	void display();
	void accept();
    ~employee();

};

#endif /* EMPLOYEE_H_ */
