/*
 * strtok.c
 *
 *  Created on: 17-Feb-2020
 *      Author: sunbeam
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//let argv[1] is data with string tokeniser & argv[2] is string of all possible tokens
//CMD INPUT : "s,a.n+k-e*t" ",.+-*"
int main(int argc,char *argv[])
{
	int len = strlen(argv[2]);
	char *ptr = (char*)calloc(len,sizeof(char));
	for(int i=0;i<len;i++)
	{
		ptr[i] = *(argv[2]+i);
		//printf("%c\n",ptr[i]);
	}
	int i=0;
	int flag;

	while(*(argv[1]+i)!='\0')
	{
		flag=0;
		for(int j=0;j<len;j++)
		{
		if(*(argv[1]+i) == ptr[j])
			{
				printf("\n");
				i++;
			}
		}
		printf("%c",*(argv[1]+i));
		i++;
	}

	return 0;
}
