/*
Que : Linear Search

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define size 10

void linearsearch(int arr[],int n)
{
	int search,index=0,i;
	int flag=0;
	printf("\nEnter Element to search : ");
	scanf("%d",&search);

	for(i=0;i<n;i++)
	{
		if(arr[i]==search)
		{
			flag=1;
			break;
		}
		index++;
	}

	if(flag==1)
	{
		printf("\nElement present at index : %d",index);

	}
	else
	{
		printf("\nElement is not present in array");
	}
}

int main()
{
	int arr[size],n,i;
	printf("\nHow many Elements you want to enter : ");
	scanf("%d",&n);

	if(n>size)
	{
		printf("\nCheck Your Array Size\n");

	}

	else
	{

	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Element %d : ",i);
		scanf("%d",&arr[i]);
	}
	linearsearch(arr,n);
	}
	
	getch();
	return 0;
}

/*
--------------
Output
--------------

How many Elements you want to enter : 5

Enter Element 0 : 10
Enter Element 1 : 20
Enter Element 2 : 30
Enter Element 3 : 40
Enter Element 4 : 50

Enter Element to search : 30

Element present at index : 2
*/