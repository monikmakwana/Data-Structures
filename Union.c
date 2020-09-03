/*

 Program to perform union of two sets of lists.

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
	struct node *prev;

};

struct node *insert(struct node *first,struct node *newnode)
{
	if(first==NULL)
	{
		newnode->next = first;
		newnode->prev = NULL;
		first = newnode;
		return first;
	}
	else
	{
		newnode->next = first;
		first->prev = newnode;
		first = newnode;
	}

	return first;
}

struct node *remove1(struct node *first)
{
	struct node *temp,*temp2,*tmp;

	if(first==NULL)
	{
		printf("\nList is Empty\n");
		return first;
	}
	else if(first->next==NULL)
	{
		return first;
	}
	else if(first->next->next==NULL)
	{
		if(first->data == first->next->data)
		{
			temp = first->next;
			first->next = NULL;
			free(temp);
		}
	}
	else
	{
		temp = first;

		while(temp->next!=NULL)
		{
			temp2 = temp->next;
			while(temp2!=NULL)
			{
				if(temp->data == temp2->data)
				{
					if(temp2->next==NULL)
					{
						temp2->prev->next = NULL;	
						free(temp2); 
						break;
					}
					else
					{
						tmp = temp2;
						temp2->prev->next = tmp->next;
						tmp->next->prev = temp2->prev;
						temp2 = tmp->prev;
						free(tmp);					
					}
				}
				temp2 = temp2->next;
			}
			temp=temp->next;
		}
	}
	return first;
}

void display(struct node *first)
{
	struct node *temp;

	if(first==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		temp = first;
		
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}

void union_list(struct node *f1,struct node *f2)
{
	struct node *f3=NULL,*newnode;

	while(f1!=NULL)
	{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->data = f1->data;
			newnode->next=NULL;
			newnode->prev=NULL;

			f3 = insert(f3,newnode);
			f1 = f1->next;
	}

	while(f2!=NULL)
	{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->data = f2->data;
			newnode->next=NULL;
			newnode->prev=NULL;
			f3 = insert(f3,newnode);

			f2=f2->next;			
	}

	f3 = remove1(f3);
	printf("\n\nUnion Of Lists :\n");
	display(f3);
}

void main()
{
	int ch,data;
	struct node *list1=NULL,*list2=NULL,*newnode;

	printf("\nEnter Data in First List\n");
	do
	{

		printf("\nEnter Data : ");
		scanf("%d",&data);

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next=NULL;
		newnode->prev=NULL;

		list1 = insert(list1,newnode);
		
		printf("\n0.Exit");
		printf("\n1.Enter Again");
		printf("\nEnter Choice:");
		scanf("%d",&ch);
	}while(ch==1);
		

	printf("\nEnter Data in Second List\n");
	do
	{

		printf("\nEnter Data : ");
		scanf("%d",&data);

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next=NULL;
		newnode->prev=NULL;

		list2 = insert(list2,newnode);

		printf("\n0.Exit");
		printf("\n1.Enter Again");
		printf("\nEnter Choice:");
		scanf("%d",&ch);
	}while(ch==1);

	printf("\nFirst List :\n");
	display(list1);

	printf("\n\nSecond List :\n");
	display(list2);

	union_list(list1,list2);

	getch();
}

/*
------------
Output
------------

Enter Data in First List

Enter Data : 10

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 20

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 30

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 40

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 50

0.Exit
1.Enter Again
Enter Choice:0

Enter Data in Second List

Enter Data : 40

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 50

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 60

0.Exit
1.Enter Again
Enter Choice:1

Enter Data : 70

0.Exit
1.Enter Again
Enter Choice:0

First List :
 50  40  30  20  10

Second List :
 70  60  50  40

Union Of Lists :
 40  50  60  70  10  20  30
*/