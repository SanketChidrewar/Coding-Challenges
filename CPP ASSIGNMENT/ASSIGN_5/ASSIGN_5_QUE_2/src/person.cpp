/*
 * person.cpp
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */
#include"date.h"
#include "person.h"
#include<iostream>
#include<cstring>
using namespace std;

person::person():birth_date()
{
	strcpy(this->name,"");
	strcpy(this->addr,"");
}
person::person(char * name,char *addr,date& birth_date)
{
	strcpy(this->name,name);
	strcpy(this->addr,addr);
	this->birth_date = birth_date;
}

const char* person::get_Name() const
{
	return name;
}
void person::set_Name(char * name)
{
	strcpy(this->name,name);
}

const char* person::get_Addr() const
{
	return addr;
}
void person::set_Addr(char * addr)
{
	strcpy(this->addr,addr);
}

const date& person::get_Birth_Date() const
{
	return birth_date;
}
void person::set_Birth_Date(const date& birthDate)
{
	birth_date = birthDate;
}

void person::display()
{
	cout<<"\nNAME :"<<this->name;
	cout<<"\nADDRESS :"<<this->addr;
	this->birth_date.display();
}
void person::accept()
{
	cout<<"ENTER NAME OF A PERSON :";
	cin.get(this->name,40);
	cout<<"ENTER ADDRESS OF PERSON :";
	cin.get(this->addr,100);
	this->birth_date.accept();
}

person::~person() {
	// TODO Auto-generated destructor stub
}

