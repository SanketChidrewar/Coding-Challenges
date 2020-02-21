#include <stdio.h>
#include<string.h>

int main()
{
	int No_Of_Test_Cases;
	scanf("%d", &No_Of_Test_Cases);              			// Reading input from STDIN
	printf("Input number is %d.\n", No_Of_Test_Cases);
	while(No_Of_Test_Cases--)
	{
	//for(int i=0;i<No_Of_Test_Cases;i++)
	//{
	    int len;
	    char str[100];
	    int str_len;
	    scanf("%d",&len);
	    scanf("%s",str);
	    //printf("%s\n",str);
	    str_len = strlen(str);
	    //printf("%d\n",str_len);
	    int arr[str_len] , count;

	    for(int i=0;i<str_len;i++)
	    {
	        count =0;
	        for(int j=0;j<str_len;j++)
	        {
	            if(str[i] == str[j])
	            {
	                count++;
	               //printf("%d ",i);
	            }
	        }
	        arr[i]=count;
	        printf("%d",count);
	    }
	    //to find max repeated char
	    int max=0,index;
	    for(int i=0;i<str_len;i++)
	    {
	        if(arr[i]>max)
	        {
	            max=arr[i];
	            index=i;
	           printf("\n%d\n",index);
	        }
	    }
	    printf("%d",(max*2)+1);
	//}
	}
	// Writing output to STDOUT
}

/*
 * #include <stdio.h>
#include<string.h>

int main()
{
	int No_Of_Test_Cases;
	int flag=0;
	scanf("%d", &No_Of_Test_Cases);              			// Reading input from STDIN
//	printf("Input number is %d.\n", No_Of_Test_Cases);
//	while(No_Of_Test_Cases--)
	//{
	for(int i=0;i<No_Of_Test_Cases;i++)
	{
	    long int len;
	    char str[100000];
	    long int str_len;
	    scanf("%d",&len);
	    scanf("%s",str);
	    //printf("%s\n",str);
	    str_len = strlen(str);
	    //printf("%d\n",str_len);
	    int arr[str_len] , count;

	    for(int i=0;i<str_len;i++)
	    {
	        count =0;
	        for(int j=0;j<str_len;j++)
	        {
	            if(str[i] == str[j])
	            {
	                count++;
	               // printf("%d ",i);
	            }
	        }
	        arr[i]=count;
	    }
	    //to find max repeated char
	    int max=0;
	    for(int i=0;i<str_len;i++)
	    {
	        if(arr[i]>max)
	        {
	            max=arr[i];
	           // printf("%d\n",index);
	        }
	    }
	    if(flag=0)
	    {
	    printf("%d\n",(max*2)+1);
	    }
	    else
	    {
	    printf("%d\n",((max*2)+1)+6);
	    }
	}
	// Writing output to STDOUT
}
 */


