/*
 * person.h
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */

#ifndef PERSON_H_
#define PERSON_H_
#include"date.h"

class person
{
private:
	char name[40];
	char addr[100];
	date birth_date;
public:

	person();
	person(char * name,char *addr,date& birth_date);

	const char* get_Name() const;
	void set_Name(char * name);
	const char* get_Addr() const;
	void set_Addr(char * addr);
	const date& get_Birth_Date() const;
	void set_Birth_Date(const date& birthDate);

	void display();
	void accept();
    ~person();

};

#endif /* PERSON_H_ */
