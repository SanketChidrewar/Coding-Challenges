/*
 * salesmanager.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#include "salesmanager.h"

sales_manager::sales_manager() {
	// TODO Auto-generated constructor stub

}

sales_manager::sales_manager(int id,float sal,float bonus,float comm)
{
	this->manager::set_Id(id);
	this->salesman::set_Sal(sal);
	this->set_Bonus(bonus);
	this->set_Comm(comm);
}
void sales_manager::display()
{
	this->manager::display();
}
void sales_manager::accept()
{
	this->salesman::display();
}

sales_manager::~sales_manager() {
	// TODO Auto-generated destructor stub
}

