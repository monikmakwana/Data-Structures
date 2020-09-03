/*
---------------------------------------------------------------------------------------------------------------------------------
WAP to Convert the INFIX EXPRESSION TO POSTFIX EXPRESSION with Brackets.
---------------------------------------------------------------------------------------------------------------------------------

--------------
Program
--------------
*/


#include<stdio.h>
#include<conio.h>

int prior(char op)
{
	switch(op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 0;
	}
}

int push(char s[],int top,char op)
{
	top++;
	s[top] = op;

	return top;
}

char pop(char s[],int top)
{
	if(top == -1)
	{
		printf("\nSTACK IS EMPTY\n");
		return NULL;
	}

	return s[top];
}

int convert(char infix[],char postfix[])
{
	char s[15],temp;
	int i,l,j=0,top=-1,rank=0,b=0;

	l = strlen(infix);

	if(l%2==0)
		return 1;

	for(i=0;i<l;i++)
	{
		if(infix[i]>='a' && infix[i]<='z')
		{
			postfix[j] = infix[i];
			j++;		
			rank++;

			if(rank!=1)
			{
				return 1;
			}
		}
		else if(infix[i] == '(' || infix[i] == ')')
		{
			switch(infix[i])
			{
			case '(':
				b++;
				top = push(s,top,infix[i]);
				break;	

			case ')':
				b--;
				temp = pop(s,top);

				if(temp==NULL)
					return 1;

				while( temp != '(' )	
				{
					postfix[j] = temp;
					j++;
					top--;
					temp = pop(s,top);
					
					if(temp==NULL)
						return 1;
				}
				top--;

				break;
			}
		}
		else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			rank--;
			if(rank!=0)
			{
				return 1;
			}
			if(top==-1)
			{
				top = push(s,top,infix[i]);
			}
			else
			{

				while( (prior(infix[i]) <= prior(s[top])) && top!=-1 )
				{
					postfix[j] = pop(s,top);
					j++;
					top--;			
				}
				top = push(s,top,infix[i]);			
			}

		}		
		else
		{
			return 1;
		}
	}

	while(top!=-1)
	{
		postfix[j] = pop(s,top);
		top--;
		j++;
	}
	postfix[j] = NULL;

	if(b!=0)
	{
		return 1;
	}

	return 0;
}

void main()
{
	int ch;
	char infix[20],postfix[20];

	do
	{
		printf("\nEnter INFIX EXPRESSION : ");
		scanf("%s",infix);

		ch = convert(infix,postfix);

		if(ch==0)
		{
			printf("\nINFIX EXPRESSION : %s \n",infix);
			printf("\nPOSTFIX EXPRESSION : %s",postfix);
		}
		else
		{
			printf("\nERROR IN EXPRESSION\n");
		}

		printf("\n\nDO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :");
		scanf("%d",&ch);

	}while(ch==1);

}

/*
--------------
Output
--------------

Enter INFIX EXPRESSION : (a+b)*c+(d-e)

INFIX EXPRESSION : (a+b)*c+(d-e)

POSTFIX EXPRESSION : ab+c*de-+

DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :1

Enter INFIX EXPRESSION : (a+b)*

ERROR IN EXPRESSION


DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :1

Enter INFIX EXPRESSION : (a+b+)

ERROR IN EXPRESSION


DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :1

Enter INFIX EXPRESSION : (a+b)*c)

ERROR IN EXPRESSION


DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :1

Enter INFIX EXPRESSION : ((a+b)+c

ERROR IN EXPRESSION


DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :((a+b)*(d-e))/f

Enter INFIX EXPRESSION :
INFIX EXPRESSION : ((a+b)*(d-e))/f

POSTFIX EXPRESSION : ab+de-*f/

DO YOU WANT TO TRY NEXT EXPRESSION ? [PRESS --> 1] :0

*/