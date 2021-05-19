// Minimum Spannning Tree

// ========"Prim"========
// Suppose there are n vertexes in the graph at all. The main idea of "Prim" is: 
// (1) Choose a random vertex as the beginning vertex, and designate the adajacent edges as "candidates".
// (2) Repeat the following procedure for n-1 times to make sure all ther vertexes are involved in the Spanning Tree.
// (2.1) Choose the "candidate" edge with the lowest weight, and add the corresponding vertex "vx" into the tree.
// (2.2) Update the weight of the remaining "candidates".

// What we need includes:
// 		An array "vset", which shows whether a vertex is included in the spanning tree.
//		An array "lowcost", which shows the lowest cost between the unchosen vertexes and the spanning tree.

# define INF 1000010;

void Prim(MGraph g, int v0, int &sum)
{
	int lowcost[MAXSIZE], vset[MAXSIZE];
	int i, j, k min;
	
	for (i = 0; i < g.n; i ++ )
	{
		lowcost[i] = g.edges[i][v0];
		vset[i] = 0;
	}
	
	vset[v0] = 1;
	sum = 0;
	
	for (i = 0; i < g.n - 1; i ++ )
	{
		min = INF;
		for (j = 0; j < g.n; j ++ )
		{
			if (vset[j] == 0 && lowcost[j] < min)
			{
				k = j;
				min = lowcost[j];
			}
		}
		
		vset[k] = 1;
		sum += min;
		
		for (j = 0; j < g.n; j ++ )
		{
			if (vset[j] == 0 && g.edges[j][k] < lowcost[j]) 
				lowcost[j] = g.edges[j][k];
		}

	}
}


// ========"Kruskal"========
typedef struct
{
	int a, b;
	int w;
}Road;
Road road[MAXSIZE];
int v[MAXSIZE];
int getRoot(int a)
{
	while (a != v[a]) a = v[a];
	return a;
}

void Kruskal(MGraph g, int &sum, Road road())
{
	int i; 
	int N = g.n, E = g.e, a, b;
	sum = 0;
	for (i = 0; i < N; i ++ ) v[i] = i;
	sort(road, E);
	for (i = 0; i < E; i ++ )
	{
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += road[i].w;
		}
	}
}