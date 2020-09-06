/*

************
Stack
************

1.Perform following operations on a stack using Array:

 -> Push
 -> Pop
 -> Peek

*/

-----------------
Program
-----------------

#include<stdio.h>
#include<conio.h>
#define size 5

int push(int arr[],int top)
{
	if(top==size-1)
	{
		printf("\nStack is Overflow\n");
		return top;
	}
	top++;
	printf("\nEnter Data : ");
	scanf("%d",&arr[top]);

	return top;
}

int pop(int arr[],int top)
{
	if(top==-1)
	{
		printf("\nStack is Underflow\n");
		return top;
	}
	printf("\nYou Poped Data %d\n",arr[top]);
	top--;

	return top;
}

void Peep(int arr[],int top)
{
	int i;
	if(top==-1)
	{
		printf("\nStack is Underflow\n");
	}
	else
	{
		printf("\n");
		for(i=top;i>=0;i--)
		{
			printf(" %d",arr[i]);
		}
	}
}

void Peek(int arr[],int top)
{
	int i;
	if(top==-1)
	{
		printf("\nStack is Underflow\n");
	}
	else
	{
		printf("\nThe value stored at top of stack is %d",arr[top]);
	}

}

void main()
{
	int top=-1,arr[size],ch;

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
				top = push(arr,top);
				break;
		case 2:
				top = pop(arr,top);
				break;
		case 3:
				Peep(arr,top);
				break;
		case 4: 
				Peek(arr,top);
				break;
		default:
				printf("\nPlease Enter Proper Choice\n");
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
Enter Your Choice : 1

Enter Data : 40


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 1

Enter Data : 50


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 1

Stack is Overflow


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 3

 50 40 30 20 10

0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 4

The value stored at top of stack is 50

0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

You Poped Data 50


0.Exit
1.Push
2.Pop
3.Peep
4.Peek
Enter Your Choice : 2

You Poped Data 40


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