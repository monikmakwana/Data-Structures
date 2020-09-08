/*

-------------------------------------------------------------------------------------------------------------------
Write a program to find the minimum spanning tree of a graph using Prim’s Algorithm.
-------------------------------------------------------------------------------------------------------------------

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
void ctable(alist al[], int n, gtable gt[], int sn)
{
	int i, j, v = 0,min=0,tmin=0;
	alist *temp = NULL;
	for (i = 0; i < n; i++)
	{
		gt[i].k = 0;
		gt[i].dv = -1;
		gt[i].pv = -1;
	}
	gt[sn - 1].dv = 0;
	gt[sn - 1].pv = 0;
	for (i = 0; i < n; i++)
	{
		min = 100;
		for (j = 0; j < n; j++)
		{
			if (i==0)
			{
				if (gt[j].v == sn)
				{
					gt[j].k = 1;
					temp = al[j].next;
					while (temp != NULL)
					{
						v = (temp->v) - 1; 
						if (gt[v].dv == -1)
						{
							gt[v].dv =temp->w;
							if (gt[v].dv < min)
							{
								min = gt[v].dv;
							}
							gt[v].pv = al[j].v;
						}
						temp = temp->next;
					}
					tmin = min;
					min = 100;
					j = n - 1;
					break;
				}
			}
			else if (gt[j].k == 0 && tmin==gt[j].dv)
			{
				gt[j].k = 1;
				min = 100;
				temp = al[j].next;
				while (temp != NULL)
				{
					v = (temp->v)-1;
					if(gt[v].dv == -1 || (gt[v].k==0 && gt[v].dv>0 && gt[v].dv>(temp->w)))
					{
						gt[v].dv=temp->w;
						gt[v].pv = al[j].v;
						if (min > gt[v].dv)
						{
							min = gt[v].dv;
						}
					}
					temp = temp->next;
				}
			}
			if (gt[j].k==0 && min > gt[j].dv && gt[j].dv!=-1 && gt[j].dv!=0)
			{
				min = gt[j].dv;
			}
			if (j == (n - 1))
			{
				tmin = min;
			}
		}
	}
}

void spantree(gtable gt[],int n,alist st[])
{
	alist *temp=NULL,*otemp=NULL,*ttemp=NULL;
	for (int i = 0; i < n; i++)
	{
		st[i].v=gt[i].v;
		st[i].next = NULL;
		otemp = NULL;
		temp = NULL;
		for (int j = 0; j < n; j++)
		{
			if (gt[j].pv == st[i].v)
			{
				temp=(alist*)malloc(sizeof(alist));
				temp->v=gt[j].v;
				temp->w=gt[j].dv;
				temp->next = NULL;
				if (otemp == NULL)
				{
					otemp = temp;
					st[i].next = temp;
				}
				else
				{
					otemp->next = temp;
					otemp = temp;
				}
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
	int n, sn;
	printf("\nEnter number of vertices in the graph: ");
	scanf(" %ld", &n);
	al = (alist*)calloc(n, sizeof(alist));
	gt = (gtable*)calloc(n, sizeof(gtable));
	st = (alist*)calloc(n, sizeof(alist));
	insert(al, n, gt);
	displayal(al, n);
	printf("\nEnter Starting node: ");
	scanf(" %ld", &sn);
	ctable(al, n, gt, sn);
	displayt(gt, n);
	spantree(gt,n,st);
	printf("\nSpanning Tree: ");
	displayal(st, n);
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

Enter distance between v1 & v2: 4

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 3

Enter distance between v1 & v3: 2

Enter 1 if vertice-1 is pointing to another vertices: 2

Enter vertice number: 2

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

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 2

Enter distance between v4 & v2: 4

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 3

Enter distance between v4 & v3: 5

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 5

Enter distance between v4 & v5: 1

Enter 1 if vertice-4 is pointing to another vertices: 2

Enter vertice number: 5

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
v4->v2 d: 4->v3 d: 5->v5 d: 1
v5->v3 d: 3->v4 d: 1
Enter Starting node: 2

Table:
v: 1 1 2 3
v: 2 1 0 0
v: 3 1 1 2
v: 4 1 1 5
v: 5 1 3 3
Spanning Tree:
Adjancency list:
v1
v2->v3 d: 1
v3->v1 d: 2->v5 d: 3
v4
v5->v4 d: 1

*/