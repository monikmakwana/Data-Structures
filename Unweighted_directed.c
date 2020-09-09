/*

--------------------------------------------------------------------------------------------------------------------------------------------------------
Write a program to find the shortest path between two vertices in an unweighted directed graph.
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
	alist *temp = NULL,*t=NULL;
	int i,flag=0;
	for (i = 0; i < n; i++)
	{
		printf("\nEnter vertice number: ");
		scanf(" %ld", &al[i].v);
		al[i].next = NULL;
		x = al[i].v;
		gt[i].v=x;
		printf("\nEnter 1 if vertice-%ld is pointing to another vertices: ",al[i].v);
		scanf(" %c",&c);
		flag = 0;
		while (c == 49)
		{
			temp = (alist*)malloc(sizeof(alist));
			printf("\nEnter vertice pointed by vertice-%ld: ", al[i].v);
			scanf(" %ld", &temp->v);
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
			printf("\nEnter 1 if vertice-%ld is pointing to another vertices: ",al[i].v);
			scanf(" %c",&c);
		}
	}
}
void displayal(alist al[], int n)
{
	alist *t = NULL;
	printf("\nAdjancency list:");
	for(int i = 0; i < n; i++)
	{
		printf("\n%ld", al[i].v);
		t = al[i].next;
		while (t!= NULL)
		{
			printf("->%ld",t->v);
			t = t->next;
		}
	}
}
void ctable(alist al[],int n,gtable gt[],int sn)
{
	int i,j,v=0;
	alist *temp = NULL;
	displayal(al, n);
	for (i = 0; i < n; i++)
	{
			gt[i].k = 0;
			gt[i].dv =-1;
			gt[i].pv =-1;
	}
	gt[sn - 1].dv = 0;
	gt[sn - 1].pv = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (gt[j].k == 0 && gt[j].dv==i)
			{
				gt[j].k = 1;
				temp=al[j].next;				
				while (temp != NULL)
				{
					v =(temp->v)-1;
					if (gt[v].dv==-1)
					{
						gt[v].dv = i+1;
						gt[v].pv =al[j].v;
					}
					temp = temp->next;
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
void shortpath(gtable gt[], int n, alist al[], int sn)
{
	int sv, dv,v,dd,tv,vv;
	alist *temp = NULL;
	printf("\nEnter destination vertice: ");
	scanf(" %ld", &dv);
	push(dv);
	v=(int)gt[(dv - 1)].pv;
	dd= gt[(dv - 1)].dv;
	/*temp = al[v - 1].next;
	while (temp != NULL)
	{
		if (temp->v == dv)
		{
			dd = temp->w;
		}
		temp = temp->next;
	}*/
	while(v!=dv)
	{
		push(v);
		tv = v;
		v = gt[v - 1].pv;
		if (v == 0)
		{
			break;
		}
		/*else
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
		}*/
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
void main()
{
	alist *al =NULL;
	gtable *gt = NULL;
	int n, sn;
	char c = 49;
	printf("\nEnter number of vertices in the graph: ");
	scanf(" %ld", &n);
	al = (alist*)calloc(n, sizeof(alist));
	gt = (gtable*)calloc(n, sizeof(gtable));
	insert(al, n, gt);
	displayal(al,n);
	printf("\nEnter Starting node: ");
	scanf(" %ld", &sn);
	ctable(al, n, gt, sn);
	displayt(gt, n);
	while(c==49)
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

Enter number of vertices in the graph: 7

Enter vertice number: 1

Enter 1 if vertice-1 is pointing to another vertices: 1

Enter vertice pointed by vertice-1: 2

Enter 1 if vertice-1 is pointing to another vertices: 2

Enter vertice number: 2

Enter 1 if vertice-2 is pointing to another vertices: 1

Enter vertice pointed by vertice-2: 3

Enter 1 if vertice-2 is pointing to another vertices: 2

Enter vertice number: 3

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 1

Enter 1 if vertice-3 is pointing to another vertices: 1

Enter vertice pointed by vertice-3: 4

Enter 1 if vertice-3 is pointing to another vertices: 2

Enter vertice number: 4

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 2

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 6

Enter 1 if vertice-4 is pointing to another vertices: 1

Enter vertice pointed by vertice-4: 7

Enter 1 if vertice-4 is pointing to another vertices: 2

Enter vertice number: 5

Enter 1 if vertice-5 is pointing to another vertices: 1

Enter vertice pointed by vertice-5: 3

Enter 1 if vertice-5 is pointing to another vertices: 2

Enter vertice number: 6

Enter 1 if vertice-6 is pointing to another vertices: 1

Enter vertice pointed by vertice-6: 5

Enter 1 if vertice-6 is pointing to another vertices: 2

Enter vertice number: 7

Enter 1 if vertice-7 is pointing to another vertices: 1

Enter vertice pointed by vertice-7: 6

Enter 1 if vertice-7 is pointing to another vertices: 2

Adjancency list:
1->2
2->3
3->1->4
4->2->6->7
5->3
6->5
7->6
Enter Starting node: 1

Adjancency list:
1->2
2->3
3->1->4
4->2->6->7
5->3
6->5
7->6
Table:
v: 1 1 0 0
v: 2 1 1 1
v: 3 1 2 2
v: 4 1 3 3
v: 5 1 5 6
v: 6 1 4 4
v: 7 1 4 4
Enter destination vertice: 6

Path: v1->v2->v3->v4->v6
Shortest path from v1 to v6 is: 4
Enter 1 for choosing another path: 1

Enter destination vertice: 4

Path: v1->v2->v3->v4
Shortest path from v1 to v4 is: 3
Enter 1 for choosing another path: 1

Enter destination vertice: 5

Path: v1->v2->v3->v4->v6->v5
Shortest path from v1 to v5 is: 5
Enter 1 for choosing another path: 1

Enter destination vertice: 3

Path: v1->v2->v3
Shortest path from v1 to v3 is: 2
Enter 1 for choosing another path:
*/