/*
 * date.cpp
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */

#include "date.h"
#include<iostream>
using namespace std;

		date::date()
		{
			this->day=01;
			this->month=01;
			this->year=2001;
		}

		date::date(int day,int month,int year)
		{
			this->day=day;
			this->month=month;
			this->year=year;
		}

		int date::get_Day() const
		{
			return day;
		}

		void date::set_Day(int day)
		{
			this->day = day;
		}

		int date::get_Month() const
		{
			return month;
		}

		void date::set_Month(int month)
		{
			this->month = month;
		}

		int date::get_Year() const
		{
			return year;
		}

		void date::set_Year(int year)
		{
			this->year = year;
		}

		void date::display()
		{
			cout<<"\n\ndate :"<<this->day<<"-"<<this->month<<"-"<<this->year<<"\n"<<endl;

		}

		void date::accept()
		{
			cout<<"\nENTER date IN (DD MM YYYY) :";
			cin>>this->day>>this->month>>this->year;
		}

		bool date::is_leap_year()
		{

			if(this->year%400 == 0)
			{
				return 1 ;
			}
			else if(this->year%4 == 0 && this->year%100 !=0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
