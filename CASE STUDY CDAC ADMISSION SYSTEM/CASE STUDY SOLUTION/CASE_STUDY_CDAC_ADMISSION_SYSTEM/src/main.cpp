/*
 * main.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>

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
						cour.add_centers(a.course[i].getId(),l);
					}
				}
			}
		}
		cour1.push_back(cour);
	}
}

bool sort_by_rank_a(Student& a, Student& b)
{
	return (a.getRankA() < b.getRankA()) ? true : false ;
}
bool sort_by_rank_b(Student& a, Student& b)
{
	return (a.getRankB() < b.getRankB()) ? true : false ;
}
bool sort_by_rank_c(Student& a, Student& b)
{
	return (a.getRankC() < b.getRankC()) ? true : false ;
}
bool sort_by_form_no(Student& a, Student& b)
{
	return (a.getId() < b.getId()) ? true : false ;
}



//- Algorithm for your reference:
//for n in 1 to 10:
//    //"n"th preference allocation
//    sort students by rank_a
//    if "n"th preference is of 'A' section course:
//	allocate course at that center to the student
//	increase filled count of that center for that course
//    sort students by rank_b
//    if "n"th preference is of 'B' section course:
//	allocate course at that center to the student
//	increase filled count of that center for that course
//    sort students by rank_c
//    if "n"th preference is of 'C' section course:
//	allocate course at that center to the student
//	increase filled count of that center for that course

void Allocate_centers_round_1(AdmissionSystem& a,vector<Student>& stud,vector<Center>& cent,vector<Course>& cour)
{
	//for RANK_A STUDENTS
//	sort(stud.begin(),stud.end(),sort_by_rank_a);
	cout<<endl<<"students are "<<stud.size()<<endl;
//	for(unsigned i=0;i<stud.size();i++)
//	{
//		stud[i].display_stud();
//	}
	for(int i=0;i<10;i++)
	{
		// FOR RANK A COURSES
		sort(stud.begin(),stud.end(),sort_by_rank_a);
//		cout<<endl<<endl;
//		cout<<"STUDENT SORTED BY RANK A"<<endl;
			for(unsigned j=0;j<cour.size();j++)
			{
				//cout<<"INSIDE COURSE FILE"<<endl;
				if(cour[j].getCcatSection() == "A" )
				{
				//cout<<"INSIDE COURSE HAVING SECTION A"<<endl;

					auto it = cour[j].getCentersOfRespectiveCourses().begin();
					while(it != cour[j].getCentersOfRespectiveCourses().end())
					{
						//cout<<"ITERATING FOR CENTERS AVAILABLE"<<endl;
						//cout<<a.center[it->second].getCenterId()<<"  "<<cour[j].getName()<<endl;
						for(unsigned ii=0;ii<stud.size();ii++)
						{
							if((stud[ii].getPreferences().size() == 0) || (stud[ii].getRankA() == -1))
							{
								continue;
							}
							if(!a.is_seats_are_full(a.center[it->second].getCenterId(),cour[j].getName()))
							{
//								cout<<stud[ii].getId();
//								cout<<"SEATS ARE NOT FULL"<<endl;
									if((stud[ii].getPreferences()[i].getCenterId() == a.center[it->second].getCenterId()) && (stud[ii].getPreferences()[i].getCourseName() == cour[j].getName()) && (stud[ii].getPreferences().size() > 0 ) && (stud[ii].getRankA() != -1))
									{
//										cout<<"ALLOCATING SEAT TO STUDENT & INCREASING CAPA COUNT"<<endl;
										stud[ii].setAllocatedPref(i+1);
										stud[ii].setCenterId(stud[ii].getPreferences()[i].getCenterId());
										stud[ii].setCourseName(stud[ii].getPreferences()[i].getCourseName());

										a.increment_capacity_size_by_one(a.center[it->second].getCenterId(),cour[j].getName());
									}
							}
						}
						it++;
					}
				}
			}



			// FOR RANK B COURSES
			sort(stud.begin(),stud.end(),sort_by_rank_b);
	//		cout<<endl<<endl;
	//		cout<<"STUDENT SORTED BY RANK A"<<endl;
				for(unsigned j=0;j<cour.size();j++)
				{
					//cout<<"INSIDE COURSE FILE"<<endl;
					if(cour[j].getCcatSection() == "B" )
					{
					//cout<<"INSIDE COURSE HAVING SECTION A"<<endl;

						auto it = cour[j].getCentersOfRespectiveCourses().begin();
						while(it != cour[j].getCentersOfRespectiveCourses().end())
						{
							//cout<<"ITERATING FOR CENTERS AVAILABLE"<<endl;
							//cout<<a.center[it->second].getCenterId()<<"  "<<cour[j].getName()<<endl;
							for(unsigned ii=0;ii<stud.size();ii++)
							{
								if((stud[ii].getPreferences().size() == 0) || (stud[ii].getRankB() == -1))
								{
									continue;
								}
								if(!a.is_seats_are_full(a.center[it->second].getCenterId(),cour[j].getName()))
								{
	//								cout<<stud[ii].getId();
	//								cout<<"SEATS ARE NOT FULL"<<endl;
										if((stud[ii].getPreferences()[i].getCenterId() == a.center[it->second].getCenterId()) && (stud[ii].getPreferences()[i].getCourseName() == cour[j].getName()) && (stud[ii].getPreferences().size() > 0 ) && (stud[ii].getRankB() != -1))
										{
	//										cout<<"ALLOCATING SEAT TO STUDENT & INCREASING CAPA COUNT"<<endl;
											stud[ii].setAllocatedPref(i+1);
											stud[ii].setCenterId(stud[ii].getPreferences()[i].getCenterId());
											stud[ii].setCourseName(stud[ii].getPreferences()[i].getCourseName());

											a.increment_capacity_size_by_one(a.center[it->second].getCenterId(),cour[j].getName());
										}
								}
							}
							it++;
						}
					}
				}


				// FOR RANK C COURSES
				sort(stud.begin(),stud.end(),sort_by_rank_c);
		//		cout<<endl<<endl;
		//		cout<<"STUDENT SORTED BY RANK A"<<endl;
					for(unsigned j=0;j<cour.size();j++)
					{
						//cout<<"INSIDE COURSE FILE"<<endl;
						if(cour[j].getCcatSection() == "C" )
						{
						//cout<<"INSIDE COURSE HAVING SECTION A"<<endl;

							auto it = cour[j].getCentersOfRespectiveCourses().begin();
							while(it != cour[j].getCentersOfRespectiveCourses().end())
							{
								//cout<<"ITERATING FOR CENTERS AVAILABLE"<<endl;
								//cout<<a.center[it->second].getCenterId()<<"  "<<cour[j].getName()<<endl;
								for(unsigned ii=0;ii<stud.size();ii++)
								{
									if(stud[ii].getPreferences().size() == 0 || stud[ii].getRankC() == -1)
									{
										continue;
									}
									if(!a.is_seats_are_full(a.center[it->second].getCenterId(),cour[j].getName()))
									{
		//								cout<<stud[ii].getId();
		//								cout<<"SEATS ARE NOT FULL"<<endl;
											if((stud[ii].getPreferences()[i].getCenterId() == a.center[it->second].getCenterId()) && (stud[ii].getPreferences()[i].getCourseName() == cour[j].getName()) && (stud[ii].getPreferences().size() > 0 ) && (stud[ii].getRankC() != -1))
											{
		//										cout<<"ALLOCATING SEAT TO STUDENT & INCREASING CAPA COUNT"<<endl;
												stud[ii].setAllocatedPref(i+1);
												stud[ii].setCenterId(stud[ii].getPreferences()[i].getCenterId());
												stud[ii].setCourseName(stud[ii].getPreferences()[i].getCourseName());

												a.increment_capacity_size_by_one(a.center[it->second].getCenterId(),cour[j].getName());
											}
									}
								}
								it++;
							}
						}
					}
	}

}


int main()
{
	AdmissionSystem a;

	a.load_Files(a);

	vector<Student> stud;
	load_all_students_with_there_preference(a,stud);

/*	for(unsigned i=0;i<stud.size();i++)
	{
		stud[i].display_stud();
	}*/

	vector<Center> cent;
	load_all_center_with_there_courses(a,cent);

/*	for(unsigned j=0;j<cent.size();j++)
	{
		cent[j].display_Center_with_courses(a);
	}*/

	vector<Course> cour;
	load_all_courses_with_resp_available_centers(a,cour);

/*	for(unsigned k=0;k<cour.size();k++)
	{
		cour[k].display_Course_with_eligibilities_and_centers(a);
	}*/

	Allocate_centers_round_1(a,stud,cent,cour);
	cout<<"ALLOCATION DONE FOR ROUND 1"<<endl;
	sort(stud.begin(),stud.end(),sort_by_form_no);
	for(unsigned i=0;i<stud.size();i++)
	{
		if(stud[i].getAllocatedPref() != 0)
		{
		stud[i].display_stud();
		}
	}
	cout<<endl<<endl;
	for(unsigned i=0;i<a.capacitie.size();i++)
	{
		a.capacitie[i].display_capacities();
	}


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
