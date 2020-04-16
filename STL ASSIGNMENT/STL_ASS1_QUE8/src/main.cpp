/*
 * main.cpp
 *
 *  Created on: 15-Apr-2020
 *      Author: sunbeam
 */

//8. Create a student class storing roll number, name (use char[] not string) and marks. Write a menu
//driven File IO program using C++ library classes to add student, display all students, find student
//by roll number and edit student.

#include<iostream>
#include "Student.h"
#include<cstring>
#include<vector>
#include<fstream>

using namespace std;

typedef enum{EXIT,ADD_STUDENT,FIND_STUDENT,DISPLAY_ALL_STUDENT,EDIT_STUDENT}menuop;

void load_student_data(vector<Student>&st)
{

	ifstream is;
	Student obj;

	is.open("src/student.txt",ios::in);

	if(!is)
	{
		cout << "failed to open file" << endl;
	}
	else
	{
	    while (!is.eof())
		{
			is.read((char*)&obj,sizeof(obj));
			st.push_back(obj);
		}
	}
	vector<Student>::iterator it = st.end();
	st.erase(it);
}

int menuChoice()
{
	int ch;
	cout<<"ENTER \n0. EXIT \n1. ADD_STUDENT \n2. FIND_STUDENT \n3. DISPLAY_ALL_STUDENT \n4. EDIT_STUDENT\nENTER OPTION :";
	cin>>ch;
	return ch;
}

void add_student(vector<Student>&st)
{
	int rn;
	char name[50];
	int marks;

	cout<<" ENTER roll no :";
	cin>>rn;
	cout<<" ENTER name :";
	cin>>name;
	cout<<" ENTER marks :";
	cin>>marks;

	//Student st_obj(rn,name,marks);
	st.push_back(Student(rn,name,marks));
	//cout<<"SIZE :"<<st.size()<<endl;
}

void find_student(vector<Student>& st)
{
	int rn,flag=0;
	cout<<"Enter roll no of student :";
	cin>>rn;
	for(unsigned int i=0;i<st.size();i++)
	{
		if(st[i].getRollNumber() == rn)
		{
			st[i].display_student();
			flag =1;
		}
	}

	if(flag==0)
	{
		cout<<"===DATA NOT FOUND==="<<endl;
	}
}

void display_all_student(vector<Student>& st)
{
	cout<<endl<<"===ALL STUDENT DATA==="<<endl;
	for(unsigned int i=0;i<st.size();i++)
	{
		st[i].display_student();
	}
	cout<<endl;
}

void edit_student(vector<Student>& st)
{
	int rn,flag=0;

	char name[50];
	int marks;

	cout<<"Enter roll no of student :";
	cin>>rn;
	for(unsigned int i=0;i<st.size();i++)
	{
		if(st[i].getRollNumber() == rn)
		{
			cout<<"ENTER NAME TO BE UPDATED :";
			cin>>name;
			cout<<"ENTER MARKS TO BE UPDATED :";
			cin>>marks;

			st[i].setName(name);
			st[i].setMarks(marks);

			cout<<endl<<"===DATA SUCCESSFULLY UPDATED==="<<endl<<endl;
			flag =1;
		}
	}

	if(flag==0)
	{
		cout<<"===DATA NOT FOUND==="<<endl;
	}

}

void upload_student_data(vector<Student>&st)
{

	ofstream os;
	os.open("src/student.txt",ios::trunc);

	if(!os)
	{
		cout << "failed to open file" << endl;
	}
	else
	{
		for(unsigned int i=0;i<st.size();i++)
		{
			os.write((const char*)&st[i],sizeof(st[i]));
		}
	}
}

int main()
{
	int choice;
	vector<Student> st;

	load_student_data(st);

	while((choice = menuChoice())!=EXIT)
	{
		switch(choice)
		{
		case ADD_STUDENT:
			add_student(st);
			break;
		case FIND_STUDENT:
			find_student(st);
			break;
		case DISPLAY_ALL_STUDENT:
			display_all_student(st);
			break;
		case EDIT_STUDENT:
			edit_student(st);
			break;
		}
	}

	upload_student_data(st);

	return 0;
}




