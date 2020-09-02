/*

Write a program to create an ordered linked list.

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

struct node *insert(struct node *head)
{	
	struct node *newnode,*temp,*temp2=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));

	printf("\nEnter Element : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;

	if(head==NULL)
	{
		head=newnode;
	}
	
	else if(head->data > newnode->data)
	{
		newnode->next=head;
		head=newnode;
	}
	
	else
	{
		
		temp=head;
		
		while((temp!=NULL) && (temp->data < newnode->data))
		{
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=newnode;
		newnode->next=temp;
		

	}
	return head;
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp=temp->next;
	}	
}

void main()
{
	int ch;
	struct node *head=NULL;

	printf("\nOrdered Linklist\n");
	do
	{
	
	printf("\n\n0 for Exit");
	printf("\n1 for Insert");

	printf("\n\nEnter Your Choice : ");
	scanf("%d",&ch); 
	switch(ch)
	{
	case 0: exit(0);
			break;
	case 1: head=insert(head);
			display(head);	
			break;
	default : printf("\nEnter Proper Choice\n");
			  break;
	}
	}
	while(ch!=0);
	getch();

}

/*
--------------
Output
--------------


Ordered Linklist


0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 10

  10

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 15

  10  15

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 5

  5  10  15

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 11

  5  10  11  15

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 9

  5  9  10  11  15

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 20

  5  9  10  11  15  20

0 for Exit
1 for Insert

Enter Your Choice : 1

Enter Element : 1

  1  5  9  10  11  15  20

0 for Exit
1 for Insert

Enter Your Choice :
*/