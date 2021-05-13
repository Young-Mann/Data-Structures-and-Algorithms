// The definition of the data structure "graph".
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;

typedef struct{
	char data;
	ArcNode *firstarc;
}VNode;

typedef struct{
	VNode adjlist[maxsize];
	int n, e;
}AGraph;


// 2. Traverse the graph -- DFS & BFS

#define MAXSIZE 1000;
int visit[MAXSIZE];

// DFS
// The main idea of DFS is: 
// (1) Choose a random vertex, namely "v0", as the beginning vertex
// (2) Visit the chosen vertex.
// (3) Find an adjacent vertex "v1" of the chosen vertex.
// (4) Repeat the procedure (2) and (3) to the adjacent vertex, until we cannot find any neighbour vertex of the present vertex.

// What we need is: 
// 		An array "visit" which shows whether a vertex has been visited or not.
//		A pointer "p" with the type "ArcNode" to do the traverse work.

void DFS(AGraph *G, int v, int visit[MAXSIZE])
{
	ArcNode *p;
	visit[v] = 1;
	Visit(v);
	p = AGraph->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visit[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

// BFS
// The main idea of BFS is:
// (1) Visit and enqueue a random vertex. Then mark it as "visited".
// (2) While the queue is not null: Dequeue the top vertex. Visit, enqueue and mark the unvisited ones.
// (3) If the queue is null: Break the iteration. The BFS is finished.

// What we need is:
// 		An array "visit" which shows whether a vertex has beenvisited or not.
//		A pointer "p" with the type "ArcNode" to do the traverse work.
// 		A queue which holds the visited vertexes, so that we can find its adjacent vertexes at once.

void BFS(AGraph *G, int v, int visit[MAXSIZE])
{
	ArcNode *p;
	int queue[MAXSIZE], front = 0, rear = 0;
	int j;
	
	Visit(v);
	visit[v] = 1;
	
	rear = (rear + 1) % MAXSIZE;
	queue[rear] = v;
	
	while (front != rear)
	{
		front = (front + 1) % MAXSIZE;
		j = queue[front];
		p = G->adjlist[j].firstarc;
		
		while (p != NULL)
		{
			if (visit[p->adjvex] == 0)
			{	
				Visit(p->adjvex);
				visit[p->adjvex]  = 1;
				rear = (rear + 1) % MAXSIZE;
				queue[rear] = p->adjvex;
			}
			
			p = p->nextarc;
		}
	}
	
}


// 对于无向图而言：
// DFS:
void dfs(AGraph *G)
{
	int i;
	for (i = 0; i < g->n; i ++ )
		if (visit[i] == 0)
			DFS(g,i);
}

//BFS同理，故不赘述。


// BFS：