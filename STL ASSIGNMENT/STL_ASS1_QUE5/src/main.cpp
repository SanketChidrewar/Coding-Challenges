/*
 * main.cpp
 *
 *  Created on: 14-Apr-2020
 *      Author: sunbeam
 */

//5. Declare a string to store some information. Use stringstream class to tokenize string into multiple
//words and put them into a vector. Count frequeny of each word (use map) and finally print the word
//that is repeated maximum along with its count.
//string info = "coronavirus disease is an infectious disease caused by a new virus. the disease
//causes respiratory illness with symptoms such as a cough, fever, and in more severe cases, difficulty
//breathing. you can protect yourself by washing your hands frequently, avoiding touching your face,
//and avoiding close contact with people who are unwell.";

#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
	string str = "coronavirus disease is an infectious disease caused by a new virus. the disease"
			"causes respiratory illness with symptoms such as a cough, fever, and in more severe cases, difficulty"
			"breathing. you can protect yourself by washing your hands frequently, avoiding touching your face,"
			"and avoiding close contact with people who are unwell.";

	stringstream s(str);

	vector<string> strvector;

	string word;
	while(s>>word)
	{
		strvector.push_back(word);
		//cout<<word<<endl;
	}

	map<string,int> strmap;

	for(string st : strvector)
	{
		strmap[st]++;
	}

	map<string,int>::iterator it = strmap.begin();

	while(it != strmap.end() )
	{
		cout<<it->first<<"->"<<it->second<<endl;
		it++;
	}

	map<string,int>::iterator it1;
	it = strmap.begin();
	int max = it->second;
	while(it != strmap.end() )
	{
		if(it->second > max)
		{
			max=it->second;
			it1 = it;
		}
		it++;

	}

	cout<<endl<<"Words repeating max times are:"<<endl<<endl;
	it = strmap.begin();
	while(it != strmap.end() )
	{
		if(it->second == max)
		{
		cout<<"WORD REPEATED MAX is : "<<it->first<<" WITH "<<it->second<<" TIMES ."<<endl;
		}
		it++;
	}
	return 0;
}

/*
map<string,int>::iterator it1;
it = strmap.begin();
int max = it->second;
while(it != strmap.end() )
{
	if(it->second >= max)
	{
		it1 = it;
	}
	it++;

}

cout<<"WORD REPEATED MAX: "<<it1->first<<" WITH "<<it1->second<<" TIMES ."<<endl;*/
