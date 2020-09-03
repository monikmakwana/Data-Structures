/*

--------------------------------------------------------------------------------------
Write a program to sort a list of numbers using radix sort.
--------------------------------------------------------------------------------------

--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int v;
	struct node *next;
};
typedef struct node nn;
int getmax(nn *head)
{
	int max=head->v;
	nn* temp =head->next;
	while (temp != NULL)
	{
		if (max < temp->v)
		{
			max = temp->v;
		}
		temp = temp->next;
	}
	return max;
}
nn* insert(nn* head)
{
	char c = 49;
	nn *temp = NULL,*oldnode=NULL;
	printf("\nEnter elements in linkedlist: ");
	while (c == 49)
	{
		temp = (nn*)malloc(sizeof(temp));
		printf("\nEnter element: ");
		scanf(" %ld",&temp->v);
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			oldnode->next = temp;
		}
		oldnode = temp;
		printf("\nEnter 1 for another value: ");
		scanf(" %c", &c);
	}
	return head;
}
void display(nn* head)
{
	nn *temp = NULL;
	temp = head;
	printf("\nList:");
	while (temp != NULL)
	{
		printf(" %ld", temp->v);
		temp = temp->next;
	}
}
nn* joinnext(nn* arr[])
{
	int i = 0;
	nn *temp = NULL, *last = NULL,*head=NULL;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			temp = arr[i];
			if (head == NULL)
			{
				head = temp;
			}
			if (last != NULL)
			{
				last->next = temp;
			}
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			last = temp;
		}
	}
	last->next = NULL;
	return head;
}
void radixsort(nn *head)
{
	int max=getmax(head);
	int i,r,b=10,tn=0,j;
	nn *temp = NULL, *arr[20] = { NULL },*atemp=NULL;
	for (i = max; i > 0; i = i / 10)
	{
		if (i == max)
		{
			temp = head;
			while (temp != NULL)
			{
				r = temp->v % 10;
				if (arr[r] == NULL)
				{
					arr[r] = temp;
					temp = temp->next;
					arr[r]->next = NULL;
				}
				else
				{
					atemp = arr[r];
					while (atemp->next != NULL)
					{
						atemp = atemp->next;
					}
					atemp->next = temp;
					atemp = atemp->next;
					temp = temp->next;
					atemp->next = NULL;
				}
			}
			head=joinnext(arr);
		}
		else
		{
			temp = head;
			for (j = 0; j < 10; j++)
			{
				arr[j] = NULL;
			}
			while (temp != NULL)
			{
				tn = temp->v/b;
				r = tn % 10;
				if (arr[r] == NULL)
				{
					arr[r] = temp;
					temp = temp->next;
					arr[r]->next = NULL;
				}
				else
				{
					atemp = arr[r];
					while (atemp->next != NULL)
					{
						atemp = atemp->next;
					}
					atemp->next = temp;
					atemp = atemp->next;
					temp = temp->next;
					atemp->next = NULL;
				}
			}
			head = joinnext(arr);
			b = b * 10;
		}
	}
	printf("\nAfter Sorting: ");
	display(head);
}
void main()
{
	nn *head = NULL;
	head = insert(head);
	display(head);
	radixsort(head);
	getch();
}

/*
--------------
Output
--------------

Enter elements in linkedlist:
Enter element: 36

Enter 1 for another value: 1

Enter element: 34

Enter 1 for another value: 1

Enter element: 13

Enter 1 for another value: 1

Enter element: 11

Enter 1 for another value: 1

Enter element: 76

Enter 1 for another value: 1

Enter element: 48

Enter 1 for another value: 1

Enter element: 91

Enter 1 for another value: 1

Enter element: 114

Enter 1 for another value: 1

Enter element: 142

Enter 1 for another value: 1

Enter element: 61

Enter 1 for another value: 2

List: 36 34 13 11 76 48 91 114 142 61
After Sorting:
List: 11 13 34 36 48 61 76 91 114 142

*/