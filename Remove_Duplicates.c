/*

 Program to remove duplicates values from a linked list.(Use Doubly Linked List)

---------------
Program
---------------
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
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

struct node *remove_dup(struct node *first)
{
	struct node *temp,*temp2,*t,*tt;

	if(first==NULL)
	{
		printf("\nLIST IS EMPTY\n");
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
						tt = temp2;
						temp2->prev->next = tt->next;
						tt->next->prev = temp2->prev;
						temp2 = tt->prev;
						free(tt);					
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
		printf("\nLIST IS EMPTY\n");
	}
	else
	{
		temp = first;

		printf("\n\nDisplay Data \n\n");
		
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}

void main()
{
	int ch,data;
	struct node *first=NULL,*newnode;

	do
	{
		printf("\n\n1.Insert");
		printf("\n2.Remove");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("\nEnter Data : ");
			scanf("%d",&data);

			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->data = data;
			newnode->next=NULL;
			newnode->prev=NULL;

			first = insert(first,newnode);

			break;
		case 2:
			first = remove_dup(first);
			break;
		case 3:
			display(first);
			break;
		case 4:
			exit();
			break;
		}

	}while(ch!=4);
}
/*
---------------
Output
---------------

1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 10


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 20


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 30


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 40


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 10


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 20


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 50


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 60


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 60


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 10


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 20


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 30


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 80


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 90


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 1

Enter Data : 90


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 3


Display Data

 90  90  80  30  20  10  60  60  50  20  10  40  30  20  10

1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 2


1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice : 3


Display Data

 90  80  30  20  10  60  50  40

1.Insert
2.Remove
3.Display
4.Exit
Enter Your Choice :
*/