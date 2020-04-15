/*
 * main.cpp
 *
 *  Created on: 14-Apr-2020
 *      Author: sunbeam
 */

//7. A text file contains set of integer (in range of 1 to 9) values separated by spaces. Read them into
//STL vector. Find the missing numbers from them.
//Input: 3 7 9 4 3 7 9 8 6 4 7 2
//Output: 1 5

#include<iostream>
#include <fstream>
#include<map>
#include <sstream>

using namespace std;

int main()
{
	ifstream is("src/numbers.txt");
	string numline;

	map<int,int> n;

	if(is.is_open())
	{
		while(getline(is,numline))
		{
			//cout<<numline<<endl;
			stringstream ss;
			ss<<numline;

			string temp;
			int found;
			while(!ss.eof())
			{
		        ss >> temp;
				if(stringstream(temp)>>found)
				{
					n[found]++;
				}
			}
		}
		is.close();
	}
	else
	{
		cout<<"FILE OPENING IS FAIL. "<<endl;
	}

	map<int,int>::iterator it;
	int flag =0;

	for(int i=1;i<=9;i++)
	{
		flag=0;
		it = n.begin();
	while(it != n.end())
	{
		//cout<<it->first<<" "<<it->second<<endl;
		if(it->first == i)
		{
			flag =1;
		}
		it++;
	}

	if(flag == 0)
	{
		cout<<i<<" ";
	}
	}

	return 0;
}


