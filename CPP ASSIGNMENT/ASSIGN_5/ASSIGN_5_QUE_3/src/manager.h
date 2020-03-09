/*
 * manager.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include<iostream>
#include"employee.h"
using namespace std;

class manager : public employee
{
private:
	float bonus;
public:
	manager();

	manager(int id,float sal,float bonus);
	int get_Bonus();
	void set_Bonus(float bonus);
	virtual void display();
	void accept();

	void display_Manager();
	void accept_Manager();

   ~manager();
};

#endif /* MANAGER_H_ */
