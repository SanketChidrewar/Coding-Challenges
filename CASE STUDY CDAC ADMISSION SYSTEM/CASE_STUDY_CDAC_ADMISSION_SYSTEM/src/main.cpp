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
#include "preference.h"
#include "students.h"


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
bool sort_by_level_CourseName_CenterName_Name(Student& a, Student& b)
{
	if(a.getCourseName() < b.getCourseName())
	{
			return true;
	}
	else if(a.getCourseName() == b.getCourseName())
	{
		if(a.getCenterId() < b.getCenterId())
		{
				return true;
		}
		else if(a.getCenterId() == b.getCenterId())
		{
			if(a.getName() < b.getName())
			{
					return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool sort_by_level_CourseName_CenterName_Fees(Student& a, Student& b)
{
	if(a.getCourseName() < b.getCourseName())
	{
			return true;
	}
	else if(a.getCourseName() == b.getCourseName())
	{
		if(a.getCenterId() < b.getCenterId())
		{
				return true;
		}
		else if(a.getCenterId() == b.getCenterId())
		{
			if(a.getPayment() < b.getPayment())
			{
					return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
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
	//cout<<endl<<"students are "<<stud.size()<<endl;
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

void store_result_after_round_1(AdmissionSystem& a, vector<Student>& stud)
{
	//for storing students capacity file after round 1
	{
		ofstream of;

		of.open("src/results_files/capacitie_after_round_1.csv");

		if(!of)
		{
			cout<<"Unable to open capacitie_after_round_1 file"<<endl;
			return ;
		}

		for(unsigned i=0;i<a.capacitie.size();i++)
		{
			of<<a.capacitie[i].getCenterId()<<","<<a.capacitie[i].getCourseName()<<","<<a.capacitie[i].getCapacity()<<","<<a.capacitie[i].getFilledCapacity()<<endl;
		}
		of.close();
		cout<<"capacitie_after_round_1 is saved successfully "<<endl;
	}


	//for storing studnets updated data
	{
		ofstream of;

		of.open("src/results_files/students_data_after_round_1.csv");

		if(!of)
		{
			cout<<"Unable to open students_data_after_round_1 file"<<endl;
			return ;
		}

		sort(stud.begin(),stud.end(),sort_by_form_no);
		for(unsigned i=0;i<stud.size();i++)
		{
			of<<stud[i].getId()<<","<<stud[i].getName()<<","<<stud[i].getRankA()<<","<<stud[i].getRankB();
			of<<","<<stud[i].getRankC()<<","<<stud[i].getDegree()<<","<<stud[i].getDegreeMarks()<<","<<stud[i].getAllocatedPref();
			of<<","<<stud[i].getCourseName()<<","<<stud[i].getCenterId();
			of<<","<<stud[i].getPayment()<<","<<stud[i].getReported()<<","<<stud[i].getPrn()<<endl;
		}
		of.close();
		cout<<"students_data_after_round_1 is saved successfully "<<endl;
	}

}

void store_result_after_round_2(AdmissionSystem& a, vector<Student>& stud)
{
	//for storing students capacity file after round 2
	{
		ofstream of;

		of.open("src/results_files/capacitie_after_round_2.csv");

		if(!of)
		{
			cout<<"Unable to open capacitie_after_round_2 file"<<endl;
			return ;
		}

		for(unsigned i=0;i<a.capacitie.size();i++)
		{
			of<<a.capacitie[i].getCenterId()<<","<<a.capacitie[i].getCourseName()<<","<<a.capacitie[i].getCapacity()<<","<<a.capacitie[i].getFilledCapacity()<<endl;
		}
		of.close();
		cout<<"capacitie_after_round_2 is saved successfully "<<endl;
	}


	//for storing studnets updated data after round 2
	{
		ofstream of;

		of.open("src/results_files/students_data_after_round_2.csv");

		if(!of)
		{
			cout<<"Unable to open students_data_after_round_2 file"<<endl;
			return ;
		}

		sort(stud.begin(),stud.end(),sort_by_form_no);
		for(unsigned i=0;i<stud.size();i++)
		{
			of<<stud[i].getId()<<","<<stud[i].getName()<<","<<stud[i].getRankA()<<","<<stud[i].getRankB();
			of<<","<<stud[i].getRankC()<<","<<stud[i].getDegree()<<","<<stud[i].getDegreeMarks()<<","<<stud[i].getAllocatedPref();
			of<<","<<stud[i].getCourseName()<<","<<stud[i].getCenterId();
			of<<","<<stud[i].getPayment()<<","<<stud[i].getReported()<<","<<stud[i].getPrn()<<endl;
		}
		of.close();
		cout<<"students_data_after_round_2 is saved successfully "<<endl;
	}
}

// Round 2 allocation

void Allocate_centers_round_2(AdmissionSystem& a,vector<Student>& stud,vector<Center>& cent,vector<Course>& cour)
{
	//for RANK_A STUDENTS
//	sort(stud.begin(),stud.end(),sort_by_rank_a);
	//cout<<endl<<"students are "<<stud.size()<<endl;
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
							if((stud[ii].getPreferences().size() == 0) || (stud[ii].getRankA() == -1) || (stud[ii].getPayment() == -1))
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
								if((stud[ii].getPreferences().size() == 0) || (stud[ii].getRankB() == -1)  || (stud[ii].getPayment() == -1))
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
									if((stud[ii].getPreferences().size() == 0) || (stud[ii].getRankC() == -1)  || (stud[ii].getPayment() == -1))
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

typedef enum{EXIT,STUDENT,ADMIN,CENTER_COORDINATOR}main_menu;
typedef enum{REGISTER_NEW_STUDENT=1,SIGN_IN_STUD,LIST_COURSES,LIST_CENTERS,GIVE_PREFERENCES,SEE_ALLOCATED_CENTER_AND_COURSE,UPDATE_PAYMENT}menu_stud;
typedef enum{SIGN_IN_ADMIN=1,LIST_COURSES_AND_ELIGIBILITIES,LIST_CENTERS_AND_CAPACITIES,LIST_STUDENTS,UPDATE_STUDENT_RANK,ALLOCATE_CENTERS_ROUND_1,ALLOCATE_CENTERS_ROUND_2,LIST_ALLOCATED_STUDENTS,LIST_PAID_STUDENTS,LIST_REPORTED_STUDENTS,GENERATE_PRN,LIST_ADMITTED_STUDENTS}menu_admin;
typedef enum{SIGN_IN_COORDINATOR=1,LIST_COURSE,LIST_STUDENT,UPDATE_REPORTED_STATUS,LIST_ADMITTED_STUDENT}coordinator_menu;

int main_menu_op()
{
	int choice;
	cout<<"\n0.EXIT \n1.STUDENT \n2.ADMIN \n3.CENTER_COORDINATOR"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
}

int student_menu_op(int flag)
{
	int choice;

	if(flag == 0)
	{
	cout<<"\n0.EXIT \n1.REGISTER_NEW_STUDENT \n2.SIGN_IN_STUD "<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
	}
	else
	{
	cout<<"\n0.EXIT \n3.LIST_COURSES \n4.LIST_CENTERS \n5.GIVE_PREFERENCES \n6.SEE_ALLOCATED_CENTER_AND_COURSE \n7.UPDATE_PAYMENT"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
	}
}

int admin_menu_op(int flag)
{
	int choice;
	if(flag == 0)
	{
		cout<<"\n0.EXIT \n1.SIGN_IN_ADMIN"<<endl;
		cout<<"ENTER YOUR CHOICE :";
		cin>>choice;
		return choice;
	}
	else
	{
	cout<<"\n0.EXIT \n2.LIST_COURSES_AND_ELIGIBILITIES \n3.LIST_CENTERS_AND_CAPACITIES \n4.LIST_STUDENTS \n5.UPDATE_STUDENT_RANK \n6.ALLOCATE_CENTERS_ROUND_1 \n7.ALLOCATE_CENTERS_ROUND_2 \n8.LIST_ALLOCATED_STUDENTS \n9.LIST_PAID_STUDENTS \n10.LIST_REPORTED_STUDENTS \n11.GENERATE_PRN \n12.LIST_ADMITTED_STUDENTS"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
	}
}

int coordinator_menu_op(int flag)
{
	int choice;
	if(flag == 0)
	{
		cout<<"\n0.EXIT \n1.SIGN_IN_COORDINATOR "<<endl;
		cout<<"ENTER YOUR CHOICE :";
		cin>>choice;
		return choice;
	}
	else
	{
	cout<<"\n0.EXIT \n2.LIST_COURSE \n3.LIST_STUDENT \n4.UPDATE_REPORTED_STATUS \n5.LIST_ADMITTED_STUDENT"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
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


	int choice;
	int rank;
	int form_no;
	int flag = 0,flag1=0;
	int username;
	int count = 0;
	string username_admin;
	string password;
	string center_id_for_coordinator_login;
	string pass_for_coordinator_login;
	int payment_amount;
	int pref_no;
	string pref_course_name;
	string pref_center_id;
	int rank1,rank2,rank3;
	string course_name;
	int rep_status;

	while((choice = main_menu_op())!=EXIT)
	{
		switch(choice)
		{
		case STUDENT:
			flag = 0 ;
			while((choice = student_menu_op(flag))!=EXIT)
			{
				students s;
				Student st;
				int stud_int;
				string stud_string;
				preference p;
				int no_of_pref;

				switch(choice)
				{

				case REGISTER_NEW_STUDENT:
					flag = 0 ;
					cout<<"ENTER FORM No :";
					cin>>stud_int;
					s.setId(stud_int);

					cout<<"ENTER NAME :";
					cin>>stud_string;
					s.setName(stud_string);

					//cout<<"ENTER RANK OF SECTION A :";
					//cin>>stud_int;
					s.setRankA(-1);

					//cout<<"ENTER RANK OF SECTION B :";
					//cin>>stud_int;
					s.setRankB(-1);

					//cout<<"ENTER RANK OF SECTION C :";
					//cin>>stud_int;
					s.setRankC(-1);

					cout<<"ENTER DEGREE NAME:";
					getchar();
					//cin>>stud_string;
					getline(cin,stud_string);
					s.setDegree(stud_string);

					cout<<"ENTER DEGREE percentage :";
					cin>>stud_int;
					flag1 = 0;
					for(unsigned i=0;i<a.degree.size();i++)
					{
						string s = a.degree[i].getDegree();
						if(stud_string == s)
						{
							flag1=1;
						}
					}
					if(flag1 == 0)
					{
						cout<<"\n###ENTERED DEGREE IS NOT ELIGIBLE###"<<endl;
						break;
					}

					s.setDegreeMarks(stud_int);
					s.setAllocatedPref(0);
					s.setCenterId("NA");
					s.setCourseName("NA");
					s.setPayment(0);
					s.setReported(0);
					s.setPrn("NA");

					//s.display_students();

					a.student.push_back(s);

					st.setId(s.getId());
					st.setName(s.getName());
					st.setRankA(s.getRankA());
					st.setRankB(s.getRankB());
					st.setRankC(s.getRankC());
					st.setDegree(s.getDegree());
					st.setDegreeMarks(s.getDegreeMarks());
					st.setAllocatedPref(s.getAllocatedPref());
					st.setCourseName(s.getCourseName());
					st.setCenterId(s.getCenterId());
					st.setPayment(s.getPayment());
					st.setReported(s.getReported());
					st.setPrn(s.getPrn());

					stud.push_back(st);
					getchar();

					break;

				case SIGN_IN_STUD:
					flag =0;
					cout<<"ENTER FORM NO AS USERNAME & NAME AS PASSWORD FOR STUDENT LOGIN"<<endl;
					cout<<"ENTER USERNAME :";
					cin>>username;
					cout<<"ENTER PASSWORD :";
					cin>>password;

					for(unsigned i=0;i<stud.size();i++)
					{
						if((username == stud[i].getId()) && (password == stud[i].getName()))
						{
							cout<<"\n===LOGGED IN SUCCESSFULLY TO STUDENT PORTAL==="<<endl;
							cout<<"\tFORM NO :"<<username<<endl;
							cout<<"\tSTUDENT NAME :"<<password<<endl;
							flag =1;
							break;
						}
					}
					if(flag == 0)
					{
							cout<<"PLEASE ENTER CORRECT USERNAME & PASSWORD "<<endl;
					}
					break;

				case LIST_COURSES:
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getId() == username)
						{
							for(unsigned j=0;j<a.eligibilitie.size();j++)
							{
								if(a.eligibilitie[j].getDegree() == stud[i].getDegree())
								{
									if(stud[i].getDegreeMarks() >= a.eligibilitie[j].getMinPer())
									{
										cout<<a.eligibilitie[j].getCourseName()<<endl;
									}
								}
							}
							break;
						}
					}

					break;

				case LIST_CENTERS:
					for(unsigned i=0 ; i<a.center.size();i++)
					{
						a.center[i].display_centers();
					}
					break;

				case GIVE_PREFERENCES:

					cout<<"ENTER NO OF PREF YOU WANT TO ADD :";
					cin>>no_of_pref;

					cout<<"\nCOURSES AND CENTERS YOU ARE ELIGIBLE IN :\n"<<endl;
					for(unsigned k=0;k<cour.size();k++)
					{
						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == username)
							{
								for(unsigned j=0;j<a.eligibilitie.size();j++)
								{
									if(a.eligibilitie[j].getDegree() == stud[i].getDegree())
									{
										if(stud[i].getDegreeMarks() >= a.eligibilitie[j].getMinPer())
										{
											if(cour[k].getName()== a.eligibilitie[j].getCourseName())
												{
													cour[k].display_Course_with_centers(a);
												}
										}
									}
								}
							}
						}
					}

					for(int k=0;k<no_of_pref;k++)
					{
						flag1 =0;

						p.setId(username);
						cout<<"ENTER PREF NO :";
						cin>>pref_no;
						p.setPrefNo(pref_no);
						cout<<"ENTER COURSE NAME :";
						cin>>pref_course_name;
						p.setCourseName(pref_course_name);
						cout<<"ENTER CENTER ID :";
						cin>>pref_center_id;
						p.setCenterId(pref_center_id);

						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == username)
							{
								for(unsigned j=0;j<a.eligibilitie.size();j++)
								{
									if(a.eligibilitie[j].getDegree() == stud[i].getDegree())
									{
										if(p.getCourseName() == a.eligibilitie[j].getCourseName())
										{
											if(stud[i].getDegreeMarks() >= a.eligibilitie[j].getMinPer())
											{
												cout<<"STIUDENT IS ELIGIBLE FOR THIS PREFERENCE :"<<endl;
												a.preferences.push_back(p);
												stud[i].add_preferences(p);
												cout<<"PREFERENCE IS ADDED TO PREFERENCE FILE";
												flag1 = 1;
											}
										}
									}
								}
							}
						}
						if(flag1 == 0)
						{
							cout<<"STUDENT IS NOT ELIGIBLE TO ADD THIS PREFERENCE "<<endl;
						}
					}
					break;

				case SEE_ALLOCATED_CENTER_AND_COURSE:
					flag1 =0;
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getId() == username)
						{
							if(stud[i].getCenterId() != "NA")
							{
								cout<<"ALLOCATED CENTER ID & COURSE OF FORM NO "<<form_no<<" IS "<<endl;
								cout<<" ALLOCATED CENTER ID :"<<stud[i].getCenterId()<<endl;
								cout<<" ALLOCATED COURSE    :"<<stud[i].getCourseName()<<endl;
								flag1 =1;
								break;
							}
						}
					}
					if(flag1 == 0)
					{
						cout<<"NOT ALLOCATED ANY CENTER YET "<<endl;
					}
					break;

				case UPDATE_PAYMENT:
					flag1 =0;
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getId() == username)
						{
							if(stud[i].getCenterId() != "NA")
							{
								for(unsigned j=0;j<cour.size();j++)
								{
									if(stud[i].getCourseName() == cour[j].getName())
									{
										cout<<"FEES PAID BY STUDENT :"<<stud[i].getPayment()<<endl;
										cout<<"REMAINING FEES OF THIS STUDENT IS :"<<cour[j].getFees()-stud[i].getPayment()<<endl;
									}
								}
								cout<<"ENTER PAYMENT AMOUT :";
								cin>>payment_amount;
								stud[i].setPayment(stud[i].getPayment() + payment_amount);
								cout<<"PAYMENT IS SUCCESSFULLY ADDED TO FROM NO "<<form_no<<" WITH AMOUNT "<<payment_amount<<endl;
								flag1 =1;
								break;
							}
						}
					}
					if(flag1 == 0)
					{
						cout<<"NOT ALLOCATED ANY CENTER YET TO PAY "<<endl;
					}
					break;

				}
			}
			break;

		case ADMIN:
			flag = 0;
			while((choice = admin_menu_op(flag))!=EXIT)
			{
				switch(choice)
				{
				case SIGN_IN_ADMIN:
					flag = 0;
					cout<<"ENTER USERNAME :";
					cin>>username_admin;
					cout<<"ENTER PASSWORD :";
					cin>>password;

					for(unsigned i=0;i<a.center.size();i++)
					{
						if((username_admin == "admin") && (password == "admin"))
						{
							cout<<"===LOGGED IN SUCCESSFULLY TO ADMIN PORTAL==="<<endl;
							flag =1;
							break;
						}
						else
						{
							cout<<"PLEASE ENTER CORRECT USERNAME & PASSWORD "<<endl;
							break;
						}
					}
					break;

				case LIST_COURSES_AND_ELIGIBILITIES:
					for(unsigned i=0;i<cour.size();i++)
					{
						cour[i].display_Course_with_eligibilities();
					}
					break;

				case LIST_CENTERS_AND_CAPACITIES:

					for(unsigned i=0;i<a.capacitie.size();i++)
					{
						a.capacitie[i].display_capacities();
					}

					break;

				case LIST_STUDENTS:
					for(unsigned i=0;i<stud.size();i++)
					{
						stud[i].display_only_stud();
					}
					break;

				case UPDATE_STUDENT_RANK:
					cout<<"ENTER FORM NO : ";
					cin>>form_no;
					cout<<"\n1.RANK_1_UPDATION \n2.RANK_2_UPDATION \n3.RANK_3_UPDATION \n4.ALL_RANKS"<<endl;
					cout<<"ENTER OPTION :";
					cin>>choice;

					switch(choice)
					{
					case 1:
						cout<<"ENTER RANK 1 TO BE UPDATED :";
						cin>>rank;
						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == form_no)
							{
								stud[i].display_only_stud();
								stud[i].setRankA(rank);
								stud[i].display_only_stud();
							}
						}
						cout<<"RANK OF FORM NO "<<form_no<<" IS SUCCESSFULLY UPDATED TO "<<rank<<endl;
						break;
					case 2:
						cout<<"ENTER RANK 2 TO BE UPDATED :";
						cin>>rank;
						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == form_no)
							{
								stud[i].display_only_stud();
								stud[i].setRankB(rank);
								stud[i].display_only_stud();
							}
						}
						cout<<"RANK OF FORM NO"<<form_no<<" IS SUCCESSFULLY UPDATED TO "<<rank<<endl;
						break;
					case 3:
						cout<<"ENTER RANK 3 TO BE UPDATED :";
						cin>>rank;
						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == form_no)
							{
								stud[i].display_only_stud();
								stud[i].setRankC(rank);
								stud[i].display_only_stud();
							}
						}
						cout<<"RANK OF FORM NO"<<form_no<<" IS SUCCESSFULLY UPDATED TO "<<rank<<endl;
						break;
					case 4:
						cout<<"ENTER RANK 1 TO BE UPDATED :";
						cin>>rank1;
						cout<<"ENTER RANK 2 TO BE UPDATED :";
						cin>>rank2;
						cout<<"ENTER RANK 3 TO BE UPDATED :";
						cin>>rank3;
						for(unsigned i=0;i<stud.size();i++)
						{
							if(stud[i].getId() == form_no)
							{
								stud[i].display_only_stud();
								stud[i].setRankA(rank1);
								stud[i].setRankB(rank2);
								stud[i].setRankC(rank3);
								stud[i].display_only_stud();
							}
						}
						cout<<"RANK OF FORM NO"<<form_no<<" IS SUCCESSFULLY UPDATED TO "<<rank<<endl;
						break;
					default:
						cout<<"ENTER VALID OPTION :"<<endl;
					}

					break;

				case ALLOCATE_CENTERS_ROUND_1:

					Allocate_centers_round_1(a,stud,cent,cour); // fun for round 1
					cout<<"ROUND 1 ALLOCATION IS DONE SUCCESSFULLY "<<endl;
					store_result_after_round_1(a,stud); // storing round 1 result

					break;

				case ALLOCATE_CENTERS_ROUND_2:
					//modify payment status according set 1 //
					sort(stud.begin(),stud.end(),sort_by_form_no);

					for(unsigned i=0;i<stud.size();i++)
					{
						vector<int> paid_form_num = {4,14,26,33,39,47,54,81,86,92,93,97,99,106,108,110,126,127,141,162,169};
						for(unsigned j=0;j<paid_form_num.size();j++)
						{
							if(stud[i].getId() == paid_form_num[j] )
							{
								stud[i].setPayment(11800);
							}
						}
					}

					//modify capacity & remove allocated center value in stud file for unpaid students according set 1 //

					for(unsigned i=0;i<stud.size();i++)
					{
						vector<int> non_paid_form_num = {11,28,31,36,37,45,56,75,78,83,102,109,116,135,139,142,160,168};
						for(unsigned j=0;j<non_paid_form_num.size();j++)
						{
							if(stud[i].getId() == non_paid_form_num[j] )
							{
								for(unsigned k=0;k<a.capacitie.size();k++)
								{
									if((stud[i].getCenterId() == a.capacitie[k].getCenterId()) && (stud[i].getCourseName() == a.capacitie[k].getCourseName()))
										{
											stud[i].setAllocatedPref(0);
											stud[i].setCenterId("NA");
											stud[i].setCourseName("NA");
											a.capacitie[k].setFilledCapacity( (a.capacitie[k].getFilledCapacity() - 1) );
											stud[i].setPayment(-1);
										}
								}
							}
						}
					}

					// Reset capacity file for round 2

					for(unsigned i=0;i<a.capacitie.size();i++)
					{
						a.capacitie[i].setFilledCapacity(0);
					}

					   Allocate_centers_round_2(a,stud,cent,cour); // fun for round 2

						cout<<"ROUND 2 ALLOCATION IS DONE SUCCESSFULLY "<<endl;

						store_result_after_round_2(a,stud); // storing round 2 result

					break;

				case LIST_ALLOCATED_STUDENTS:

					cout<<endl<<"LIST OF ALLOCATED STUDENTS"<<endl;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getAllocatedPref() != 0)
						{
						stud[i].display_stud();
						}
					}

					break;

				case LIST_PAID_STUDENTS:
					flag1 = 0;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Fees);
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getPayment() != 0 && stud[i].getPayment() != -1)
						{
							if(flag1 == 0 )
							{
								cout<<endl<<"LIST OF PAID STUDENTS"<<endl;
							}
						stud[i].display_stud();
						flag1 = 1;
						}
					}
					if(flag1 == 0)
					{
						cout<<"THERE IS NO ANY PAID STUDENT IN LIST "<<endl;
					}
					break;

				case LIST_REPORTED_STUDENTS:
					flag1 = 0;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getReported() == 1)
						{
						stud[i].display_stud();
						flag1 = 1;
						}
					}
					if(flag1 == 0)
					{
						cout<<"NO ANY STUDENT IS REPORTED TO ANY CENTER YET "<<endl;
					}
					break;

				case GENERATE_PRN:
					flag1 = 0;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getReported() == 1)
						{
							for(unsigned j =0;j<cour.size();j++)
							{
								if(stud[i].getPayment() == cour[j].getFees())
								{
									if(stud[i].getCourseName() == cour[j].getName())
									{
										count++;
										stringstream ss;
										ss<<stud[i].getCourseName()<<stud[i].getCenterId()<<"_"<<"_"<<count;
										string s;
										getline(ss,s);
										stud[i].setPrn(s);
										flag1 = 1;
									}
								}
							}
						}
					}
					if(flag1 == 1)
					{
						cout<<"PRN GENERATION OF REPORTED AND FULLY PAID STUDENTS IS SUCCESSFULLY GENERATED "<<endl;
					}
					else if(flag1 == 0)
					{
						cout<<"THERE IS NO ANY STUDENT WHO IS FULY PAID & REPORTED TO CENTER FOR PRN GENERATION "<<endl;
					}

					break;

				case LIST_ADMITTED_STUDENTS:
					flag1 = 0;
					cout<<"ENTER COURSE NAME :";
					cin>>course_name;
					cout<<"ENTER CENTER ID TO GET IT'S ADMITTED STUDENTS :";
					cin>>center_id_for_coordinator_login;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if((stud[i].getCenterId() == center_id_for_coordinator_login) && (stud[i].getCourseName() == course_name)  && (stud[i].getReported() != 0)  &&  (stud[i].getPrn() != "NA"))
						{
							stud[i].display_only_stud();
							flag1 = 1;
						}
					}
					if(flag1 == 0)
					{
						cout<<"NO ANY STUDENT ADMITTED TO CENTER "<<center_id_for_coordinator_login<<" YET"<<endl;
					}
					break;
				}
			}

			break;

		case CENTER_COORDINATOR:
			flag =0;
			while((choice = coordinator_menu_op(flag))!=EXIT)
			{
				switch(choice)
				{
				case SIGN_IN_COORDINATOR:
					flag =0;
					cout<<"ENTER CENTER ID :";
					cin>>center_id_for_coordinator_login;
					cout<<"ENTER PASSWORD :";
					cin>>pass_for_coordinator_login;

					for(unsigned i=0;i<a.center.size();i++)
					{
						if((a.center[i].getCenterId() == center_id_for_coordinator_login) && (a.center[i].getPassword() == pass_for_coordinator_login))
						{
							cout<<"===LOGGED IN SUCCESSFULLY TO CENTER "<<center_id_for_coordinator_login<<"==="<<endl;
							flag =1;
							break;
						}
						else
						{
							cout<<"PLEASE ENTER CORRECT CENTER ID & PASSWORD "<<endl;
							break;
						}
					}
					break;

				case LIST_COURSE:
					for(unsigned i=0;i<cent.size();i++)
					{
						if(cent[i].getId() == center_id_for_coordinator_login)
						{

							cent[i].display_Center_with_courses(a);

//							auto it = cent[i].getCenterIdCourses().begin();
//							while(it != cent[i].getCenterIdCourses().end())
//							{
//								a.course[it->second].display_courses();
//							}
						}
					}
					break;

				case LIST_STUDENT:
					flag1 = 0;
					cout<<"ENTER COURSE NAME :";
					cin>>course_name;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getCenterId() == center_id_for_coordinator_login)
						{
							if(stud[i].getCourseName() == course_name)
							{
								stud[i].display_only_stud();
								flag1 = 1;
							}
						}
					}
					if(flag1 == 0)
					{
						cout<<"NO ANY STUDENT IS ALLOCATED TO CENTER "<<center_id_for_coordinator_login<<" YET"<<endl;
					}
					break;

				case UPDATE_REPORTED_STATUS:
					flag1 = 0;
					cout<<"ENTER FORM NUMBER TO UPDATE_REPORTED_STATUS :";
					cin>>form_no;
					cout<<"ENTER REPORTED STATUS :";
					cin>>rep_status;
					for(unsigned i=0;i<stud.size();i++)
					{
						if(stud[i].getId() == form_no)
						{
							if(stud[i].getCenterId() == center_id_for_coordinator_login)
							{
							stud[i].setReported(rep_status);
							cout<<"REPORTED STATUS OF STUDENT HAVING FORM NO "<<form_no<<" IS UPDATED SUCCESSFULLY ";
							flag1=1;
							break;
							}
						}
					}
					if(flag1 == 0)
					{
						cout<<"NO ANY SEAT IS ALLOCATED TO THIS STUDENT AT THIS CENTER "<<center_id_for_coordinator_login<<endl;
					}
					break;

				case LIST_ADMITTED_STUDENT:
					flag1 = 0;
					cout<<"ENTER COURSE NAME :";
					cin>>course_name;
					sort(stud.begin(),stud.end(),sort_by_level_CourseName_CenterName_Name);
					for(unsigned i=0;i<stud.size();i++)
					{
						if((stud[i].getCenterId() == center_id_for_coordinator_login) && (stud[i].getCourseName() == course_name)  && (stud[i].getReported() != 0)  &&  (stud[i].getPrn() != "NA"))
						{
							stud[i].display_only_stud();
							flag1 = 1;
						}
					}
					if(flag1 == 0)
					{
						cout<<" STILL NO ANY STUDENT ADMITTED TO CENTER "<<center_id_for_coordinator_login<<endl;
					}
					break;
				}
			}
			break;
		}
	}

	return 0;
}


/*		//modify payment status according set 2//
		sort(stud.begin(),stud.end(),sort_by_form_no);

		for(unsigned i=0;i<stud.size();i++)
		{
			vector<int> paid_form_num = {4,67,125,97,168,102,52,113,61,31,24,167,114,11,14,99,26,89,37,124,137,36,101,110,150,156,119,115,157,160,123};
			for(unsigned j=0;j<paid_form_num.size();j++)
			{
				if(stud[i].getId() == paid_form_num[j] )
				{
					stud[i].setPayment(11800);
				}
			}
		}*/

	// to check payment modified list
/*		cout<<"STUDENTS PAID 11800"<<endl;
	for(unsigned i=0;i<stud.size();i++)
	{
		if(stud[i].getPayment() == 11800)
		{
		stud[i].display_stud();
		}
	}*/



/*
		//modify capacity & remove allocated center value in stud file for unpaid students according set 2//

		for(unsigned i=0;i<stud.size();i++)
		{
			vector<int> non_paid_form_num = {6,10,50,16,174,108,93,106};
			for(unsigned j=0;j<non_paid_form_num.size();j++)
			{
				if(stud[i].getId() == non_paid_form_num[j] )
				{
					for(unsigned k=0;k<a.capacitie.size();k++)
					{
						if((stud[i].getCenterId() == a.capacitie[k].getCenterId()) && (stud[i].getCourseName() == a.capacitie[k].getCourseName()))
							{
								stud[i].setAllocatedPref(0);
								stud[i].setCenterId("NA");
								stud[i].setCourseName("NA");
								a.capacitie[k].setFilledCapacity( (a.capacitie[k].getFilledCapacity() - 1) );
								stud[i].setPayment(-1);
							}
					}
				}
			}
		}
*/


/*		for(unsigned i=0;i<stud.size();i++)
		{
			if(stud[i].getAllocatedPref() != 0)
			//if(stud[i].getPayment() == -1)
			{
			stud[i].display_stud();
			}
		}*/



	// To check capacity modified status
/*	for(unsigned i=0;i<a.capacitie.size();i++)
	{
		a.capacitie[i].display_capacities();
	}*/


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
