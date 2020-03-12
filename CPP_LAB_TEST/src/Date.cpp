/*
 * Date.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#include "Date.h"
#include<iostream>
using namespace std;

Date::Date() {
	this->day=0;
	this->month=0;
	this->year=0;
}

Date::Date(int day,int month,int year)
{
	this->day=day;
	this->month=month;
	this->year=year;

}
void Date::Accept()
{
	cout<<"ENTER DATE :"<<endl;
	cin>>this->day>>this->month>>this->year;
}
void Date::Display()
{
	cout<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() const {
	return year;
}

void Date::setYear(int year) {
	this->year = year;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

