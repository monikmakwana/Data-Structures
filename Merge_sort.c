/*
----------------------------------------------------------------------------------------
Write a program to sort a list of numbers using Merge sort.
----------------------------------------------------------------------------------------

--------------
Program
--------------

*/

#include<stdio.h>
#include<conio.h>
void insert(int arr[], int n)
{
	int i;
	printf("\nEnter elements in array: ");
	for (i = 0; i < n; i++)
	{
		scanf_s(" %ld", &arr[i]);
	}
}
void display(int arr[], int n)
{
	printf("\nElements in array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%ld ", arr[i]);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int n1, n2,L[20],R[20],i,j,k;
	n1 = m - l+1;
	n2 = r - m;
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l+i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else if (R[j] < L[i])
		{
			arr[k] = R[j];
			j++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			k++;
			arr[k] = L[i];
			i++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j< n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l+r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void main()
{
	int arr[20], n,l,r;
	printf("\nEnter number of elements in array: ");
	scanf_s(" %ld", &n);
	insert(arr, n);
	display(arr, n);
	l = 0;
	r = n - 1;
	mergesort(arr, l, r);
	display(arr, n);
	getch();
}

/*
--------------
Output
--------------

Enter number of elements in array: 8

Enter elements in array: 89 95 26 32 8 71 11 45

Elements in array: 89 95 26 32 8 71 11 45
Elements in array: 8 11 26 32 45 71 89 95
*/