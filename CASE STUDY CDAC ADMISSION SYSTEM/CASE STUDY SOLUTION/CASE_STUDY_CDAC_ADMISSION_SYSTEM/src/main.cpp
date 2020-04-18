/*
 * main.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include<iostream>
#include<fstream>
#include<sstream>

#include "Student.h"
#include "Center.h"
#include "Course.h"

#include "AdmissionSystem.h"

using namespace std;

void load_all_students_with_there_preference(AdmissionSystem& a,vector<Student>& stud1)
{
	for(unsigned i=0;i<a.student.size();i++)
	{
		Student stud;
		stud.setId(a.student[i].getId());
		stud.setName(a.student[i].getName());
		stud.setRankA(a.student[i].getRankA());
		stud.setRankB(a.student[i].getRankB());
		stud.setRankC(a.student[i].getRankC());
		stud.setDegree(a.student[i].getDegree());
		stud.setDegreeMarks(a.student[i].getDegreeMarks());
		stud.setAllocatedPref(a.student[i].getAllocatedPref());
		stud.setCourseName(a.student[i].getCourseName());
		stud.setCenterId(a.student[i].getCenterId());
		stud.setPayment(a.student[i].getPayment());
		stud.setReported(a.student[i].getReported());
		stud.setPrn(a.student[i].getPrn());

		for(unsigned j=0;j<a.preferences.size();j++)
		{
			if(a.student[i].getId() == a.preferences[j].getId())
			{
				stud.add_preferences(a.preferences[j]);
			}
		}
		stud1.push_back(stud);
	}
}

void load_all_center_with_there_courses(AdmissionSystem& a,vector<Center>& cent1)
{
	for(unsigned i=0;i<a.center.size();i++)
	{
		Center cent;
		cent.setId(a.center[i].getCenterId());
		cent.setName(a.center[i].getCenterName());
		cent.setAddress(a.center[i].getAddress());
		cent.setCoordinator(a.center[i].getCoordinator());
		cent.setPassword(a.center[i].getPassword());

		for(unsigned j=0;j<a.capacitie.size();j++)
		{
			if(a.capacitie[j].getCenterId() == a.center[i].getCenterId())
			{
				for(unsigned k=0;k<a.course.size();k++)
				{
					if(a.capacitie[j].getCourseName() == a.course[k].getName())
					{
						//cent.add_courses_in_center(a.course[k]);
						cent.add_courses_to_respective_centers(a.center[i].getCenterId(),k);
					}
				}
			}

		}
		cent1.push_back(cent);
	}
}

void load_all_courses_with_resp_available_centers(AdmissionSystem& a,vector<Course>& cour1)
{
	for(unsigned i=0;i<a.course.size();i++)
	{
		Course cour;
		cour.setId(a.course[i].getId());
		cour.setName(a.course[i].getName());
		cour.setFees(a.course[i].getFees());
		cour.setCcatSection(a.course[i].getSection());

		for(unsigned j=0;j<a.eligibilitie.size();j++)
		{
			if(a.course[i].getName() == a.eligibilitie[j].getCourseName())
			{
				cour.add_eligibilities(a.eligibilitie[j]);
			}
		}

		for(unsigned int k=0;k<a.capacitie.size();k++)
		{
			if(a.capacitie[k].getCourseName() == a.course[i].getName())
			{
				for(unsigned l=0; l<a.center.size();l++)
				{
					if(a.capacitie[k].getCenterId()== a.center[l].getCenterId())
					{
						cour.add_centers(a.center[l]);
					}
				}
			}
		}
		cour1.push_back(cour);
	}

}

int main()
{
	AdmissionSystem a;

	a.load_Files(a);

	vector<Student> stud;
	load_all_students_with_there_preference(a,stud);

/*	for(int i=0;i<stud.size();i++)
	{
		stud[i].display_stud();
	}*/

	vector<Center> cent;
	load_all_center_with_there_courses(a,cent);

	for(unsigned j=0;j<cent.size();j++)
	{
		cent[j].display_Center_with_courses(a);
	}

	vector<Course> cour;
	load_all_courses_with_resp_available_centers(a,cour);

/*	for(int k=0;k<cour.size();k++)
	{
		cour[k].display_Course_with_eligibilities_and_centers();
	}*/






	return 0;
}


//AdmissionSystem a;

/*	Student s1;
vector<preference> pref={};
pref.push_back(preference(10,1,"DAC","SIP"));
Student s(12,"sanket",100,102,104,"B.E.",81.25,0,"DAC","SIP",0,0,"PRN",pref);
s.add_preferences(preference());
s.display_stud();*/

/*	courses c1;
vector<courses> course;
course.push_back(c1);
Center c("SIP","SUNBEAM","SUNBEAM PUNE","NITIN KUDALE","sunbeam",course);
c.add_courses_in_center(courses(10,"DAC",105000,"B"));
c.display_Center_with_courses();*/

/*	Course c;
eligibilities e;
c.add_eligibilities(e);
centers c1;
c.add_centers(c1);
c.display_Course_with_eligibilities_and_centers();*/

/*
	for(unsigned i=0;i<a.degree.size();i++)
	{
		a.degree[i].display_degrees();
	}
	cout<<endl<<endl;

	for(unsigned i=0;i<a.course.size();i++)
	{
		a.course[i].display_courses();
	}
	cout<<endl<<endl<<a.eligibilitie.size()<<" "<<a.center.size()<<" "<<a.capacitie.size();

	for(unsigned i=0;i<a.eligibilitie.size();i++)
	{
		a.eligibilitie[i].display_eligibilities();
	}
	cout<<endl<<endl;

	for(unsigned i=0;i<a.center.size();i++)
	{
		a.center[i].display_centers();
	}
	cout<<endl<<endl;

	for(unsigned i=0;i<a.capacitie.size();i++)
	{
		a.capacitie[i].display_capacities();
	}
	cout<<endl<<endl;

	for(unsigned i=0;i<a.student.size();i++)
	{
		a.student[i].display_students();
	}
	cout<<endl<<endl;

	for(unsigned i=0;i<a.preferences.size();i++)
	{
		a.preferences[i].display_pref();
	}
	cout<<endl<<endl;
*/
