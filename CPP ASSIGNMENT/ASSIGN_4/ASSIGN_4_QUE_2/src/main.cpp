
/*Write a class address. Implement constructors, getters, setters and
accept()/display() methods.*/

#include<iostream>
#include<cstring>

using namespace std;

class address
{


private:
	char building[30];
	char street[30];
	char city[20];
	int pin;

public:

	address()
	{
		strcpy(this->building,"");
		strcpy(this->street,"");
		strcpy(this->city,"");
		this->pin=0;
	}
	address(char *building,char *street, char *city,int pin)
	{
		strcpy(this->building,building);
		strcpy(this->street,street);
		strcpy(this->city,city);
		this->pin=pin;
	}
	void accept()
	{
		cout<<"\nENTER ADDRESS :";
		cin.get(this->building,30);
		cout<<"ENTER STREET :";
		cin.get(this->street,30);
		cout<<"ENTER CITY :";
		cin.get(this->city,30);
		cout<<"ENTER CITY PIN :";
		cin>>this->pin;
	}
	void display()
	{
		cout<<" \nADDRESS    :"<<this->building;
		cout<<" \nSTREET     :"<<this->street;
		cout<<" \nCITY       :"<<this->city;
		cout<<" \nCITY PIN   :"<<this->pin;
	}

	const char* get_building()
	{
		return this->building;
	}
	const char* get_street()
	{
		return this->street;
	}
	const char* get_city()
	{
		return this->city;
	}
	int get_pin()
	{
		return this->pin;
	}
	void set_building(const char* building)
	{
		strcpy(this->building,building);
	}
	void set_street(const char* street)
	{
		strcpy(this->street,street);
	}
	void set_city(const char* city)
	{
		strcpy(this->city,city);
	}
	void set_pin(int pin)
	{
		this->pin = pin;
	}

};

int main()
{
	address a("saraf line","chillarge galli","udgir",413517);
	a.display();

	return 0;

}



