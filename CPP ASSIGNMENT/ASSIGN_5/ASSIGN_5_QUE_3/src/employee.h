/*
 * employee.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class employee {
private:
	int id;
	float sal;
public:
	employee();
	employee(int id,float sal);

	int get_Id() const;
	void set_Id(int id);
	float get_Sal() const;
	void set_Sal(float sal);

	virtual void display();
	void accept();

   ~employee();
};

#endif /* EMPLOYEE_H_ */
