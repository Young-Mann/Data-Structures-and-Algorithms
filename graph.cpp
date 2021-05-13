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
