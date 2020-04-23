/*
 * preference.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

#include<iostream>
using namespace std;

class preference {
private :
	int id;
	int pref_no;
	string course_name;
	string center_id;

public:
	preference();
	preference(int id, int pref_no, string course_name, string center_id);

	int getId() const;
	void setId(int id);

	int getPrefNo() const;
	void setPrefNo(int prefNo);

	void display_pref();

	virtual ~preference();
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
};

#endif /* PREFERENCE_H_ */
