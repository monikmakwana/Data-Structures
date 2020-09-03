/*

--------------------------------------------------------------------------------------------
Write a program to sort a list of numbers using shell sort.
--------------------------------------------------------------------------------------------

--------------
Program
--------------

*/

#include<stdio.h>
#include<conio.h>
void insert(int arr[], int n)
{
	int i;
	printf("\nEnter elements of array: ");
	for (i = 0; i < n; i++)
	{
		scanf(" %ld", &arr[i]);
	}
}
void display(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf(" %ld", arr[i]);
	}
}
void shellsort(int arr[], int n)
{
	int i, j, gap, temp;
	for (gap = n / 2; gap>0; gap = gap / 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] >temp; j = j - gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}
void main()
{
	int arr[20], n;
	printf("\nEnter size of Array: ");
	scanf(" %ld", &n);
	insert(arr, n);
	printf("\nElements of Array:");
	display(arr, n);
	shellsort(arr, n);
	printf("\nElements of Array after Shellsort:");
	display(arr, n);
	getch();
}

/*
--------------
Output
--------------

Enter size of Array: 10

Enter elements of array: 34
32 11 9 74 46 89 112 140 59

Elements of Array: 34 32 11 9 74 46 89 112 140 59
Elements of Array after Shellsort: 9 11 32 34 46 59 74 89 112 140
*/