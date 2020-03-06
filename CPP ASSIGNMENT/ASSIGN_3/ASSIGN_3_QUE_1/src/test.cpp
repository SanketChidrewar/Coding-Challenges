

/*1) Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
print_Time()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time. Allocate the memory
for the array and the object dynamically.*/

#include<iostream>

using namespace std;

class Time
{
	int h;
	int m;
	int s;

public:
	Time()
	{
		this->h = 0;
		this->m = 0;
		this->s = 0;
	}

	Time(int h,int m,int s)
	{
		this->h = h;
		this->m = m;
		this->s = s;
	}

	int getHour()
	{
		return this->h;
	}
	int getMinute()
	{
		return this->m;
	}
	int getSeconds()
	{
		return this->s;
	}
	void print_date()
	{
		cout<<this->h<<":"<<this->m<<":"<<this->s<<endl;
	}
	void setHour(int h)
	{
		this->h = h;
	}
	void setMinute(int m)
	{
		this->m = m;
	}
	void setSeconds(int s)
	{
		this->s = s;
	}
};


int main()
{
	int size;
	cout<<"ENTER NUMBER OF TIME OBJECT YOU WANT TO CREATE :";
	cin>>size;
	Time *t = new Time[size];
	int val;

	for(int i=0;i<size;i++)
	{
		cout<<"ENTER DETAILS OF OBJECT "<<i+1<<" : ";
		cout<<"enter hour :";
		cin>>val;
		t[i].setHour(val);

		cout<<"enter min :";
		cin>>val;
		t[i].setMinute(val);

		cout<<"enter sec :";
		cin>>val;
		t[i].setSeconds(val);
	}

	cout<<"\n\nENTERED DETAILS ARE :";


	for(int i=0;i<size;i++)
	{
		cout<<"\n OBJ : "<<i+1<<endl;
		cout<<" HOUR : MIN : SEC = ";
		cout<<t[i].getHour()<<" : "<<t[i].getMinute()<<" : "<<t[i].getSeconds();
	}
	return 0;
}


/*

#include<iostream>

typedef enum menu{EXIT,GET_HOUR,GET_MIN,GET_SEC,SET_HOUR,SET_MIN,SET_SEC,PRINT_DATE}MENUOP;

using namespace std;

class Time
{
	int h;
	int m;
	int s;

public:
	Time()
	{
		this->h = 0;
		this->m = 0;
		this->s = 0;
	}

	Time(int h,int m,int s)
	{
		this->h = h;
		this->m = m;
		this->s = s;
	}

	int getHour()
	{
		return this->h;
	}
	int getMinute()
	{
		return this->m;
	}
	int getSeconds()
	{
		return this->s;
	}
	void print_date()
	{
		cout<<this->h<<":"<<this->m<<":"<<this->s<<endl;
	}
	void setHour(int h)
	{
		this->h = h;
	}
	void setMinute(int m)
	{
		this->m = m;
	}
	void setSeconds(int s)
	{
		this->s = s;
	}
};

int menuchoice()
{
	int choice;
	cout<<"ENTER CHOICE :"<<endl;
	cout<<"\n0.EXIT \n1.GET_HOUR \n2.GET_MIN \n3.GET_SEC \n4.SET_HOUR \n5.SET_MIN \n6.SET_SEC \n7.PRINT_DATE\n";
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;

}

int main()
{
	Time *t = new Time[1];
	int choice;
	int val;

	while((choice=menuchoice())!=EXIT)
	{
		switch(choice)
		{
		case GET_HOUR:
			cout<<t[0].getHour();
			break;
		case GET_MIN:
			cout<<t[0].getMinute();
			break;
		case GET_SEC:
			cout<<t[0].getSeconds();
			break;
		case SET_HOUR:
			cout<<"ENTER HOUR :";
			cin>>val;
			t[0].setHour(val);
			break;
		case SET_MIN:
			cout<<"ENTER MIN :";
			cin>>val;
			t[0].setMinute(val);
			break;
		case SET_SEC:
			cout<<"ENTER SEC :";
			cin>>val;
			t[0].setSeconds(val);
			break;
		case PRINT_DATE:
			t[0].print_date();
			break;
		default:
			cout<<"ENTER VALID INPUT";
			break;
		}
	}
	return 0;
}

*/



