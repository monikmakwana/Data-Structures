/*

Program to split a given linked list(containing numbers),into two lists of odd and even numbers respectively.(Use Singly Circular Linked List).

--------------
Program
--------------

*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *insert(struct node *first,struct node *newnode)
{
	struct node *temp;
	
	if(first == NULL)
	{
		first = newnode;
	}
	
	else
	{
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next = newnode;
		newnode->next=NULL;
		
	}

	return first;
}

void display(struct node *first)
{
	
	if(first == NULL)
	{
		printf("\n\nList is Empty\n");
	}
	
	else
	{
		while(first!=NULL)
		{
			printf(" %d ",first->data);
			first = first->next;
		}
	}
}

void split(struct node *first)
{
	struct node *odd=NULL,*even=NULL,*newnode;
	
	while(first!=NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = first->data;
		newnode->next = NULL;

		if(first->data % 2 == 0)
		{
			even = insert(even,newnode);
		}
		else
		{
			odd = insert(odd,newnode);
		}

		first = first->next;
	}

	printf("\n\nOdd List\n");
	display(odd);
	printf("\n\nEven List\n");
	display(even);	
}

void main()
{
	int ch,data;
	struct node *first=NULL,*newnode;

	do
	{

		printf("\n\n0.Exit");
		printf("\n1.Insert");
		printf("\n2.Display");
		printf("\n3.Split List into Odd And Even");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 0: exit(0);
			break;
		case 1:
				printf("\nEnter Data : ");
				scanf("%d",&data);
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->data = data;
				newnode->next=NULL;
				first = insert(first,newnode);
				break;
		case 2:
				printf("\nDisplay List\n\n");
				display(first);
				break;
		case 3:
				split(first);
				break;
		default:
				printf("\nPlease Enter Proper Choice\n");
		}

	}while(ch!=0);

	getch();
}

/*
--------------
Output
--------------

0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 10


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 11


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 12


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 13


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 14


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 15


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 1

Enter Data : 16


0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 2

Display List

 10  11  12  13  14  15  16

0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice : 3


Odd List
 11  13  15

Even List
 10  12  14  16

0.Exit
1.Insert
2.Display
3.Split List into Odd And Even
Enter Your Choice :
*/