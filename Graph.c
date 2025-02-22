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
