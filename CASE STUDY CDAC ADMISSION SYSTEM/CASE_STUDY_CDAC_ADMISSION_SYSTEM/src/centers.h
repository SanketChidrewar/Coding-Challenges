/*
 * centers.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CENTERS_H_
#define CENTERS_H_
#include<iostream>
using namespace std;

class centers {
private:
	string center_id;
	string center_name;
	string address;
	string coordinator;
	string password;

public:
	centers();
	centers(string center_id,string center_name,string address,string coordinator,string password);
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCenterName() const;
	void setCenterName(const string& centerName);
	const string& getCoordinator() const;
	void setCoordinator(const string& coordinator);
	const string& getPassword() const;
	void setPassword(const string& password);

	void display_centers();
	virtual ~centers();

};

#endif /* CENTERS_H_ */
