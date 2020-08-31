/*
Create a Binary Search tree (Without Recursion).

*****************
Program : 
*****************
*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct trees
{
	int data;
	struct trees *left,*right;
};
typedef struct trees tree;

tree *create(tree *root,tree *newroot)
{
    tree  *x = root; 
	tree *y = NULL; 
	while (x != NULL) 
	{ 
        y = x; 
		if (newroot->data < x->data) 
		{
			x = x->left; 
		}
		else
		{
			x = x->right; 
		}
   	 } 
   	if (y == NULL) 
	{
		root = newroot; 
	}
    
	else if (newroot->data < y->data) 
	{ 
		y->left = newroot; 
	}
	else if(newroot->data > y->data)
	{
		y->right = newroot; 
	}
    
    return root; 
}

void display(tree *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf(" %d\t",root->data);
		display(root->right);
	}
}

void main()
{
	int ch,value;
	tree *root=NULL,*newroot=NULL;
	do
	{
		printf("\n\n0.Exit");
		printf("\n1.Create Tree");
		printf("\n2.Display");

		printf("\n\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 0:
			exit(0);
		case 1:
			printf("\nEnter the Value:");
			scanf("%d",&value);
			newroot=(tree *)malloc(sizeof(tree));
			newroot->data=value;
			newroot->left=NULL;
			newroot->right=NULL;
			root=create(root,newroot);
			break;
		case 2:
			printf("\n\n");
			display(root);
			break;
	
		}
	}while(ch!=0);
	getch();
}

/*
*****************
Output : 
*****************

0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:10


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:65


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:55


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:45


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:32


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:29


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 1

Enter the Value:49


0.Exit
1.Create Tree
2.Display

Enter Your Choice : 2


 10      29      32      45      49      55      65

0.Exit
1.Create Tree
2.Display

Enter Your Choice :
*/