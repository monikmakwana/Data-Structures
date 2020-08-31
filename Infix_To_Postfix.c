/*
 Convert an infix expression into postfix expression using stack. 

-----------------
Program
-----------------
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int prior(char c)
{
	switch(c)
	{
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	}
}

int push(char arr[],char opr,int top)
{
	if(top==9)
	{
		printf("\nStack is Full\n");
		return top;
	}

	top++;
	arr[top] = opr;

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

int convert(char infix[],char postfix[])
{
	int i,l,j=0,top=-1,rank=0;
	char temp,arr[10];

	l = strlen(infix);

	for(i=0;i<l;i++)
	{
		if( (infix[i]>=97 && infix[i]<=122) || (infix[i]>=65 && infix[i]<=90))
		{
			postfix[j] = infix[i];
			j++;
			rank++;
			
			if(rank!=1)
			{
				return 0;
			}
		}
		else if(infix[i] == '/' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-')
		{
			rank--;
			if(rank!=0)
			{
				return 0;
			}
						
			if(top==-1)
			{
				top = push(arr,infix[i],top);
			}
			else
			{
				while( (prior(infix[i]) <= prior(arr[top])) && top!=-1)
				{
					postfix[j] = pop(arr,top);
					j++;
					top--;
				}
				top = push(arr,infix[i],top);				
			}			
		}
		else
		{
			return 0;
		}
	}

	while(top!=-1)
	{
		temp = pop(arr,top);
		top--;
		postfix[j] = temp;
		j++;
	}

	postfix[j] = NULL;
	return 1;

}

void main()
{
	char infix[15],postfix[15];
	int ans=0;

	printf("\nEnter Infix Expression : ");
	scanf("%s",infix);

	ans = convert(infix,postfix);

	if(ans==0)
	{
		printf("\nError in Infix Expression\n");
	}
	else
	{
		printf("\nPostfix Expression : %s\n",postfix);
	}

	getch();
}

/*
-----------------
Output
-----------------

Enter Infix Expression : a+b*c/d+f

Postfix Expression : abc*d/+f+


Enter Infix Expression : a*b*c+d

Postfix Expression : ab*c*d+
*/
