/*
 Check whether a symbol is balanced or not using stack.

-----------------
Program
-----------------
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 10

int push(char arr[],char str,int top)
{
	if(top==size)
	{
		printf("\nStack is Full\n");
		return top;
	}
	top++;
	arr[top]=str;

	return top;
}

char pop(char arr[],int top)
{
	if(top==-1)
	{
		printf("\nStack is Empty\n");
		return NULL;
	}

	return arr[top];
}

int check_balance(char str[])
{
	int i,l,top=-1, flag;
	char arr[10],temp;

	l = strlen(str);

	if(l%2==0)
	{
		for(i=0;i<l;i++)
		{
			if(str[i]=='{' || str[i]=='[' || str[i]=='(')
			{
				top = push(arr,str[i],top);
			}
			else if(str[i]=='}' || str[i]==']' || str[i]==')')
			{
				temp = pop(arr,top);
				top--;
				
				if(str[i]=='}' && temp=='{')
				{
					flag= 1;
				}
				else if(str[i]==')' && temp=='(')
				{
					flag=1;
				}
				else if(str[i]==']' && temp=='[')
				{
					flag=1;
				}
				else 
				{
					flag=0;
				}
			}
			else
			{
				printf("\nPlease Enter Symbol Expression...\n");
				return 0;
			}
		}
	}
	else
	{
		flag=0;
	}
	return flag;
}

void main()
{
	int ch;
	char str[10];

	printf("\nEnter Expression : ");
	scanf("%s",str);

	ch = check_balance(str);

	if(ch==0)
	{
		printf("\nNot Balanced\n");
	}
	else
	{
		printf("\nBalanced\n");
	}

	getch();
}

/*
-----------------
Output
-----------------

Enter Expression : (){}[]()

Balanced


Enter Expression : [{()}]

Balanced


Enter Expression : [{()}}

Not Balanced


Enter Expression : {{{[]}}

Not Balanced
*/
