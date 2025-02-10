#include <stdio.h>

#define MAX_SIZE 100
//Khai bao CTDL Stack
typedef struct{
	int data[MAX_SIZE];
	int top_idx;
}Stack;

void make_null_stack(Stack *S){
	S->top_idx = -1;
}
void push(Stack *S, int u){
	S->top_idx++;
	S->data[S->top_idx] = u;
}

int top(Stack *S){
	return S->data[S->top_idx];
}
void pop(Stack *S){
	S->top_idx--;
}
int empty(Stack *S){
	return S->top_idx==-1;
}

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

void DFS(Graph *G, int s){
	Stack S;
	int v;
	make_null_stack(&S);
	push(&S,s);
	while(!empty(&S)){
		int u = top(&S); pop(&S);
		if(mark[u]!=0) continue;
		printf("%d\n", u);
		mark[u] = 1;
		for(v=1;v<=G->n;v++){
			if(adjacent(G,u,v)) 
				push(&S,v);
		}
	}
}

int main(){
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G,u,v);
	}
	for(i=1;i<=n;i++){
		if(mark[i] != 1){
			DFS(&G,i);
		}
	}
}
