#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 100
typedef int ElementType;

// Queue - Hàng đợi
typedef struct
{
    /* data */
    ElementType queue[max];
    int front, rear;
}Queue;
void init_Queue(Queue *pQ){
    pQ->front = -1;
	pQ->rear = -1;
}
void enQueue(Queue *pQ, int v){
    if(pQ->rear == max - 1){
        printf("Queue Full!!!");
    }else {
        if(pQ->front == -1) pQ->front = 0;
        pQ->rear++;
        pQ->queue[pQ->rear]=v;
    }
}

int deQueue(Queue *pQ){
    int v;
    if(pQ->front == -1 || pQ->front > pQ->rear){
        printf("Null!!!");
        return -1;
    }else {
        v = pQ->queue[pQ->front];
        pQ->front++;
        return v;
    }
}

bool isEmpty(Queue *pQ){
    return pQ->front == -1 || pQ->front > pQ->rear;
}
//=============================================================
// Grapp
typedef struct {
    ElementType A[max][max];
    int m,n; 
}Graph;
void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int i = 1; i<=n;i++){
        for(int j=0;j<n;j++){
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *pG, int u,int v){
    pG->A[u + 1][v + 1] = 1;
    pG->A[v + 1][u + 1] = 1;
    pG->m++;
}

void print_Graph(Graph *pG){
    int lg = pG->n;
    for(int i = 1; i<=lg;i++){
        for(int j = 1; j<= lg;j++){
            printf("%d ",pG->A[i][j]);
        }
        printf("/n");
    }
}

// ==============================
// ===========BFS================================================================
void BFS(Graph *pG, ElementType start, bool visited[]){
    int n = pG->n;
    visited[start] = true;
    Queue Q;
    init_Queue(&Q);
    enQueue(&Q,start);
    while (!isEmpty(&Q))
    {
        int u = deQueue(&Q);
        printf("%d\n", u);
        for(int i = 1; i<= n;i++){
            if(pG->A[u][i] == 1 && !visited[i]){
                visited[i] = true;
                enQueue(&Q,i);
            }
        }
    }
    

}
//===============End
int main(){
	freopen("dt.txt", "r", stdin);
	Graph G;
	bool visited[max] = {false};
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(int i = 1; i <= n; i++){
	    if(!visited[i]){
	    	BFS(&G,i,visited);
		}    	
	}
	return 0;
}

