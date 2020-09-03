/*
----------------------------------------------------------------------------------------------------------------------------
 Write a program to perform Breadth-First Traversal on a graph.
----------------------------------------------------------------------------------------------------------------------------

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
		scanf(" %ld", &al[i].v);
		printf("\nEnter level of vertice-%ld", al[i].v);
		scanf(" %ld", &al[i].l);
		al[i].w = -1;
		al[i].next = NULL;
		x = al[i].v;
		gt[i].v = x;
		printf("\nEnter 1 if vertice-%ld is pointing to another vertices: ", al[i].v);
		scanf(" %c", &c);
		flag = 0;
		while (c == 49)
		{
			temp = (alist*)malloc(sizeof(alist));
			printf("\nEnter vertice pointed by vertice-%ld: ", al[i].v);
			scanf(" %ld", &temp->v);
			printf("\nEnter distance between v%ld & v%ld: ", al[i].v,temp->v);
			scanf(" %ld", &temp->w);
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
			scanf(" %c", &c);
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
			printf("->v%ld d: %ld", t->v,t->w);
			t = t->next;
		}
	}
}

int front = -1, rear = -1,a[20];
void push(int n)
{
	if (rear == -1)
	{
		rear = front = 0;
	}
	else
	{
		rear++;
	}
	a[rear] = n;
}

int pop(alist al[],int n,gtable gt[])
{
	int v,i;
	alist *temp = NULL;
	if (front ==-1)
	{
		v = -1;
	}
	else
	{
		v = a[front];
		if (front == rear)
		{
			front=rear = -1;
		}
		else
		{
			front++;
		}
		temp = al[v - 1].next;
		while (temp != NULL)
		{
			if (gt[(temp->v) - 1].k != 1)
			{
				gt[(temp->v) - 1].k = 1;
				push(temp->v);
			}
			temp = temp->next;
		}
	}
	return v;
}

void ctable(alist al[], int n, gtable gt[], int sn,int ln)
{
	int i, j, v = 0, min = 0, tmin = 0;
	alist *temp = NULL;
	printf("\nBFS Traversal:-	");
	for (i = 1; i <= ln; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (al[j].l == i && gt[j].k!=1)
			{
				gt[j].k = 1;
				push(al[j].v);
			}
		}
		int q = 0;
		while (q != -1)
		{
			q = pop(al, n, gt);
			if (q != -1)
			{
				printf(" v%ld ->", q);
			}
			else
			{
				break;
			}
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
	alist *al = NULL,*st=NULL;
	gtable *gt = NULL;
	int n, sn,ln;
	printf("\nEnter number of vertices in the graph: ");
	scanf(" %ld", &n);
	printf("\nEnter number of levels in the graph: ");
	scanf(" %ld", &ln);
	al = (alist*)calloc(n, sizeof(alist));
	gt = (gtable*)calloc(n, sizeof(gtable));
	st = (alist*)calloc(n, sizeof(alist));
	insert(al, n, gt);
	displayal(al, n);
	printf("\nEnter Starting node: ");
	scanf(" %ld", &sn);
	ctable(al, n, gt, sn,ln);
	getch();
}

/*
--------------
Output
--------------

Enter number of vertices in the graph: 5

Enter number of levels in the graph: 3

Enter vertice number: 1

Enter level of vertice-11

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 2

Enter distance between v1 & v2: 4

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 3

Enter distance between v1 & v3: 2

Enter 1 if vertice-1 is pointing to another vertices: 2

Enter vertice number: 2

Enter level of vertice-21

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 1

Enter distance between v2 & v1: 4

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 3

Enter distance between v2 & v3: 1

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 4

Enter distance between v2 & v4: 4

Enter 1 if vertice-2 is pointing to another vertices: 2

Enter vertice number: 3

Enter level of vertice-32

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 1

Enter distance between v3 & v1: 2

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 2

Enter distance between v3 & v2: 1

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 4

Enter distance between v3 & v4: 5

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 5

Enter distance between v3 & v5: 3

Enter 1 if vertice-3 is pointing to another vertices: 2

Enter vertice number: 4

Enter level of vertice-42

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 2

Enter distance between v4 & v2: 4

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 3

Enter distance between v4 & v3: 3

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 5

Enter distance between v4 & v5: 1

Enter 1 if vertice-4 is pointing to another vertices: 2

Enter vertice number: 5

Enter level of vertice-53

Enter 1 if vertice-5 is pointing to another vertices: 1

Enter vertice pointed by vertice-5: 3

Enter distance between v5 & v3: 3

Enter 1 if vertice-5 is pointing to another vertices: 1

Enter vertice pointed by vertice-5: 4

Enter distance between v5 & v4: 1

Enter 1 if vertice-5 is pointing to another vertices: 2

Adjancency list:
v1->v2 d: 4->v3 d: 2
v2->v1 d: 4->v3 d: 1->v4 d: 4
v3->v1 d: 2->v2 d: 1->v4 d: 5->v5 d: 3
v4->v2 d: 4->v3 d: 3->v5 d: 1
v5->v3 d: 3->v4 d: 1
Enter Starting node: 2

BFS Traversal:-  v1 -> v2 -> v3 -> v4 -> v5

*/