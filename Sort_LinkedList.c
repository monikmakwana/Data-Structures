/*
Program to sort a given linked list.(Use Doubly Circular Linked List)

---------------
Program
---------------
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next,*prev;
};

struct node *insert(struct node *first, int no)
{
	struct node *newnode, *temp;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=no;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if (first==NULL)
	{
		newnode->prev=newnode;
		newnode->next=newnode;
	}
	else
	{
		newnode->next=first->next;
		newnode->prev=first;
		first->next=newnode;
	}
	
	return newnode;
}

struct node *minmum(struct node *first)
{
	int data;
	struct node *mnode, *temp;
	
	mnode=first;
	data=first->data;
	temp=first->next;
	
	while(temp!=first)
	{
		if(data > temp->data)
		{
			data=temp->data;
			mnode=temp;
		}
		temp=temp->next;
	}
	
	return mnode;
}

void display(struct node *first)
{
	struct node *temp;
	int i=0;
	
	temp=first;
	printf("\n");
	do
	{
		printf("  %d ",temp->data);
		temp=temp->next;
	}while(temp!=first);
}

struct node *sort(struct node *first, struct node *tail)
{
	struct node *min, *sortb=NULL, *sortl=NULL, *temp;
	
	while(first->next!=first)
	{
		min=minmum(first);
	
		if(min==first)
		{
			if(sortb==NULL)
			{
				sortb=first;
				first=first->next;
				sortb->next=sortb;
				sortb->prev=sortb;
				sortl=sortb;
			}
			else
			{
				temp=first;
				first=first->next;
				temp->next=sortl->next;
				temp->prev=sortl;
				sortl->next=temp;
				sortl=temp;
			}
		
			tail->next=first;
			first->prev=tail;
		}
		else if(min==tail)
		{
			if(sortb==NULL)
			{
				sortb=tail;
				tail=tail->prev;
				sortb->next=sortb;
				sortb->prev=sortb;
				sortl=sortb;
			}
			else
			{
				temp=tail;
				tail=tail->prev;;
				temp->next=sortl->next;
				temp->prev=sortl;
				sortl->next=temp;
				sortl=temp;
			}
			tail->next=first;
			first->prev=tail;
		}
		else
		{
			if(sortb==NULL)
			{
				sortb=min;
				min->prev->next=min->next;
				min->next->prev=min->prev;
				sortb->next=sortb;
				sortb->prev=sortb;
				sortl=sortb;
			}
			else
			{
				temp=min;
				min->prev->next=min->next;
				min->next->prev=min->prev;
				temp->next=sortl->next;
				temp->prev=sortl;
				sortl->next=temp;
				sortl=temp;
			}
			min->next=min->next->next;
		}
	}
	
	sortl->next=first;
	first->prev=sortl;
	first->next=sortb;
	
	return sortb;
}

void main()
{
	int ch, data;
	struct node *first=NULL,*last=NULL;
	
	do 
	{
		printf("\n\nEnter Data : ");
		scanf("%d",&data);
	
		if(first==NULL)
		{
			last=insert(last,data);
			first=last;
		}
		else
		{
			last=insert(last,data);
		}
		printf("\n0. Exit");
		printf("\n1. Insert New Data : ");
		scanf("%d",&ch);
		
	}while(ch==1);
	
	printf("\n\nBefore Sorting : ");
	display(first);
	
	first=sort(first,last);
	last=first->prev;
	
	if(first==NULL)
	{
		printf("\nList is lost.\n");
	}
	else
	{
		printf("\n\nAfter Sorting :  ");
		display(first);
	}
	
	getch();
}

/*
---------------
Output
---------------


Enter Data : 10

0. Exit
1. Insert New Data : 1


Enter Data : 5

0. Exit
1. Insert New Data : 1


Enter Data : 25

0. Exit
1. Insert New Data : 1


Enter Data : 14

0. Exit
1. Insert New Data : 1


Enter Data : 12


0. Exit
1. Insert New Data : 0


Before Sorting :
  10   5   25   14   12

After Sorting :
  5   10   12   14   25
*/
