/*
Program to perform Intersection of two sets of lists. 

--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *insert(struct node *temp,struct node *newnode)
{
	if(temp==NULL)
	{
		newnode->next = NULL;
		temp = newnode;
	}
	else
	{
		newnode->next = temp;
		temp = newnode;
	}
	return temp;
}

void display(struct node *temp)
{
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

struct node *intersection(struct node *list1,struct node *list2,struct node *list3)
{
	struct node *temp1,*newnode;
	while(list1!=NULL)
	{
		temp1 = list2;
		while(temp1!=NULL)
		{
			if(list1->data == temp1->data)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->data = list1->data;
				list3 = insert(list3,newnode);
			}
			temp1 = temp1->next;
		}
		list1 = list1->next;
	}

	return list3;
}

void main()
{
	struct node *list1=NULL,*list2=NULL,*list3=NULL,*newnode;
	int ch,data;

	printf("\nEnter data in List 1\n");
	do
	{
		printf("\nEnter Data : ");
		scanf("%d",&data);

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = data;

		list1 = insert(list1,newnode);

		ch=0;
		printf("\n0.Exit from List 1");
		printf("\n1.Insert Again");
		printf("\nEnter Choice :");
		scanf("%d",&ch);

	}while(ch==1);

	printf("\n\nEnter data in List 2\n");
	do
	{
		printf("\nEnter Data : ");
		scanf("%d",&data);

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = data;

		list2 = insert(list2,newnode);

		ch=0;
		printf("\n0.Exit from List 1");
		printf("\n1.Insert Again");
		printf("\nEnter Choice :");
	
		scanf("%d",&ch);

	}while(ch==1);

	printf("\n\nList 1 Values\n");
	display(list1);

	printf("\n\nList 2 Values\n");
	display(list2);

	list3 = intersection(list1,list2,list3);
	printf("\n\nIntersection Values \n");
	display(list3);

	getch();
}

/*
------------
Output
------------

Enter data in List 1

Enter Data : 10

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 20

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 30

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 40

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 50

0.Exit from List 1
1.Insert Again
Enter Choice :0


Enter data in List 2

Enter Data : 40

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 50

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 60

0.Exit from List 1
1.Insert Again
Enter Choice :1

Enter Data : 70

0.Exit from List 1
1.Insert Again
Enter Choice :0


List 1 Values
 50  40  30  20  10

List 2 Values
 70  60  50  40

Intersection Values
 40  50
*/