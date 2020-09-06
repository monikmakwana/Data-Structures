/*

 Perform following operations on a stack using Linked List:

	->Push
	->Pop
	->Peek


-----------------
Program
-----------------

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *push(struct node *head,struct node *newnode)
{
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}

	return head;
}

struct node *pop(struct node *head)
{
	struct node *temp;

	if(head==NULL)
	{
		printf("\nStack is Underflow\n");
	}
	else
	{
		temp = head;	
		head = head->next;
		printf("\nYou Poped Data %d\n",temp->data);
		free(temp);
	}

	return head;
}

void peep(struct node *head)
{
	struct node *temp;

	if(head==NULL)
	{
		printf("\nStack is Underflow\n");
	}
	else
	{
		temp = head;
		printf("\n");
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}

void peek(struct node *head)
{
	struct node *temp;

	if(head==NULL)
	{
		printf("\nStack is Underflow\n");
	}
	else
	{
		printf("\nThe value stored at top of stack is %d ",head->data);
	}
}

void main()
{
	struct node *head=NULL,*newnode;
	int data,ch;

	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peep");
		printf("\n4.Peek");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 0:
				exit(0);
				break;
		case 1:
				printf("\nEnter Data : ");
				scanf("%d",&data);
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->data = data;
				newnode->next = NULL;
				head = push(head,newnode);
				break;
		case 2:
				head = pop(head);
				break;
		case 3:
				peep(head);
				break;
		case 4: 
				peek(head);
				break;
		default:
				printf("\nPlease Enter Proper Choice");
		}
	}while(ch!=0);
}

/*
-----------
Output 
-----------

0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 1

Enter Data : 10


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 1

Enter Data : 20


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 1

Enter Data : 30


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 3

 30  20  10

0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 4

The value stored at top of stack is 30

0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

You Poped Data 30


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

You Poped Data 20


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

You Poped Data 10


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

Stack is Underflow


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice :
*/