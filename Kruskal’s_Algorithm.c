/*
----------------------------------------------------------------------------------------------------------------------------
Write a program to find the minimum spanning tree of a graph using Kruskal’s Algorithm.
----------------------------------------------------------------------------------------------------------------------------

--------------
Program
--------------

*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
typedef struct Edge
{
	int s,d,w;
}edge;
typedef struct Graph
{
	int v,e;
	edge* ed;
}graph;
typedef struct subset
{
	int parent;
	int rank;
}subset;
graph* cgraph(graph *gg,int nv,int ne)
{
	edge *ee = NULL;
	gg = (graph*)malloc(sizeof(graph));
	gg->v = nv;
	gg->e = ne;
	ee = (edge*)calloc(ne, sizeof(edge));
	for (int i = 0; i < ne; i++)
	{
		printf("\nEnter Source vertice: ");
		scanf(" %ld", &ee[i].s);
		printf("\nEnter Destination vertice: ");
		scanf(" %ld", &ee[i].d);
		printf("\nEnter Weight of Edge:- v%ld to v%ld: ", ee[i].s, ee[i].d);
		scanf(" %ld", &ee[i].w);
	}
	gg->ed = ee;
	return gg;
}
void displaye(edge ee[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nSource: v%ld, Destination: v%ld, Weight: %ld", ee[i].s, ee[i].d, ee[i].w);
	}
}
void swap(edge *a, edge *b)
{
	edge t;
	t = *a;
	*a = *b;
	*b = t;
}
graph* sort(graph *gg)
{
	int n, i, j;
	edge *temp,*ed;
	n =gg->e;
	ed = gg->ed;
	int min;
	printf("\nBefore sorting: ");
	displaye(ed, n);
	temp = (edge*)malloc(sizeof(edge));
	for (i = 0; i < n-1; i++)
	{
		/*temp->d = ed[i].d;
		temp->s = ed[i].s;
		temp->w = ed[i].w;*/
		min = i;
		for (j = i+1; j < n; j++)
		{
			if (ed[min].w > ed[j].w)
			{
				min = j;
			}
		}
		swap(&ed[min], &ed[i]);
	}
	printf("\nAfter sorting: ");
	displaye(ed, n);
	return gg;
}
int find(subset subsets[],int i)
{
	if (subsets[i].parent!=i)
	{
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}
void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);
	if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;
	}
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
void kruskal(graph *gg)
{
	int V = gg->v;
	int e=0,i=0;
	edge result[20],nextedge;
	gg=sort(gg);
	subset *subsets = (subset*)malloc(V * sizeof(subset));
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	i = 0;
	while (e<V-1 && i<gg->e)
	{
		nextedge = gg->ed[i];
		i++;
		printf("\nYo!");
		int x = find(subsets, nextedge.s);
		int y = find(subsets,nextedge.d);
		if (x != y)
		{
			result[e] = nextedge;
			e++;
			printf("\nYoy");
			Union(subsets, x, y);
		}
	}
	printf("\nSpantree: ");
	displaye(result, e);
}
void main()
{
	graph *gg=NULL; 
	int nv, ne;
	printf("\nEnter number of Vertices: ");
	scanf(" %ld", &nv);
	printf("\nEnter number of Edges: ");
	scanf(" %ld", &ne);
	gg=cgraph(gg,nv,ne);
	kruskal(gg);
	spantree(gt,n,st);
	printf("\nSpanning Tree: ");
	displayal(st, n);
	getch();
}

/*
--------------
Output
--------------

Enter number of Vertices: 5

Enter number of Edges: 7

Enter Source vertice: 1

Enter Destination vertice: 2

Enter Weight of Edge:- v1 to v2: 4

Enter Source vertice: 1

Enter Destination vertice: 3

Enter Weight of Edge:- v1 to v3: 2

Enter Source vertice: 2

Enter Destination vertice: 3

Enter Weight of Edge:- v2 to v3: 1

Enter Source vertice: 2

Enter Destination vertice: 4

Enter Weight of Edge:- v2 to v4: 4

Enter Source vertice: 3

Enter Destination vertice: 4

Enter Weight of Edge:- v3 to v4: 5

Enter Source vertice: 3

Enter Destination vertice: 5

Enter Weight of Edge:- v3 to v5: 3

Enter Source vertice: 4

Enter Destination vertice: 5

Enter Weight of Edge:- v4 to v5: 1

Before sorting:
Source: v1, Destination: v2, Weight: 4
Source: v1, Destination: v3, Weight: 2
Source: v2, Destination: v3, Weight: 1
Source: v2, Destination: v4, Weight: 4
Source: v3, Destination: v4, Weight: 5
Source: v3, Destination: v5, Weight: 3
Source: v4, Destination: v5, Weight: 1
After sorting:
Source: v2, Destination: v3, Weight: 1
Source: v4, Destination: v5, Weight: 1
Source: v1, Destination: v3, Weight: 2
Source: v3, Destination: v5, Weight: 3
Source: v2, Destination: v4, Weight: 4
Source: v1, Destination: v2, Weight: 4
Source: v3, Destination: v4, Weight: 5
Spanning Tree:
Adjancency list:
v1
v2->v3 d: 1
v3->v1 d: 2->v5 d: 3
v4
v5->v4 d: 1

*/