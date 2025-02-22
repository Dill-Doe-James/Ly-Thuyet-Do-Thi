#include <stdio.h>
//Khai bao CTDL Graph
#define MAX_N 100
typedef struct{
	int n,m; //n: dinh, m: cung
	int A[MAX_N][MAX_N];
}Graph;

typedef struct{
	int u,p;
}ElementType;

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
int mark[MAX_N];
void DFS(Graph *G, int u){
	int v;
//	printf("%d\n", u);
	if(mark[u]==1) return;
	mark[u] = 1;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)&& mark[v]==0){
			DFS(G,v);
		}
	}
}
int connected(Graph *G){
	int u;
	for(u=1;u<=G->n;u++){
		mark[u] = 0;
	}
	DFS(G,1);
	for(u=1;u<=G->n;u++){
		if(mark[u]==0) return 0;
	}
	return 1;
}
int main(){
//	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	if(connected(&G)) printf("DUOC");
	else printf("KHONG");
}
