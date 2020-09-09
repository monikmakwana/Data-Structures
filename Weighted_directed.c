/*

--------------------------------------------------------------------------------------------------------------------------------------------------------
Write a program to find the shortest path between two vertices in an weighted directed graph.
--------------------------------------------------------------------------------------------------------------------------------------------------------

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
int top = -1;
int a[20];
void push(int vv)
{
	if (top < 20-1)
	{
		top++;
		a[top] = vv;
	}
	else
	{
		printf("\nStack is Full!");
	}
}
int pop()
{
	int vv;
	if (top != -1)
	{
		vv=a[top];
		top--;
	}
	else
	{
		vv = -1;
	}
	return vv;
}
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
							gt[v].dv = gt[al[j].v - 1].dv + temp->w;
							if (gt[v].dv < min)
							{
								min = gt[v].dv;
								tmin = min;
							}
							gt[v].pv = al[j].v;
						}
						temp = temp->next;
					}
					break;
				}
			}
			else if (gt[j].k == 0 && tmin==gt[j].dv)
			{
				gt[j].k = 1;
				temp = al[j].next;
				while (temp != NULL)
				{
					v = (temp->v)-1;
					if(gt[v].dv == -1 || (gt[v].k==0 && gt[v].dv>0 && gt[v].dv>(gt[al[j].v-1].dv+temp->w)))
					{
						gt[v].dv=gt[al[j].v-1].dv+temp->w;
						printf("\nV:%ld,dist: %ld", gt[v].v,gt[v].dv);
						gt[v].pv = al[j].v;
						if (gt[v].dv > tmin && min > gt[v].dv && min>tmin)
						{
							min = gt[v].dv;
						}
					}
					temp = temp->next;
				}
			}
			if (gt[j].dv > tmin && min > gt[j].dv && min>tmin)
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
void shortpath(gtable gt[], int n,alist al[],int sn)
{
	int sv, dv,v,dd,tv,vv;
	alist *temp = NULL;
	printf("\nEnter destination vertice: ");
	scanf(" %ld", &dv);
	push(dv);
	v=(int)gt[(dv - 1)].pv;
	temp = al[v - 1].next;
	while (temp != NULL)
	{
		if (temp->v == dv)
		{
			dd = temp->w;
		}
		temp = temp->next;
	}
	while(v!=dv)
	{
		push(v);
		tv = v;
		v = gt[v - 1].pv;
		if (v == 0)
		{
			break;
		}
		else
		{
			temp = al[v - 1].next;
			while (temp != NULL)
			{
				if (temp->v == tv)
				{
					dd = dd + temp->w;
					break;
				}
				temp = temp->next;
			}
		}
	}
	printf("\nPath: v%ld", pop());
	vv =pop();
	while (vv != -1)
	{
		printf("->v%ld", vv);
		vv = pop();
	}
	printf("\nShortest path from v%ld to v%ld is: %ld", sn, dv, dd);
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
	alist *al = NULL;
	gtable *gt = NULL;
	int n, sn;
	printf("\nEnter number of vertices in the graph: ");
	scanf(" %ld", &n);
	al = (alist*)calloc(n, sizeof(alist));
	gt = (gtable*)calloc(n, sizeof(gtable));
	insert(al, n, gt);
	displayal(al, n);
	printf("\nEnter Starting node: ");
	scanf(" %ld", &sn);
	ctable(al, n, gt, sn);
	displayt(gt, n);
	while (c == 49)
	{
		shortpath(gt, n, al,sn);
		printf("\nEnter 1 for choosing another path: ");
		scanf(" %c", &c);
	}
	getch();
}

/*
--------------
Output
--------------

Enter number of vertices in the graph: 6

Enter vertice number: 1

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 2

Enter distance between v1 & v2: 3

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 3

Enter distance between v1 & v3: 3

Enter 1 if vertice-1 is pointing to another vertices: 2

Enter vertice number: 2

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 4

Enter distance between v2 & v4: 1

Enter 1 if vertice-2 is pointing to another vertices: 2

Enter vertice number: 3

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 6

Enter distance between v3 & v6: 4

Enter 1 if vertice-3 is pointing to another vertices: 2

Enter vertice number: 4

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 3

Enter distance between v4 & v3: 1

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 5

Enter distance between v4 & v5: 5

Enter 1 if vertice-4 is pointing to another vertices: 2

Enter vertice number: 5

Enter 1 if vertice-5 is pointing to another vertices: 2

Enter vertice number: 6

Enter 1 if vertice-6 is pointing to another vertices: 1

Enter vertice pointed by vertice-6: 5

Enter distance between v6 & v5: 1

Enter 1 if vertice-6 is pointing to another vertices: 2

Adjancency list:
v1->v2 d: 3->v3 d: 3
v2->v4 d: 1
v3->v6 d: 4
v4->v3 d: 1->v5 d: 5
v5
v6->v5 d: 1
Enter Starting node: 1

V:4,dist: 4
V:6,dist: 7
V:5,dist: 9
V:5,dist: 8
Table:
v: 1 1 0 0
v: 2 1 3 1
v: 3 1 3 1
v: 4 1 4 2
v: 5 1 8 6
v: 6 1 7 3
Enter destination vertice: 4

Path: v1->v2->v4
Shortest path from v1 to v4 is: 4
Enter 1 for choosing another path: 1

Enter destination vertice: 2

Path: v1->v2
Shortest path from v1 to v2 is: 3
Enter 1 for choosing another path: 1

Enter destination vertice: 5

Path: v1->v3->v6->v5
Shortest path from v1 to v5 is: 8
Enter 1 for choosing another path:
*/