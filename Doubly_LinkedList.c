/*
 Perform following operations on a doubly linked list: 
 
Insert a Node: 

M. At Beginning of List. 
N. At End of List. 
O. After a key value. 

Delete a Node: 

P. At Beginning of List. 
Q. At End of List. 
R. After a key value. 

Display the List. 

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct linked_list
{
	int data;
	struct linked_list *next;
	struct linked_list *prev;
}*head;
struct linked_list *insert_first(struct linked_list *head)
{
	struct linked_list *newnode=NULL,*temp;

	if(head==NULL)
	{
		head=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&head->data);
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		temp=head;
		newnode=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=head;
		head->prev=newnode;

		head=newnode;
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
		newnode->next=NULL;
		newnode->prev=NULL;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=NULL;
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
		printf("\nAfter which number do you want to Insert : ");
		scanf("%d",&value);
		

		while(temp!=NULL)
		{
			if(value==temp->data)
			{
				if(temp->next==NULL)
				{
					head=insert_last(head);
				}
				else
				{
				newnode=(struct linked_list *)malloc(sizeof(struct linked_list));
				printf("\nEnter Data : ");
				scanf("%d",&newnode->data);
				newnode->next=NULL;
				newnode->prev=NULL;
				valuenode=temp;
				temp=temp->next;
				valuenode->next=newnode;
				newnode->next=temp;
				newnode->prev=valuenode;
				
				temp->prev=newnode;
				}
			}
			temp=temp->next;
		}
		

	}
	return head;
}
struct linked_list *create_list(struct linked_list *head)
{
	struct linked_list *newnode=NULL,*temp;

	if(head==NULL)
	{
		head=(struct linked_list *)malloc(sizeof(struct linked_list));
		printf("\nEnter Data : ");
		scanf("%d",&head->data);
		head->next=NULL;
		head->prev=NULL;
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
		while(temp!=NULL)
		{
 			printf("  %d",temp->data);
			temp=temp->next;
		}
	}

}
struct linked_list *delete_first(struct linked_list *head)
{
	struct linked_list *temp;
	if(head==NULL)
	{
		printf("\nList is Empty");	
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
	}
	else
	{
		temp=head;
		head=temp->next;
		temp->next=NULL;
		head->prev=NULL;
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
		while(temp->next!=NULL)
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
			temp1->next=NULL;
			temp->prev=NULL;
		}
		free(temp);
	}
	return head;

}
struct linked_list *delete_specific(struct linked_list *head)
{
	struct linked_list *ptr, *temp;   
    int val;   
	printf("\nAfter which number do you want to Delete : ");
    scanf("%d",&val);  
    temp = head;  
    while(temp -> data != val)  
    temp = temp -> next;  
    if(temp -> next == NULL)  
    {  
		 printf("\nCan't Delete\n");  
		
    }  
    else if(temp -> next -> next == NULL)  
    {  
        temp ->next = NULL;  
    }  
    else  
    {   
        ptr = temp -> next;  
        temp -> next = ptr -> next;  
        ptr -> next -> prev = temp;  
        free(ptr);  
        printf("\nNode Deleted\n");  
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
		printf("\n Enter Choice:");
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
		default: printf("\nPlease Enter Proper Choice");
				break;

		}
	}while(ch!=0);
	getch();
}

/*
--------------
Output
--------------

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

After which number do you want to Insert : 5

Enter Data : 9


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
  5  9  10  20  25

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

Enter Data : 30


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
  5  9  10  20  25  30

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
  9  10  20  25  30

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
  10  20  25  30

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
  10  20  25

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
 Enter Choice:8

After which number do you want to Delete : 10


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
  10

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

After which number do you want to Delete : 10

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