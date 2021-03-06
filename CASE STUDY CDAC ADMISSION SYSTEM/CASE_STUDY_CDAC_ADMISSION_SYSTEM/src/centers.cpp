/*
 * centers.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "centers.h"

centers::centers() {
	// TODO Auto-generated constructor stub
	this->center_id = " ";
	this->center_name = " ";
	this->address = " ";
	this->coordinator = " ";
	this->password = " ";
}
centers::centers(string center_id,string center_name,string address,string coordinator,string password)
{

	this->center_id = center_id;
	this->center_name = center_name;
	this->address = address;
	this->coordinator = coordinator;
	this->password = password;
}


const string& centers::getAddress() const {
	return address;
}

void centers::setAddress(const string& address) {
	this->address = address;
}

const string& centers::getCenterId() const {
	return center_id;
}

void centers::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& centers::getCenterName() const {
	return center_name;
}

void centers::setCenterName(const string& centerName) {
	center_name = centerName;
}

const string& centers::getCoordinator() const {
	return coordinator;
}

void centers::setCoordinator(const string& coordinator) {
	this->coordinator = coordinator;
}

const string& centers::getPassword() const {
	return password;
}

void centers::setPassword(const string& password) {
	this->password = password;
}

void centers::display_centers()
{
	cout<<this->center_id<<","<<this->center_name<<","<<this->address<<","<<this->coordinator<<","<<this->password<<endl;
}


centers::~centers() {
	// TODO Auto-generated destructor stub
}

