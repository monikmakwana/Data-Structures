/*
--------------------------------------------------------------------------------------
Write a program to sort a list of numbers using Quick sort.
--------------------------------------------------------------------------------------

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
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high],i,j;
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quicksort(int arr[], int low,int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
void main()
{
	int arr[20], n,low,high;
	printf("\nEnter size of Array: ");
	scanf(" %ld", &n);
	insert(arr, n);
	printf("\nElements of Array:");
	display(arr, n);
	low = 0;
	high = n - 1;
	quicksort(arr,low,high);
	printf("\nElements of Array after Quicksort:");
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
Elements of Array after Quicksort: 9 11 32 34 46 59 74 89 112 140

*/
