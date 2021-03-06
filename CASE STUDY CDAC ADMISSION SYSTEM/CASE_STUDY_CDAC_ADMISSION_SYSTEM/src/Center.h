/*
 * Center.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CENTER_H_
#define CENTER_H_

#include "courses.h"
#include "AdmissionSystem.h"

#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Center {
private:
	string id;
	string name;
	string address;
	string coordinator;
	string password;

	multimap<string,int> center_id_courses;

public:
	Center();
	Center(string id, string name, string address, string coordinator, string password, multimap<string,int> center_id_courses);

	void display_Center_with_courses(AdmissionSystem& a);

	void add_courses_to_respective_centers(string s, int k);

	virtual ~Center();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCoordinator() const;
	void setCoordinator(const string& coordinator);
	const vector<courses>& getCourse() const;
	void setCourse(const vector<courses>& course);
	const string& getId() const;
	void setId(const string& id);
	const string& getName() const;
	void setName(const string& name);
	const string& getPassword() const;
	void setPassword(const string& password);
	const multimap<string, int>& getCenterIdCourses() const;
	void setCenterIdCourses(const multimap<string, int>& centerIdCourses);
};

#endif /* CENTER_H_ */
