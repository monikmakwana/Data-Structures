/*

Write a Program to sort a list of numbers using Insertion Sort.

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#define size 10

void insertionsort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		j=i;
		while(arr[j]<arr[j-1] && j>0)
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;

		}
	}

	printf("\nAfter Sorting Elements\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d : %d",i+1,arr[i]);
	}

}

int main()
{
	int arr[size],n;
	int i;

	printf("\nHow many Elements you want to Enter : ");
	scanf("%d",&n);
	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("Enter %d Element : ",i+1);
		scanf("%d",&arr[i]);
	}
	insertionsort(arr,n);
	getch();
	return 0;

}

/*
--------------
Output
--------------

How many Elements you want to Enter : 5

Enter 1 Element : 19
Enter 2 Element : 11
Enter 3 Element : 15
Enter 4 Element : 35
Enter 5 Element : 27

After Sorting Elements

Element 1 : 11
Element 2 : 15
Element 3 : 19
Element 4 : 27
Element 5 : 35
*/