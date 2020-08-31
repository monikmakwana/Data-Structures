/*

Write a Program to sort a list of numbers using Selection Sort.

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#define size 10

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void selectionsort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		swap(&arr[min],&arr[i]);
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
	printf("\nHow many elements you want to Enter : ");
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
		printf("Enter %d Element : ",i+1);
		scanf("%d",&arr[i]);

	}
	selectionsort(arr,n);
	}
	getch();
	return 0;
}

/*
--------------
Output
--------------

How many elements you want to Enter : 5

Enter 1 Element : 10
Enter 2 Element : 5
Enter 3 Element : 9
Enter 4 Element : 3
Enter 5 Element : 20

After Sorting Elements

Element 1 : 3
Element 2 : 5
Element 3 : 9
Element 4 : 10
Element 5 : 20
*/