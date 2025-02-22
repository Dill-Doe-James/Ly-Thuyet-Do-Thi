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
