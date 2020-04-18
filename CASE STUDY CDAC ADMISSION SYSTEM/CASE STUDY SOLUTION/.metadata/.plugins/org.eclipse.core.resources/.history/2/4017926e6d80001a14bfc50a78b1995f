/*
 * preference.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

class preference {
private :
	int id;
	int pref_no;
	char course_name[50];
	char center_id[50];

public:
	preference();
	preference(int id, int pref_no, char* course_name, char* center_id);

	const char* getCenterId() const;
	void setCenterId(char* center_id);

	const char* getCourseName() const;
	void setCourseName(char* course_name);

	int getId() const;
	void setId(int id);

	int getPrefNo() const;
	void setPrefNo(int prefNo);

	void display_pref();

	virtual ~preference();

};

#endif /* PREFERENCE_H_ */
