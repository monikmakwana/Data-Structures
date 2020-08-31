/*
Tree Using Recursion

*****************
Program : 
*****************
*/

#include<conio.h>
#include<stdio.h>

struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree node;

node * create(node *root,int data)
{

	node *newnode;
	if(root==NULL)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		root=newnode;
	}
	else if(data < root->data)
	{
		root->left=create(root -> left , data);
	}
	else if(data > root->data)
	{
		root->right=create(root->right ,data);
	}
	return root;
}
void inOrder(node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("\t%d",root->data);
		inOrder(root->right);
	}
}
void preOrder(node *root)
{
	if(root!=NULL)
	{
		printf("\t%d",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("\t%d",root->data);
	}
}
void main()
{
	node *root=NULL;
	int data,ch;
	printf("\n0.Exit");
	printf("\n1.Create Node");
	printf("\n2.PreOrder");
	printf("\n3.PostOrder");
	printf("\n4.InOrder");

	do
	{
		printf("\n\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Entr Data : ");
				scanf("%d",&data);
				root=create(root,data);
				break;
			case 2:
				printf("\nPre Order : ");
				preOrder(root);
				break;
			case 3:
				printf("\nPost Order : ");
				postOrder(root);
				break;
			case 4:
				printf("\nIn Order : ");
				inOrder(root);
				break;
		}
	}while(ch!=0);
}

/*
*****************
Output : 
*****************

0.Exit
1.Create Node
2.PreOrder
3.PostOrder
4.InOrder

Enter Your Choice : 1
Entr Data : 10


Enter Your Choice : 1
Entr Data : 5


Enter Your Choice : 1
Entr Data : 55


Enter Your Choice : 1
Entr Data : 35


Enter Your Choice : 1
Entr Data : 25


Enter Your Choice : 1
Entr Data : 20


Enter Your Choice : 1
Entr Data : 69


Enter Your Choice : 2

Pre Order :     10      5       55      35      25      20      69

Enter Your Choice : 3

Post Order :    5       20      25      35      69      55      10

Enter Your Choice : 4

In Order :      5       10      20      25      35      55      69

Enter Your Choice :
*/