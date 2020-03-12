/*
 * HealthClubMembership.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#include "Health_Club_Membership.h"
#include<cstring>
#include<iostream>
using namespace std;

Health_Club_Membership::Health_Club_Membership():Start_Date() {
	strcpy(this->name,"");
	this->IS_CUST_OLD=0;
	this->amount_paid=0;
}
Health_Club_Membership::Health_Club_Membership(char* name, int IS_CUST_OLD, Date& Start_Date, float amount_paid)
{
	strcpy(this->name,name);
	this->IS_CUST_OLD=IS_CUST_OLD;
	this->amount_paid=amount_paid;
	this->Start_Date = Start_Date;
}

void Health_Club_Membership::Accept()
{
	cout<<"ENTER CUSTOMER NAME :";
	cin.get(this->name,30);
	cout<<"IS CUST OLD \n1. YES\n0. NO\n ENTER YOUR CHOICE :";
	cin>>this->IS_CUST_OLD;
	this->Start_Date.Accept();
	//cout<<"ENTER AMOUNT PAID BY CUSTOMER :";
	//cin>>this->amount_paid;
}
void Health_Club_Membership::Display()
{
	cout<<"CUSTOMER NAME :"<<this->getName()<<endl;
	this->Start_Date.Display();
	cout<<"AMOUNT PAID BY CUSTOMER :"<<this->getAmountPaid()<<endl;
}

float Health_Club_Membership::getAmountPaid() const {
	return amount_paid;
}

void Health_Club_Membership::setAmountPaid(float amountPaid) {
	amount_paid = amountPaid;
}

int Health_Club_Membership::getIsCustOld() const {
	return IS_CUST_OLD;
}

void Health_Club_Membership::setIsCustOld(int isCustOld) {
	IS_CUST_OLD = isCustOld;
}

const char* Health_Club_Membership::getName() const {
	return name;
}
void Health_Club_Membership::setName(char * name)
{
	strcpy(this->name,name);
}

const Date& Health_Club_Membership::getStartDate() const {
	return Start_Date;
}

void Health_Club_Membership::setStartDate(const Date& startDate) {
	Start_Date = startDate;
}

Health_Club_Membership::~Health_Club_Membership() {
	// TODO Auto-generated destructor stub
}

