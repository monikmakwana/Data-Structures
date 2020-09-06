/*
 Program to Reverse a linked list. 

---------------
Program
---------------
*/

#include<conio.h>
#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *insert_last(struct node *head)
{
	struct node *temp,*temp2;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter Data:");
		scanf("%d",&head->data);
		head->next=NULL;	
	}
	else
	{
		temp=head;
		temp2=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter Data:");
		scanf("%d",&temp2->data);
		temp2->next=NULL;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=temp2;

	}
	return head;


}
struct node *reverse(struct node *head)
{
	struct node *p1,*p2,*p3;
	p1=NULL;
	p2=head;
	p3=head->next;
	printf("\nLinklist is Reversed\n\n");
	while(p3!=NULL)
	{
		p2->next=p1;
		p1=p2;
		p2=p3;
		p3=p3->next;
	}
	p2->next=p1;
	head=p2;

	return head;
	

}

struct node *insert_first(struct node *head)
{
	
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter Data:");
		scanf("%d",&newnode->data);
		newnode->next=head;
		
		head=newnode;

		return head;
		
	
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp=temp->next;
	}
}

void main()
{
	int ch;
	struct node *head=NULL;
	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Insert Data");
		printf("\n2.Insert First");
		printf("\n3.Display");
		printf("\n4.Reverse Linklist");

		printf("\n\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 0:
			exit(0);
			break;
		case 1:
			 head=insert_last(head);
			 break;
				
		case 2:
			head=insert_first(head);
			break;
				
		case 3:
			 display(head);
			 break;
				
		case 4: 
			head=reverse(head);
			display(head);
			break;
		}
	}while(ch!=0);
	getch();

}

/*
-----------
Output
-----------

0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:1

 Enter Data:10


0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:1

 Enter Data:20


0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:1

 Enter Data:30


0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:1

 Enter Data:40


0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:1

 Enter Data:50


0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:3
  10  20  30  40  50

0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:4

Linklist is Reversed

  50  40  30  20  10

0.Exit
1.Insert Data
2.Insert First
3.Display
4.Reverse Linklist

Enter Your Choice:
*/