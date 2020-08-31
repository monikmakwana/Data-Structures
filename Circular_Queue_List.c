/*
Perform following operations on a Circular queue(use Linked List):
	A.	Insert
	B.	Delete 


--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>
struct queuelist
{
	int data;
	struct queuelist *next;
};
struct queuelist *insert(struct queuelist *first,int data)
{
	struct queuelist *new_node,*temp;
	if(first==NULL)
	{
		first=(struct queuelist *)malloc(sizeof(struct queuelist));
		first->data=data;
		first->next=first;
	}
	else
	{
		new_node=(struct queuelist *)malloc(sizeof(struct queuelist));
		new_node->data=data;
		temp = first;
		while(temp->next!=first)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->next = first;

	}
	return first;
}
struct queuelist *del(struct queuelist *first)
{
	struct queuelist *temp;

	if(first==NULL)
	{
		printf("\nQueue is Empty\n");
	}
	else if(first->next==first)
	{
		printf("\n Deleted");
		free(first);
		first=NULL;
	}
	else
	{
		temp = first;
		while(temp->next!=first)
		{
			temp = temp->next;
		}
		temp->next = first->next;
		printf("\n Deleted");
		free(first);
		first = temp->next;
	}
	return first;
}
void display(struct queuelist *first)
{
	struct queuelist *temp;
	if(first==NULL)
	{
		printf("\nQueue is Empty\n");
	}
	else
	{
		printf("\n\nQueue\n");
		temp=first;
		do
		{
			printf(" %d",temp->data);
			temp = temp->next;
		}while(temp!=first);
	}
}
void main()
{
	struct queuelist *first=NULL;
	int choice,data;
	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
	

		printf("\n\nEnter your choice :");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("\n Enter Data to insert :");
			scanf("%d",&data);

			first=insert(first,data);
			break;
		case 2:
			first=del(first);
			break;
		case 3:
			display(first);
			break;
		case 0:
			break;
		}
	}while(choice!=0);
	getch();
}

/*
--------------
Output
--------------


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :1

 Enter Data to insert :10


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :1

 Enter Data to insert :20


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :1

 Enter Data to insert :30


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :1

 Enter Data to insert :40


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :1

 Enter Data to insert :50


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :3


Queue
 10 20 30 40 50

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

 Deleted

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

 Deleted

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

 Deleted

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

 Deleted

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

 Deleted

0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :2

Queue is Empty


0.Exit
1.Insert
2.Delete
3.Display

Enter your choice :
*/