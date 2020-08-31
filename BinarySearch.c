/*

Que : Binary Search

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
		printf("\nElement at arr[%d] : %d",i,arr[i]);
	}
}

void main()
{
	int arr[size];
	int i,n,search;
	int mid,first,last;

	printf("\nEnter size of array : ");
	scanf("%d",&n);
	
	if(n>size)
	{
		printf("\nCheck Your Array Size\n");
	}

	else
	{
		printf("\n\n");
		for(i=0;i<n;i++)
		{
			printf("Enter Element arr[%d] : ",i); 
			scanf("%d",&arr[i]);
		}
	}
	selectionsort(arr,n);
	
	//Binary Search

	printf("\n\nEnter Element to Search : ");
	scanf("%d",&search);

	first=0;
	last=n-1;
	mid=(first+last)/2;

	while(first<=last)
	{
		if(search==arr[mid])
		{
			printf("\nElement %d Found at Index : %d",search,mid);
			break;
		}

		else if(search>arr[mid])
		{
			first=mid+1;
		}

		else
		{
			last=mid-1;
		}
		mid=(first+last)/2;
	}
	getch();
}

/*
--------------
Output
--------------

Enter size of array : 7


Enter Element arr[0] : 50
Enter Element arr[1] : 20
Enter Element arr[2] : 40
Enter Element arr[3] : 25
Enter Element arr[4] : 15
Enter Element arr[5] : 60
Enter Element arr[6] : 35

After Sorting Elements

Element at arr[0] : 15
Element at arr[1] : 20
Element at arr[2] : 25
Element at arr[3] : 35
Element at arr[4] : 40
Element at arr[5] : 50
Element at arr[6] : 60

Enter Element to Search : 50

Element 50 Found at Index : 5
*/