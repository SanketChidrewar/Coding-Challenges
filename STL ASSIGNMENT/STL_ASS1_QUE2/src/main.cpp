/*
 * main.cpp
 *
 *  Created on: 13-Apr-2020
 *      Author: sunbeam
 */

//2. Create STL vector of float of size given by the user. Input values from the user. Iterate through
//the vector two times to find minimum value and maximum value. Use subscript operator for the
//first iteration, while iterator for the second iteration.


#include<iostream>
#include <bits/stdc++.h> // required for max, min readymade functions.
#include<vector>
using namespace std;

int main()
{
	int size;

	cout<<"Enter no of element you want to enter :";
	cin>>size;

	//vector<float> num = {20.1, 10.0,26.25,48.25};
	vector<float>num(size,0);

	cout<<"ENTER VECTOR ELEMENTS<<size"<<" :";

	for(int i=0;i<size;i++)
	{
		cin>>num[i];
	}

	//cout << "\nMin Element = "<< *min_element(num.begin(), num.end())<<endl;
	//cout << "\nMax Element = "<< *max_element(num.begin(), num.end())<<endl;

	//to find min using subscript
	float min=num[0];

	for(int i=1;i<size;i++)
	{
		if(num[i]<min)
		{
			min=num[i];
		}
	}
	cout<<"MIN = "<<min<<endl;


	//to find max using iterator
	float max =num[0];

	vector<float>::iterator it =num.begin();
	it++;
	while(it!=num.end())
	{
		if(*it>max)
		{
			max = *it;
		}
		it++;
	}

	cout<<"MAX = "<<max<<endl;
	return 0;
}


