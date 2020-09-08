/*

--------------------------------------------------------------------------------------------------------------------------------------------------------
Write a Program to create a tree and display the Minimum and Maximum Value present in the tree.
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------
Program
--------------
*/

#include<stdio.h>
#include<conio.h>

struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree *root;

struct tree* insert(struct tree *temp, int val)
{
	if(temp==NULL)
	{
		temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data = val;
		temp->left = temp->right = NULL;
	}
	else if(val < temp->data)
	{
		temp->left = insert(temp->left, val);
	}
	else if(val > temp->data)
	{
		temp->right = insert(temp->right, val);
	}
	return temp;
}

void findMin(struct tree *temp)
{
    if(temp==NULL)
    {
        printf("\nTree does not have any node");
    }
    else
    {
        while(temp->left!=NULL)
        {
            temp = temp->left;
        }
        printf("\nMinimum Value in Tree: %d",temp->data);
    }
}

void findMax(struct tree *temp)
{
    if(temp==NULL)
    {
        printf("\nTree does not have any node");
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp = temp->right;
        }
        printf("\nMaximum Value in Tree: %d",temp->data);
    }
}

void main()
{
    int ch,v;
    do
    {
        printf("\n\n1. Insert into tree");
        printf("\n2. Display Minimum Value in Tree");
        printf("\n3. Display Minimum Value in Tree");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\nEnter Value to insert: ");
                    scanf("%d",&v);
                    root = insert(root, v);
					printf("\nValue Inserted..");
                    break;
            case 2:
                    findMin(root);
                    break;
            case 3:
                    findMax(root);
                    break;
            default:
                    printf("\n\nWrong Option Selected..");
                    break;
        }
    }while(ch!=4);
}

/*
--------------
Output
--------------

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 50

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 47

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 10

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 95

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 5

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 30

Value Inserted..

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 2

Minimum Value in Tree: 5

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 3

Maximum Value in Tree: 95

1. Insert into tree
2. Display Minimum Value in Tree
3. Display Minimum Value in Tree
4. Exit

Enter your choice: 4
*/