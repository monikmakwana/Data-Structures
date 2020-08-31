/* 
 Perform following operations on a Circular queue(use Array):
	A.	Insert
	B.	Delete 


--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>
#define n 10
int insert(int arr[],int rear,int *front)
{
	if(rear==-1)
	{
		*front=0;
		rear=0;
		printf("Enter Data :");
		scanf("%d",&arr[rear]);
	}
	else if(rear>=n-1 && *front==0)
	{
		printf("\nQueue is full\n");
	}
	else if(rear==*front-1)
	{
		printf("\nQueue is full\n");
	}
	else
	{
		rear++;
		if(rear>=n)
		{
			rear=rear%n;
		}
		printf("Enter Data : ");
		scanf("%d",&arr[rear]);
	}
	return rear;
}

int del(int arr[],int front,int *rear)
{
	if(front==-1)
	{
		printf("Queue is empty");
	}
	else if(front==*rear)
	{
		printf("\nLast element of queue deleted %d",arr[front]);
		front=-1;
		*rear=-1;
	}
	else
	{
		printf("\nElement deleted from queue %d",arr[front]);
		front++;

		if(front>=n)
		{
			front=front%n;
		}
	}
	return front;
}

void display(int arr[],int front,int *rear)
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nQueue Data\n");
		while(front!=*rear)
		{
			printf(" %d ",arr[front]);
			front++;

			if(front>=n)
			{
				front=front%n;
			}
		}
		printf(" %d \n",arr[front]);
	}
}

void main()
{
	int ch,arr[10],rear=-1,front=-1;
	
	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
		
		printf("\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			rear=insert(arr,rear,&front);
			break;
		case 2:
			front=del(arr,front,&rear);
			break;
		case 3:
			display(arr,front,&rear);
			break;
		case 0:
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
1.Insert
2.Delete
3.Display
Enter your Choice : 1
Enter Data :10


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 1
Enter Data : 20


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 1
Enter Data : 30


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 1
Enter Data : 40


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 1
Enter Data : 50


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 1

Queue is full


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 3

Queue Data
 10  20  30  40  50


0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2

Element deleted from queue 10

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2

Element deleted from queue 20

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2

Element deleted from queue 30

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2

Element deleted from queue 40

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2

Last element of queue deleted 50

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice : 2
Queue is empty

0.Exit
1.Insert
2.Delete
3.Display
Enter your Choice :
*/