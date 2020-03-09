/*
 * salesmanager.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#ifndef SALESMANAGER_H_
#define SALESMANAGER_H_
#include"manager.h"
#include"salesman.h"

class sales_manager :public manager,salesman
{
public:
	sales_manager();
	sales_manager(int id,float sal,float bonus,float comm);
	virtual void display();
	void accept();
    ~sales_manager();
};

#endif /* SALESMANAGER_H_ */
