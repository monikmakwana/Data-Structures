/*
Perform following operations on a singly circular linked list: 
 
Insert a Node: 

G. At Beginning of List. 
H. At End of List. 
I. After a key value. 

Delete a Node: 

J. At Beginning of List. 
K. At End of List. 
L. After a key value. 

Display the List. 

-----------------
Program
-----------------
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct linked_list
{
	int data;
	struct linked_list *next;
}*head;
struct linked_list *insert_first(struct linked_list *head)
{
	struct linked_list *newnode=NULL,*temp;

	if(head==NULL)
	{
		head=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&head->data);
		head->next=head;
	}
	else
	{
		temp=head;
		newnode=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&newnode->data);
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		newnode->next=head;
		head=newnode;
		temp->next=head;	
	}
	return head;
}
struct linked_list *insert_last(struct linked_list *head)
{
	struct linked_list *newnode=NULL,*temp;

	if(head==NULL)
	{
		printf("\nList is Empty");

	}
	else
	{
		temp=head;
		newnode=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&newnode->data);
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=head;
	}
	return head;
}

struct linked_list *insert_specific(struct linked_list *head)
{
	struct linked_list *newnode=NULL,*temp,*valuenode=NULL;
	int value;

	if(head==NULL)
	{
		printf("\nList is Empty");

	}
	else
	{
		temp=head;
		printf("\n\nAfter which number do you want to Insert : ");
		scanf("%d",&value);
		newnode=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		while(temp->data!=value)
		{
			temp=temp->next;

		}
		newnode->next=temp->next;
		temp->next=newnode;
		
		
		return head;
	}
}
struct linked_list *create_list(struct linked_list *head)
{

	if(head==NULL)
	{
		head=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data:");
		scanf("%d",&head->data);
		head->next=head;
	}
	else
	{
		head=insert_last(head);		
	}
	return head;
}
void display(struct linked_list *head)
{
	struct linked_list *temp;
	if(head==NULL)
	{
		printf("\nList is Empty");	
	}
	else
	{
		temp=head;
		do
		{
 			printf("  %d",temp->data);
			temp=temp->next;
		}while(temp!=head);

	}

}
struct linked_list *delete_first(struct linked_list *head)
{
	struct linked_list *temp,*temp1;
	if(head==NULL)
	{
		printf("\nList is Empty");	
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		
	}
	else
	{
		temp=head;
		head=temp->next;
		temp1=head;
		
		while(temp1->next!=temp)
		{
			temp1=temp1->next;
		}
		temp1->next=temp->next;
		free(temp);
	}
	return head;

}
struct linked_list *delete_last(struct linked_list *head)
{
	struct linked_list *temp,*temp1;
	
	if(head==NULL)
	{
		printf("\nList is Empty");	
	}
	else
	{
		temp=head;
		temp1=head;
		while(temp->next!=head)
		{
			temp1=temp;
			temp=temp->next;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else
		{
			temp1->next=head;
		}
		free(temp);
	}
	return head;

}
struct linked_list *delete_specific(struct linked_list *head)
{
	struct linked_list *temp,*temp1=NULL;
	int value;

	if(head==NULL)
	{
		printf("\nList is Empty");

	}
	else
	{ 
		temp=head;
		printf("\n\nAfter which number do you want to Delete : ");
		scanf("%d",&value);
		

		while(temp->data!=value)
		{
			temp=temp->next;

		}
		if(temp->next==head)
		{
			printf("Can't Delete");

		}
		else
		{
			
		temp1=temp->next;	
		temp->next=temp1->next;
		free(temp1);
		}
	}
	return head;
}
void main()
{
	int ch;
	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Create List");
		printf("\n2.Insert First");
		printf("\n3.Insert Last");
		printf("\n4.Insert Specific");
		printf("\n5.Display");
		printf("\n6.Delete First");
		printf("\n7.Delete Last");
		printf("\n8.Delete Specific");
		printf("\n\n Enter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 0: exit(0);
				break;
		case 1: head=create_list(head);
				break;
		case 2:head=insert_first(head);
				break;
		case 3:head=insert_last(head);
				break;
		case 4:head=insert_specific(head);
				break;
		case 5:display(head);
				break;
		case 6:head=delete_first(head);
				break;
		case 7:head=delete_last(head);
				break;
		case 8:head=delete_specific(head);
				break;
		}
	}while(ch!=0);
}

/*
-----------
Output 
-----------

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:1

Enter Data : 10


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:1

Enter Data : 20


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  10  20

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:2

Enter Data : 5


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  5  10  20

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:3

Enter Data : 25


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  5  10  20  25

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:4


After which number do you want to Insert : 10

Enter data:15


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  5  10  15  20  25

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:4


After which number do you want to Insert : 25

Enter data:30


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  5  10  15  20  25  30

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:6


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  10  15  20  25  30

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:6


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  15  20  25  30

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:7


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  15  20  25

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:8


After which number do you want to Delete : 20


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  15  20

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:8


After which number do you want to Delete : 15


0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:5
  15

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:8


After which number do you want to Delete : 15
Can't Delete

0.Exit
1.Create List
2.Insert First
3.Insert Last
4.Insert Specific
5.Display
6.Delete First
7.Delete Last
8.Delete Specific

 Enter Choice:
*/