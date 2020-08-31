/*
Find Minimum and Maximum Value From the Binary Search Tree.

*****************
Program : 
*****************
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
        printf("\nMinimum Value in Tree : %d",temp->data);
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
        printf("\nMaximum Value in Tree : %d",temp->data);
    }
}

void main()
{
    int ch,v;
    do
    {
		printf("\n\n0. Exit");
        printf("\n1. Insert into tree");
        printf("\n2. Display Minimum Value in Tree");
        printf("\n3. Display Maximum Value in Tree");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
			case 0: exit(0);	
					break;
            case 1:
                    printf("\nEnter Value to insert: ");
                    scanf("%d",&v);
                    root = insert(root, v);
				
                    break;
            case 2:
                    findMin(root);
                    break;
            case 3:
                    findMax(root);
                    break;
            default:
                    printf("\n\nPlease Enter Proper Choice \n");
                    break;
        }
    }while(ch!=0);
}

/*
*****************
Output : 
*****************

0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 10


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 20


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 90


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 80


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 65


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 1

Enter Value to insert: 55


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 43


Please Enter Proper Choice


0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 2

Minimum Value in Tree : 10

0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice: 3

Maximum Value in Tree : 90

0. Exit
1. Insert into tree
2. Display Minimum Value in Tree
3. Display Maximum Value in Tree
4. Exit

Enter your choice:
*/