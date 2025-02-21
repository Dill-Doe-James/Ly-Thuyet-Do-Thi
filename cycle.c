#include <stdio.h>
#define MAX_N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
typedef struct{
	int m,n;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G,int n){
	int u,v;
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			G->A[u][v] = 0;
		}
	}
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v){
	G->A[u][v]++;
	G->A[v][u]++;
	G->m++;
	
}
int adjacent(Graph *G, int u, int v){
	return G->A[u][v]>0;
}
int color[MAX_N];
int has_circle;

void DFS(Graph *G, int u,int p){
	color[u] = GRAY;
	int v;
	for(v=1;v<=G->n;v++){
		if(adjacent(G,u,v)){
			if(v==p) continue;
			if(G->A[u][v]==2) has_circle=1;
			if(color[v] == WHITE)
				DFS(G,v,u);
			else if(color[v] == GRAY)
				has_circle = 1;	
		}
	}
	color[u] = BLACK;
}

int main(){
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	has_circle = 0;
	for(u=1;u<=G.n;u++){
		color[u] == WHITE;		
	}
	for(u=1;u<=G.n;u++){
		if(color[u] == WHITE){
			DFS(&G,u,-1);
		}		
	}	
	if(has_circle==1) printf("YES");
	else printf("NO");
}
