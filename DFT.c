/*

---------------------------------------------------------------------------------------------------------
Write a program to perform Depth-First Traversal on a graph.
---------------------------------------------------------------------------------------------------------

--------------
Program
--------------

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct alist
{
	int v;
	int w;
	int l;
	struct alist *next;
};
typedef struct alist alist;
struct gtable
{
	int k, v, dv, pv;
};
typedef struct gtable gtable;
void insert(alist al[], int n, gtable gt[])
{
	char c = 49;
	int x;
	alist *temp = NULL, *t = NULL;
	int i, flag = 0;
	for (i = 0; i < n; i++)
	{
		printf("\nEnter vertice number: ");
		scanf_s(" %ld", &al[i].v);/*
		printf("\nEnter level of vertice-%ld", al[i].v);
		scanf_s(" %ld", &al[i].l);*/
		al[i].w = -1;
		al[i].next = NULL;
		x = al[i].v;
		gt[i].v = x;
		printf("\nEnter 1 if vertice-%ld is pointing to another vertices: ", al[i].v);
		scanf_s(" %c", &c);
		flag = 0;
		while (c == 49)
		{
			temp = (alist*)malloc(sizeof(alist));
			printf("\nEnter vertice pointed by vertice-%ld: ", al[i].v);
			scanf_s(" %ld", &temp->v);/*
			printf("\nEnter distance between v%ld & v%ld: ", al[i].v, temp->v);
			scanf_s(" %ld", &temp->w);*/
			temp->next = NULL;
			if (flag == 0)
			{
				al[i].next = temp;
				t = temp;
				flag = 1;
			}
			else
			{
				t->next = temp;
				t = temp;
			}
			printf("\nEnter 1 if vertice-%ld is pointing to another vertices: ", al[i].v);
			scanf_s(" %c", &c);
		}
	}
}
void displayal(alist al[], int n)
{
	alist *t = NULL;
	printf("\nAdjancency list:");
	for (int i = 0; i < n; i++)
	{
		printf("\nv%ld", al[i].v);
		t = al[i].next;
		while (t != NULL)
		{
			printf("->v%ld", t->v);
			t = t->next;
		}
	}
}

int top = -1;
alist *a[20] = { NULL };

void push(alist *temp,gtable gt[],int n,alist al[])
{
	alist *t = NULL;
	top++;
	if (temp!=NULL && gt[(temp->v)-1].k==0)
	{
		a[top] = temp;
		gt[(temp->v) - 1].k = 1;
		printf("v%ld->", temp->v);
		push(al[(temp->v)-1].next, gt, n,al);
	}
	else if (temp!=NULL && gt[(temp->v) - 1].k == 1)
	{
		temp = temp->next;
		if (temp != NULL)
		{
			push(temp, gt, n,al);
		}
	}
}
int pop(alist al[], int n, gtable gt[])
{
	int i,v;
	alist *temp = NULL;
	if (top == -1)
	{
		v=-1;
	}
	else
	{
		v = top;
		top--;
	}
	return v;
}
void ctable(alist al[], int n, gtable gt[], int sn)
{
	int i, j, v = 0, min = 0, tmin = 0;
	alist *temp = NULL;
	for (i = 0; i < n; i++)
	{
		gt[i].k = 0;
	}
	printf("\nDFS Traversal:-	");
		for (j = 0; j < n; j++)
		{
			if (al[j].v == sn)
			{
				push(&al[j], gt, n,al);
				while (v != -1)
				{
					v = pop(al, n, gt);
				}
				break;
			}
		}
}

void displayt(gtable gt[], int n)
{
	int i;
	printf("\nTable: ");
	for (i = 0; i < n; i++)
	{
		printf("\nv: %ld %ld %ld %ld", gt[i].v, gt[i].k, gt[i].dv, gt[i].pv);
	}
}
void main()
{
	char c = 49;
	alist *al = NULL, *st = NULL;
	gtable *gt = NULL;
	int n, sn;
	printf("\nEnter number of vertices in the graph: ");
	scanf_s(" %ld", &n);
	al = (alist*)calloc(n, sizeof(alist));
	gt = (gtable*)calloc(n, sizeof(gtable));
	st = (alist*)calloc(n, sizeof(alist));
	insert(al, n, gt);
	displayal(al, n);
	printf("\nEnter Starting node: ");
	scanf_s(" %ld", &sn);
	ctable(al, n, gt, sn);
	
	getch();
}

/*
--------------
Output
--------------

Enter number of vertices in the graph: 5

Enter vertice number: 1

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 2

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 3

Enter 1 if vertice-1 is pointing to another vertices: 2

Enter vertice number: 2

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 1

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 3

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 4

Enter 1 if vertice-2 is pointing to another vertices: 2

Enter vertice number: 3

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 1

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 2

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 4

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 5

Enter 1 if vertice-3 is pointing to another vertices: 2

Enter vertice number: 4

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 2

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 3

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 5

Enter 1 if vertice-4 is pointing to another vertices: 2

Enter vertice number: 5

Enter 1 if vertice-5 is pointing to another vertices: 1

Enter vertice pointed by vertice-5: 3

Enter 1 if vertice-5 is pointing to another vertices: 1

Enter vertice pointed by vertice-5: 4

Enter 1 if vertice-5 is pointing to another vertices: 2

Adjancency list:
v1->v2->v3
v2->v1->v3->v4
v3->v1->v2->v4->v5
v4->v2->v3->v5
v5->v3->v4
Enter Starting node: 2

DFS Traversal:- v2->v1->v3->v4->v5

*/