/*
 2) Write a menu driven program for class Student. In Main Create Array of Objects and
 	provide facility for Accept, Print, Search and Sort. For student accept name, gender,
	roll number and marks of three subjects from user and print name, roll number , gender and
	percentage. Provide global function e.g. “SortRecord ()” for sorting array. When we
	search 	a particular student in an array and if it is founds show all record of that
	student otherwise show some error message.*/


#include<iostream>
#include<cstring>
#include <cstdlib>

using namespace std;

typedef enum menu{EXIT,ACCEPT_3_STUDENT_INFO,PRINT_STUDENT_INFO,SEARCH_STUDENT_INFO,SORT_STUDENT_INFO}menuop;

class Marks_of_subject
 {

	private:
		int marks;

	public:

	int getMarks() const {
		return marks;
	}

	void setMarks(int marks) {
		this->marks = marks;
	}
};

class Student
{
public:
	char name[30];
	char gender;
	int roll_number;
	Marks_of_subject sub1;
	Marks_of_subject sub2;
	Marks_of_subject sub3;

public:
	Student()
	{
		this->gender=' ';
		this->roll_number=0;
		this->sub1.setMarks(0);
		this->sub2.setMarks(0);
		this->sub3.setMarks(0);
	}

	char getGender() const {
		return gender;
	}

	void setGender(char gender) {
		this->gender = gender;
	}

	int getRollNumber() const {
		return roll_number;
	}

	void setRollNumber(int rollNumber) {
		roll_number = rollNumber;
	}

	Marks_of_subject getSub1() const {
		return sub1;
	}

	void setSub1(Marks_of_subject sub1) {
		this->sub1 = sub1;
	}

	Marks_of_subject getSub2() const {
		return sub2;
	}

	void setSub2(Marks_of_subject sub2) {
		this->sub2 = sub2;
	}

	Marks_of_subject getSub3() const {
		return sub3;
	}

	void setSub3(Marks_of_subject sub3) {
		this->sub3 = sub3;
	}


	void Accept_info()
	{
		int sub_marks;
		getchar();
		cout<<"ENTER NAME OF STUDENT :";
		cin.get(name,30);
		getchar();
		cout<<"\nENTER GENDER M/F :";
		cin>>this->gender;

		cout<<"\nENTER ROLL_NUMBER :";
		cin>>this->roll_number;

		cout<<"ENTER SUB 1 MARKS :";
		cin>>sub_marks;
		this->sub1.setMarks(sub_marks);

		cout<<"ENTER SUB 2 MARKS :";
		cin>>sub_marks;
		this->sub2.setMarks(sub_marks);


		cout<<"ENTER SUB 3 MARKS :";
		cin>>sub_marks;
		this->sub2.setMarks(sub_marks);
	}

	void Print_info()
	{
		cout<<"\n\nNAME     :"<<this->name<<endl;
		cout<<"GENDER       :"<<this->gender<<endl;
		cout<<"ROLL_NUMBER  :"<<this->roll_number<<endl;
		float per = (float)(( this->sub1.getMarks() + this->sub2.getMarks() + this->sub3.getMarks() ) / 3) ;
		cout<<"PERCENTAGE IS :"<<per;
	}

};

int menuchoice()
{
	int choice;
	cout<<"ENTER ANY OPTION :";
	cout<<"\n1.ACCEPT_3_STUDENT_INFO \n2.PRINT_STUDENT_INFO \n3.SEARCH_STUDENT_INFO \n4.SORT_STUDENT_INFO"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
}

int Search_student_by_name(Student *ptr,int roll)
{
	//const char *name,*name1;

//	getline(cin,name);
//	name1=(const char *)ptr->getName();
//	(strstr(name1,name));
//	if(!=NULL)
//	{
//		ptr->Print_info();
//	}
	if(roll==ptr->getRollNumber())
		return 1;
	else
		return 0;
}

int compare_students(const void *ptr1,const void *ptr2)
{
	const Student* ptr3 = (Student*)ptr1;
	const Student* ptr4 = (Student*)ptr2;

	//const char* pt1 = (char*)ptr3->name;
	//const char* pt2 = (char*)ptr4->name;

	cout<<"\n "<<strcmp(ptr3->name,ptr4->name)<<" ";
	return strcmp(ptr3->name,ptr4->name);

}



int main()
{
	/*int size;
	cout<<"ENTER SIZE OF ARRAY :";
	cin>>size;
	Student s[size];*/
	Student s[3];
	int choice;
	int roll;

	int flag=0;
	while((choice=menuchoice())!=EXIT)
	{
		switch(choice)
		{
		case ACCEPT_3_STUDENT_INFO:
			for(int i=0;i<3;i++)
				{
					s[i].Accept_info();
				}
			break;
		case PRINT_STUDENT_INFO:
			for(int i=0;i<3;i++)
				{
					s[i].Print_info();
				}
			break;
		case SEARCH_STUDENT_INFO:
			cout<<"ENTER ROLL_NUMBER WHICH YOU WANT TO SEARCH :";
			cin>>roll;
			for(int i=0;i<3;i++)
				{
				flag = ::Search_student_by_name(&s[i],roll);
				if(flag == 1)
				{
					s[i].Print_info();
					break;
				}
				}
			break;
		case SORT_STUDENT_INFO:
			qsort(s,3,sizeof(Student),compare_students);
//			for(int i=0;i<3;i++)
//			{
//				s[i].Print_info();
//			}
			break;
		default :
			cout<<"ENTER VALID INPUT";
		}
	}

	return 0;
}
