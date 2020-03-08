/*
 * date.h
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */

#ifndef date_H_
#define date_H_

class date
{
private:
	int day;
	int month;
	int year;
public:

	date();

	date(int day,int month,int year);

	int get_Day() const;

	void set_Day(int day);

	int get_Month() const;

	void set_Month(int month);

	int get_Year() const;

	void set_Year(int year);

    void display();

    void accept();

    bool is_leap_year();
};

#endif /* date_H_ */
