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
