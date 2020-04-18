/*
 * Center.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CENTER_H_
#define CENTER_H_

#include "courses.h"
#include<vector>

using namespace std;

class Center {
private:
	string id;
	string name;
	string address;
	string coordinator;
	string password;

	vector<courses> course;

public:
	Center();
	Center(string id, string name, string address, string coordinator, string password, vector<courses> course);


	const vector<courses>& getCourses() const;
	void setCourses(const vector<courses>& course);

	void display_Center_with_courses();

	void add_courses_in_center(courses c);

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
};

#endif /* CENTER_H_ */
