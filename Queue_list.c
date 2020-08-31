/*
 Perform following operations on a Simple queue(use Linked List):
	A.	Insert
	B.	Delete 


--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct list
{
	int info;
	struct list *next;
};
typedef struct list node;
node *f,*r,*new_node,*curr;

node *insert(node *r)
{
	int value;
	printf("\nEnter the value:");
	scanf("%d",&value);
	new_node=(node *)malloc(sizeof(node));
	new_node->info=value;
	new_node->next=NULL;
	if(r==NULL)
	{
		f=new_node;
		r=new_node;
	}
	else
	{
		r->next=new_node;
		new_node->next=NULL;
		r=new_node;
	}
	return(r);
}
node *del(node *f)
{
	if(f==NULL)
	{
		printf("\nList is Empty");
		return(f);
	}
	else
	{
		curr=f;
		printf("\n Deleted Value is: %d",curr->info);
		f=f->next;
		curr->next=NULL;
		free(curr);
	}
	return(f);
}
void  display(node *f)
{
	if(f==NULL)
	{
		printf("\nQueue is Underflow");
	}
	curr=f;
	printf("\n");
	while(curr!=NULL)
	{
		printf(" %d",curr->info);
		curr=curr->next;
	}
}
void main()
{
	int n,ch;
	do
	{
		printf("\n\n0. Exit");

		printf("\n1. Insert ");
		printf("\n2. Display the list");
		printf("\n3. Delete ");

		printf("\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 0: exit(0);
				break;
		case 1:
				r=insert(r);
				break;
		case 2:
		

			display(f);
			break;
		case 3:
			f=del(f);
			break;
		default :
			printf("\nPlease Enter Proper Choice\n");
			break;
		}
	}while(ch!=0);
	getch();
}

/*
--------------
Output
--------------



0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 1

Enter the value:10


0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 1

Enter the value:20


0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 1

Enter the value:30


0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 2

 10 20 30

0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 3

 Deleted Value is: 10

0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 3

 Deleted Value is: 20

0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 3

 Deleted Value is: 30

0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice : 3

List is Empty

0. Exit
1. Insert
2. Display the list
3. Delete
Enter your Choice :
*/
