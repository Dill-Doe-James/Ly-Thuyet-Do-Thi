#include <stdio.h>
#define MAX_SIZE 100
//DUYET THEO CHIEU RONG (QUEUE)	

//Khai bao CTDL Graph
#define MAX_N 100
typedef struct{
	int n,m; //n: dinh, m: cung
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
	int u,v;
	for (u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			G->A[u][v] = 0;
		}
	}
}

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
	G->A[v][u] = 1;
	G->m++;
}
int adjacent(Graph *G, int u, int v){
	return G->A[u][v] > 0;
	
}
//Khai bao CTDL Queue
typedef struct{
	int data[MAX_SIZE];
	int front,rear;
}Queue;

void makenullQueue(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void enQueue(Queue *Q, int u){
	Q->rear++;
	Q->data[Q->rear] = u;
}

int front(Queue *Q){
	return Q->data[Q->front];
}

void deQueue(Queue *Q){
	Q->front++;
}

int empty(Queue *Q){
	return Q->front > Q->rear;
}
//Duyet theo chieu rong
int mark[MAX_N];

void BFS(Graph *G, int s){
	Queue Q;
	int v;
	makenullQueue(&Q);
	enQueue(&Q,s);
	while(!empty(&Q)){
		int u = front(&Q); deQueue(&Q);
		if(mark[u]!=0) continue;
		printf("%d\n", u);
		mark[u] = 1;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v)){
//				if(mark[v] == 0) 
				enQueue(&Q,v);
			}
		}
	}
}

int main(){
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, e, notdone;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	BFS(&G,1);
	for(e=1;e<=n;e++){
		if(mark[e]!=1){
			notdone = e;
			BFS(&G,notdone);
			break;
		}
	}
	return 0;
}

