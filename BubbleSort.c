/*
*** Write a Program to sort a list of numbers using Bubble Sort. ***

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#define size 30

void bubblesort(int arr[],int n)
{
	int i,j,temp;
	int flag=0;
	for(i=0;i<n-1;i++)
	{
	
		for(j=0;j<n-i-1;j++)
		{
		
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
			
		}
		if(flag==0)
			break;
	
	}

	if(flag==0)
	{
	printf("\nAlready Sorted Data\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d",arr[i]);
	}
	}
	else
	{
	printf("\nAfter Sorting Elements \n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d : %d",i+1,arr[i]);
	}
	}
}

int main()
{
	int arr[size];
	int n,i;	
	printf("\nHow Many Elements You Want to Enter : ");
	scanf("%d",&n);

	if(n>size)
	{
		printf("\nPlease Check your Array Size\n");
	}

	else
	{
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,n);
	}
	getch();
	return 0;
}

/*
--------------
Output
--------------

How Many Elements You Want to Enter : 5

Enter Element 1 : 13
Enter Element 2 : 11
Enter Element 3 : 15
Enter Element 4 : 5
Enter Element 5 : 18

After Sorting Elements

Element 1 : 5
Element 2 : 11
Element 3 : 13
Element 4 : 15
Element 5 : 18
*/