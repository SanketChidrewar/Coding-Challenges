/*
 * HealthClubMembership.h
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#ifndef HEALTH_CLUB_MEMBERSHIP_H_
#define HEALTH_CLUB_MEMBERSHIP_H_

#include"Date.h"


class Health_Club_Membership {
private:
	char name[30];
	int IS_CUST_OLD;
	Date Start_Date;
	float amount_paid;

public:
	Health_Club_Membership();

	Health_Club_Membership(char* name, int IS_CUST_OLD, Date& Start_Date, float amount_paid);

	virtual void Accept();
	virtual void Display();

	virtual float calculate_cost()=0;

	virtual ~Health_Club_Membership();
	float getAmountPaid() const;
	void setAmountPaid(float amountPaid);
	int getIsCustOld() const;
	void setIsCustOld(int isCustOld);
	const char* getName() const;
	void setName(char * name);
	const Date& getStartDate() const;

	void setStartDate(const Date& startDate);
};

#endif /* HEALTH_CLUB_MEMBERSHIP_H_ */
