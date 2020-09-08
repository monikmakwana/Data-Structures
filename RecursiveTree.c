/*
--------------------------------------------------------------------------------------------------------------------------

   Write a program to perform the following:
	
	A. Insert a node in Binary Search tree (Using Recursive Method).

	B. Delete a node from the tree usung Recursive Method.

	C. Traverse through the created tree using recursive method:
		? Pre-Order Traversal
		? In-Order Traversal
		? Post-Order Traversal
		
--------------------------------------------------------------------------------------------------------------------------

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

struct tree *find(struct tree *node) 
{
   if (node == NULL)
      return NULL;

   if (node->left != NULL)
   {
      return find(node->left);
   }
   return node;
}

struct tree* deletes(struct tree *temp, int val) 
{
	if(temp==NULL)
		return NULL;

	if (val < temp->data)
		temp->left = deletes(temp->left, val);
	else if (val > temp->data)
		temp->right = deletes(temp->right, val);
	else
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			printf("\n%d is deleted..",temp->data);
			free(temp);
			temp = NULL;
		}
		else if (temp->left==NULL)
		{
			struct tree *temp1 = temp;
			temp = temp->right;
			printf("\n%d is deleted..",temp1->data);
			free(temp1);
		}
        else if (temp->right==NULL)
		{
			struct tree *temp1 = temp;
			temp = temp->left;
			printf("\n%d is deleted..",temp1->data);
			free(temp1);
		}
		else
		{
			struct tree *temp1 = find(temp->right);
			temp->data = temp1->data;
			temp->right = deletes(temp->right, temp1->data);
		}
	}
	return temp;
}

void preorder(struct tree *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(struct tree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

void main()
{
	struct tree *root = NULL;
    int ch,v;
    do
    {
        printf("\n\n1. Insert into tree");
        printf("\n2. Delete from tree");
		printf("\n3. Pre-Order Display");
        printf("\n4. In-Order Display");
        printf("\n5. Post-Order Display");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\nEnter Value to insert: ");
                    scanf("%d",&v);
                    root = insert(root, v);
                    break;
			case 2:
					printf("\nEnter Value to Delete: ");
                    scanf("%d",&v);
                    root = deletes(root, v);
					break;
			case 3:
                    preorder(root);
                    break;
            case 4:
                    inorder(root);
                    break;
            case 5:
                    postorder(root);
                    break;
            default:
                    printf("\n\nWrong Option Selected..");
                    break;
        }
    }while(ch!=6);
}

/*
--------------
Output
--------------

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 35


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 17


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 27


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 96


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 30


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 89


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 57


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 1

Enter Value to insert: 63


1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 3
35      17      27      30      96      89      57      63

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 2

Enter Value to Delete: 89

89 is deleted..

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 4
17      27      30      35      57      63      96

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 2

Enter Value to Delete: 17

17 is deleted..

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 5
30      27      63      57      96      35

1. Insert into tree
2. Delete from tree
3. Pre-Order Display
4. In-Order Display
5. Post-Order Display
6. Exit

Enter your choice: 6

*/