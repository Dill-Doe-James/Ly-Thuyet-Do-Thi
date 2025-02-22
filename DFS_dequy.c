#include <stdio.h>
//Khai bao CTDL Graph
#define MAX_N 100
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	G->m = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
	G->A[v][u] = 1;
	G->m++;
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v]>0;
}
int mark[MAX_N];

void DFS(Graph *G, int u){
	int v;
	printf("%d\n", u);
	if(mark[u]==1) return;
	mark[u] = 1;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)&& mark[v]==0){
			DFS(G,v);
		}
	}
}
int main(){
//	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(e=1;e<=G.n;e++){
		if(mark[e] == 0)
			DFS(&G,e);
	}
}
