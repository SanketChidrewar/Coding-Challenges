
/*
Write a C++ Class to store Account information of Bank customer by using
following class diagram. Use enum to store information of account type.
Create an array of 5 Accounts in main() and accept their details from
user. Write Menu driven program to deposit/WITHDRAWAL amount from the
account. After each transaction display updated account balance. Provide
appropriate getters/setters with necessary validations. Throw exceptions
for invalid values.
Also implement an exception class insufficient_funds. In WITHDRAWAL()
member function, if sufficient balance is not available in account,
throw this exception.*/


#include<iostream>

using namespace std;

typedef enum{SAVING=1,CURRENT,DMAT,DEPOSIT=1,WITHDRAWAL}account_type;

class Insufficient_fund
{
	int accid;
	double cur_balance;
	double WITHDRAWAL_amount;
public:

	Insufficient_fund(int accid ,double cur_balance, double WITHDRAWAL_amount)
	{
		this->accid = accid;
		this->cur_balance = cur_balance;
		this->WITHDRAWAL_amount = WITHDRAWAL_amount;
		//cout<<"INSUFFICIENT BALANCE to WITHDRAWAL "<<this->cur_balance;
	}
	void display()
	{
		cout<<"\nINSUFFICIENT BALANCE :";
		cout<<"\nYour current balance is :"<<this->cur_balance;
		cout<<"\nyou are trying to WITHDRAWAL :"<<this->WITHDRAWAL_amount;
	}
};

class Account
{
	int id;
	account_type type;
	double balance;

public:
	Account()
	{
		this->id=0;
		this->type=type;
		this->balance=0;
	}
	Account(int id, account_type type)
	{
		this->id = id;
		this->type = type;
		this->balance = 0;
	}
	void Accept()
	{
		label1:
		int val;
		cout<<"ENTER ACCOUNT ID :";
		cin>>this->id;
		cout<<"ENTER ACCOUT TYPE :";
		cout<<"\n1.SAVING \n2.CURRENT \n3.DMAT \n";
		cin>>val;
		if(val==1)
			this->type = SAVING;
		else if(val==2)
			this->type = CURRENT;
		else if(val==3)
			this->type = DMAT;
		else
		{
			cout<<"\nENTER VALID ACCOUNT TYPE :\n";
			goto label1;
		}
	}
	void Display()
	{
		cout<<"\nACC_ID :"<<this->id;
		cout<<"\nACC_TYPE :";
		int val = this->type;
		if(val==1)
			cout<<"SAVING";
		else if(val==2)
			cout<<"CURRENT";
		else if(val==3)
			cout<<"DMAT";
		cout<<"\nACC_BAL :"<<this->balance;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	void set_type(int val)
	{
		if(val==1)
			this->type = SAVING;
		else if(val==2)
			this->type = CURRENT;
		else if(val==3)
			this->type = DMAT;
	}
	int get_id()
	{
		return this->id;
	}
	account_type get_type()
	{
		return this->type;
	}
	double get_balance()
	{
		return this->balance;
	}
	void deposit(double amount)
	{
		if(amount > 0)
		{
		this->balance = this->balance + amount;
		//cout<<"\nAMOUNT SUCCESSFULLY DEPOSITED\n";
		cout<<"\nUPDATED BALANCE IS :"<<this->balance<<"\n";
		}
		else
			throw(10);

	}
	void WITHDRAWAL(double amount)
	{
		if(amount<0 || amount >this->balance)
			throw Insufficient_fund(this->get_id(),this->get_balance(),amount);
		this->balance = this->balance - amount;
		cout<<"\nUPDATED BALANCE IS :"<<this->balance<<"\n";
		cout<<"\nAMOUNT SUCCESSFULLY WITHDRAWAL\n";

	}
};

int menu_choice()
{
	int ch;
	cout<<"\n\nENTER CHOICE\n0.EXIT \n1.DEPOSIT \n2.WITHDRAWAL";
	cout<<"\nENTER YOUR CHOICE : ";
	cin>>ch;
	return ch;
}

int main()
{
	Account a[5];
	int flag=0;
	int acc_id;
	int amt;
	for(int i=0;i<5;i++)
	{
		cout<<"\nENTER ACCOUNT DETAILS OF "<<i+1<<" :\n";
		a[i].Accept();
	}
	int choice;
	while((choice= menu_choice())!=0)
	{
		switch(choice)
		{
		case DEPOSIT:
			flag=0;
			cout<<"ENTER ACC_ID IN WHICH YOU WANT TO DEPOSIT MONEY :";
			cin>>acc_id;
			for(int i=0;i<5;i++)
			{
				if(a[i].get_id()==acc_id)
				{
					try
					{
					cout<<"ENTER AMOUNT YOU WANT TO DEPOSIT :";
					cin>>amt;
					a[i].deposit(amt);
					flag=1;
					}catch(int)
						{
							flag=2;
							cout<<"\nENTER VALID AMOUNT \n";
						}
				}
			}
			if(flag==1)
			{
				cout<<"\nAMOUNT IS DEPOSITED SUCCESSFULLY IN ACC_NO "<<acc_id<<" WITH AMOUNT "<<amt<<"\n";
			}
			else if(flag==0)
			{
				cout<<"\nACCOUNT NOT FOUND\n";
			}
			break;
		case WITHDRAWAL:
			flag=0;
			cout<<"ENTER ACC_ID FROM WHICH YOU WANT TO WITHDRAWAL MONEY :";
			cin>>acc_id;
			for(int i=0;i<5;i++)
			{
				if(a[i].get_id()==acc_id)
				{
					try
					{
					cout<<"ENTER AMOUNT THAT WANT TO WITHDRAWAL :";
					cin>>amt;
					a[i].WITHDRAWAL(amt);
					flag=1;
					}	catch(Insufficient_fund i)
					{
						flag=2;
						i.display();
					}
				}
			}
			if(flag==1)
			{
				cout<<"\nAMOUNT IS WITHDRAWALAL SUCCESSFULLY IN ACC_NO "<<acc_id<<" WITH AMOUNT "<<amt<<"\n";
			}
			else if(flag==0)
			{
				cout<<"\nACCOUNT NOT FOUND\n";
			}
			break;

			break;
		}
	}
	return 0;
}

