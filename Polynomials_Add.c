/*

Program to perform addition of two polynomials. 

--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>

struct term
{
	int coefficient;
	int power;

	struct term *next;
};

struct term *insert(struct term *first,struct term *newnode)
{
	struct term *p1, *p2;

	if(first == NULL)
	{
		first = newnode;
	}
	else if(newnode->power >= first->power)
	{
		if(newnode->power == first->power)
		{
			first->coefficient = first->coefficient + newnode->coefficient;
		}
		else
		{
			newnode->next = first;
			first = newnode;	
		}
	}
	else
	{
		p1=first;
		p2=first->next;
		while((p2!=NULL) && (p2->power >= newnode->power) )
		{
			if(newnode->power == p2->power)
			{
				p2->coefficient = p2->coefficient + newnode->coefficient;
				return first;
			}

			p1=p2;
			p2=p2->next;
		}
		p1 -> next = newnode;
		newnode->next=p2;
	}

	return first;
}

struct term *add(struct term *first,struct term *first2,struct term *first3)
{
	struct term *p1,*p2,*p3,*newnode;
	p1=first;
	p2=first2;
	p3=first3;

	while( (p1!=NULL) && (p2!=NULL) )
	{
		newnode = (struct term *)malloc(sizeof(struct term));
		if(p1->power == p2->power)
		{
			newnode->power = p1->power;
			newnode->coefficient = p1->coefficient + p2->coefficient;
			newnode->next =NULL;

			first3 = insert(first3,newnode);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->power > p2->power)
		{
			newnode->power = p1->power;
			newnode->coefficient = p1->coefficient;
			newnode->next =NULL;

			first3 = insert(first3,newnode);			
			p1=p1->next;
		}
		else
		{
			newnode->power = p2->power;
			newnode->coefficient = p2->coefficient;
			newnode->next =NULL;

			first3 = insert(first3,newnode);			
			p2 = p2->next;
		}
	}

	if(p1==NULL)
	{
		while(p2!=NULL)
		{
			newnode= (struct term *)malloc(sizeof(struct term));
			newnode->power = p2->power;
			newnode->coefficient = p2->coefficient;
			newnode->next =NULL;

			first3 = insert(first3,newnode);			
			p2 = p2->next;
		}
	}
	else
	{
		while(p1!=NULL)
		{
			newnode = (struct term *)malloc(sizeof(struct term));
			newnode->power = p1->power;
			newnode->coefficient = p1->coefficient;
			newnode->next =NULL;

			first3 = insert(first3,newnode);			
			p1=p1->next;
		}
	}

	return first3;
}

void display(struct term *first)
{
	struct term *p;
	p=first;
	while(p!=NULL)
	{
		if(p->coefficient!=0)
		{
			printf(" %d",p->coefficient);
			if(p->power != 0)
				printf("x^%d  ",p->power);
			if(p->next != NULL)
				printf(" + ");
		}
		p=p->next;
	}
}

void main()
{
	int coeff,pow,ch;
	struct term *first=NULL,*first2=NULL,*first3=NULL,*newnode;

	printf("\nEnter Data For 1st Equation.\n");
	do
	{
		newnode = (struct term *)malloc(sizeof(struct term));
		printf("\nEnter Coefficient of Term : ");
		scanf("%d",&coeff);
		printf("Enter Power of Term : ");
		scanf("%d",&pow);

		newnode->coefficient = coeff;
		newnode->power = pow;
		newnode->next=NULL;

		first = insert(first,newnode);
		ch=0;
		printf("\n0.Exit");
		printf("\n1.Add new Term");
		printf("\nEnter Choice:");
		scanf("%d",&ch);

	}while(ch==1);

	printf("\nEnter Data For 2nd Equation.\n");
	do
	{
		newnode = (struct term *)malloc(sizeof(struct term));
		printf("\nEnter Coefficient of Term : ");
		scanf("%d",&coeff);
		printf("Enter Power of Term : ");
		scanf("%d",&pow);

		newnode->coefficient = coeff;
		newnode->power = pow;
		newnode->next=NULL;

		first2 = insert(first2,newnode);
		ch=0;
		printf("\n0.Exit");
		printf("\n1.Add new Term");
		printf("\nEnter Choice:");
		scanf("%d",&ch);

	}while(ch==1);

	printf("\n1st Equation : \n");
	display(first);
	printf("\n\n2nd Equation : \n");
	display(first2);

	first3=add(first,first2,first3);
	printf("\n\nAddition of Equation\n");
	display(first3);

	getch();
}
/*
--------------
Output
--------------

Enter Data For 1st Equation.

Enter Coefficient of Term : 2
Enter Power of Term : 3

0.Exit
1.Add new Term
Enter Choice:1

Enter Coefficient of Term : 3
Enter Power of Term : 3

0.Exit
1.Add new Term
Enter Choice:1

Enter Coefficient of Term : 4
Enter Power of Term : 1

0.Exit
1.Add new Term
Enter Choice:0

Enter Data For 2nd Equation.

Enter Coefficient of Term : 2
Enter Power of Term : 4

0.Exit
1.Add new Term
Enter Choice:1

Enter Coefficient of Term : 3
Enter Power of Term : 2

0.Exit
1.Add new Term
Enter Choice:0

1st Equation :
 5x^3   +  4x^1

2nd Equation :
 2x^4   +  3x^2

Addition of Equation
 2x^4   +  5x^3   +  3x^2   +  4x^1
*/