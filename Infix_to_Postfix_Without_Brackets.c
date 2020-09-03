/*
------------------------------------------------------------------------------------------------------------
 WAP to Convert the INFIX EXPRESSION TO POSTFIX EXPRESSION.
------------------------------------------------------------------------------------------------------------

--------------
Program
--------------
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
		printf("\nSTACK IS FULL\n");
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
		printf("\nSTACK IS EMPTY\n");
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

	printf("\nEnter INFIX EXPRESSION : ");
	scanf("%s",infix);

	ans = convert(infix,postfix);

	if(ans==0)
	{
		printf("\nERROR IN INFIX EXPRESSION\n");
	}
	else
	{
		printf("\nPOSTFIX EXPRESSION is %s\n",postfix);
	}

	getch();
}

/*
--------------
Output
--------------

Enter INFIX EXPRESSION : a+b*c-d/e

POSTFIX EXPRESSION is abc*+de/-


Enter INFIX EXPRESSION : A*B-C*D+E/F

POSTFIX EXPRESSION is AB*CD*-EF/+


Enter INFIX EXPRESSION : A*B/C-D/E+F

POSTFIX EXPRESSION is AB*C/DE/-F+


Enter INFIX EXPRESSION : a+b*c/ef

ERROR IN INFIX EXPRESSION


Enter INFIX EXPRESSION : a+b**c

ERROR IN INFIX EXPRESSION

*/