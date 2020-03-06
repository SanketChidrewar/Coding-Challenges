
/*3] Write a user defined function sqr() that calculates square of
number and it throws exception if number entered by user is negative.*/


#include<iostream>

using namespace std;

class Sqr
{
	int num;

public:
	Sqr(int n)
	{
		this->num=n;
	}
	void cal_sqr(int num)throw(int);

};

void Sqr::cal_sqr(int num)throw(int)
{

	if(num < 0)
		throw 1;
	else
		cout<<"SQUARE"<<num*num;
}

int main()
{
	Sqr s(3);

	try
	{
		s.cal_sqr(-9);
	}
	catch(int i)
	{
		cout<<"\nENTER POSITIVE NUMBER FOR SQUARE";
	}

	return 0;
}
