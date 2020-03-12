/*
 * Date.h
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();

	Date(int day,int month,int year);
	void Accept();
	void Display();
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);

	virtual ~Date();

};

#endif /* DATE_H_ */
