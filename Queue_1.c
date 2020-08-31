/*
 Perform following operations on simple queue(use Array):
	A.	Insert
	B.	Delete 

--------------
Program
--------------
*/

#include<conio.h>
#include<stdio.h>
#define size 5
int arr[size];
int front=-1,rear=-1;

void insert()
{
	int item;
	if(rear==size-1)
		printf("\nQueue is Overflow\n");
	else
	{
		if(front==-1)
				front=0;
		printf("\nEnter In Queue:");
		scanf("%d",&item);
		rear++;
		arr[rear]=item;

	}
}

void del()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue is Underflow\n");
		return;
	}
	else
	{
		front++;
	}
}

void display()
{
	int i;
	if(front==-1)
		printf("\nQueue is Empty\n");
	else if(front==-1 || front>rear)
	{
		printf("\nQueue is Underflow\n");
		return;
	}
	else
	{
		printf("\nQueue is:");
		for(i=front;i<=rear;i++)
		{
			printf("\n%d",arr[i]);

		}
		printf("\n");
	}
}

void main()
{
	int ch;
	do
	{
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
		printf("\n0.Exit");
		printf("\nEnter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
		case 0: exit(0);
				break;
		case 1: insert();
				break;
		case 2: del();
				break;
		case 3: display();
				break;
		default:printf("\nEnter Proper Choice:");
				break;

		}

	}while(ch!=0);
	getch();
}
/*
--------------
Output
--------------

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Enter In Queue:10

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Enter In Queue:20

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Enter In Queue:30

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Enter In Queue:40

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Enter In Queue:50

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :1

Queue is Overflow

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :3

Queue is:
10
20
30
40
50

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :3

Queue is:
10
20
30
40
50

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :3

Queue is:
20
30
40
50

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :3

Queue is:
30
40
50

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :2

Queue is Underflow

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :3

Queue is Underflow

1.Insert
2.Delete
3.Display
0.Exit
Enter Your Choice :
*/