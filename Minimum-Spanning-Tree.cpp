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
	int lowcost[MAXSIZE], vset[MAXSIZE], v;
	
	
	for (int i = 0; i < g.n; i ++ )
	{
		lowcost = g.edges[v0][i];
		vset[i] = 0;
	}
	
	vset[v0] = 1;
	sum = 0;
	
	for (int i = 0; i < g.n - 1; i ++ )
	{
		min = INF;
		for (int j = 0; j < g.n; j ++ )
		{
			if (vset[j] == 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}

		vset[k] = 1;
		sum += lowcost[k];
		
		for (int j = 0; j < g.n; j ++ )
			if (vset[j] == 0 && g.edges[k][j] < lowcost[j])
					lowcost = g.edges[k][j];
	}
}