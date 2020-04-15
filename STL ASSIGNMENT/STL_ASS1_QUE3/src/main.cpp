/*
 * main.cpp
 *
 *  Created on: 14-Apr-2020
 *      Author: sunbeam
 */

//3. Create STL queue of double values. Write a menu driven program to push, pop, peek and delete
//all values in queue. After each operation display current size of queue.

#include<iostream>
#include<queue>
using namespace std;

typedef enum{EXIT,PUSH,POP,PEEK,DELETE}menuop;

int qchoice()
{
	int choice;
	cout<<"0.EXIT \n1.PUSH \n2.POP \n3.PEEK \n4.DELETE \nENTER YOUR CHOICE: ";
	cin>>choice;
	return choice;
}

int main()
{
	queue<double> q;

	int choice =0;
	double ele;

	while((choice = qchoice())!=EXIT)
	{
		switch(choice)
		{
		case PUSH:
			cout<<"ENTER QUEUE ELEMENT : ";
			cin>>ele;
			q.push(ele);
			cout<<"CURRENT SIZE :"<<q.size()<<endl<<endl;
			break;
		case POP:
			q.pop();
			cout<<"CURRENT SIZE :"<<q.size()<<endl<<endl;
			break;
		case PEEK:
			cout<<endl<<"FRONT ELEMENT :"<<q.front()<<endl<<endl;
			cout<<"CURRENT SIZE :"<<q.size()<<endl<<endl;
			break;
		case DELETE:
			while(q.size()!=0)
			{
				q.pop();
			}
			cout<<"CURRENT SIZE :"<<q.size()<<endl<<endl;
			break;
		}
	}

	return 0;
}


