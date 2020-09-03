/*
 Program to check whether a linked list is palindrome or not.

--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *prev,*next;
};

struct node *insert(struct node *first,struct node *newnode)
{
	if(first==NULL)
	{
		first = newnode;
	}
	else
	{
		newnode->next = first;
		first->prev = newnode;
		first = newnode;
	}

	return first;
}

void display(struct node *first)
{
	if(first==NULL)
	{
		printf("\nList is Empty\n");
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

int palindrome(struct node *first)
{
	struct node *temp,*last=NULL;
	int count=1,i;

	if(first==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		temp = first;

		while(temp->next!=NULL)
		{
			temp = temp->next;
			count++;
		}
		last = temp;

		for(i=0;i<count/2;i++)
		{
			if(first->data!=last->data)
			{
				return 0;
			}
			
			first = first->next;
			last = last->prev;
		}
		return 1;
	}
	return 0;
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
		printf("\n3.Palindrome Check");

		printf("\n\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 0:
					exit();
					break;
			case 1:
					printf("\nEnter Data : ");
					scanf("%d",&data);
					newnode = (struct node *)malloc(sizeof(struct node));
					newnode->data = data;
					newnode->prev = NULL;
					newnode->next = NULL;
					first = insert(first,newnode);
					break;
			case 2:
					display(first);
					break;
			case 3:
					ch = palindrome(first);
					display(first);

					if(ch==0)
					{
						printf("\n\nList is Not Palindrome\n");
					}
					else
					{
						printf("\n\nList is Palindrome\n");
					}
					break;
			default:
					printf("\nEnter Proper Choice\n");
		}
	}while(ch!=0);

	getch();
}

/*
--------------
Output
--------------
--------------

0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 10


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 20


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 30


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 40


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 50


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 2
 50  40  30  20  10

0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 3
 50  40  30  20  10

List is Not Palindrome

--------------



0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 10


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 20


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 1

Enter Data : 10


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 2
 10  20  10

0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice : 3
 10  20  10

List is Palindrome


0.Exit
1.Insert
2.Display
3.Palindrome Check

Enter Your Choice :
*/