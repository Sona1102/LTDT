#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 100
typedef int ElementType;




//=========================Begin BFS======================
/// List
typedef struct {
    int size;
    ElementType data[max];
}List;
void makenull(List *pL){
    pL->size = 0;
}

void push_Back(List *pL, int x){
    pL->data[pL->size] = x;
    pL->size++;
}   

int count_List(List *pL){
    return pL->size;
}

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

//Graph
typedef struct {
    ElementType A[max][max];
    int m,n; 
}Graph;

void init_Graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int i = 0; i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&pG->A[i][j]);
        }
    }
}
void add_Edge(Graph *pG, int u,int v){
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

void print_Graph(Graph *pG){
    int lg = pG->n;
    for(int i = 0; i<lg;i++){
        for(int j = 0; j<lg;j++){
            printf("%d ",pG->A[i][j]);
        }
        printf("/n");
    }
}


void BFS(Graph *pG, ElementType start){
    int n = pG->n;
    bool visited[max] = {false};
    visited[start] = true;
    Queue Q;
    init_Queue(&Q);
    enQueue(&Q,start);
    printf("BFS duyet tu dinh %d ", start);
    while (!isEmpty(&Q))
    {
        int v = deQueue(&Q);
        printf("%d ", v);
        for(int i = 0; i<n;i++){
            if(pG->A[v][i] == 1 && !visited[i]){
                visited[i] = true;
                enQueue(&Q,i);
            }
        }
    }
    printf("End \n");
}

//=========================End BFS======================

//   _____________________________________
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||_____________________________________||

//=========================Begin DFS======================
typedef struct{
    ElementType data[max];
    int top;
}Stack;
void init_Stack(Stack *pS){
    pS->top = -1;
}

bool isStack_Empty(Stack *pS){
    return pS->top == -1;
}
bool isStack_Full(Stack *pS){
    return pS->top = max-1;
}

void push(Stack *pS, ElementType v){
    if(isStack_Full(pS)){
        printf("Stack full");
    }else{
        pS->data[++(pS->top)] = v;
    }
}
ElementType pop(Stack *pS){
    if(isStack_Empty(pS)){
        printf("Stack Empty");
        return -1;
    }else{
        return pS->data[pS->top--];
    }
}
// DFS
void DFS(Graph *pG, ElementType start){
    int n = pG->n;
    bool visited[max] = {false};
    Stack S;
    init_Stack(&S);
    visited[start] = true;
    push(&S, start);
    printf("DFS -> %d: ",start);
    while (!isStack_Empty(&S))
    {
        /* code */
        int v = pop(&S);
        if(visited[v]) continue;
        printf("%d ", v);
        for(int i = 0; i < n; i++){
            if(pG->A[v][i] == 1 && !visited[i]){
                visited[i] = true;
                push(&S,i);
            }
        }
    }
    printf("\n");//Xuong dong di phen
}
//=========================End DFS======================
//   _____________________________________
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||                                     ||
// ||_____________________________________||
//=========================Begin DFS1======================

void DFS1(Graph *pG, ElementType start, bool visited[]){
    int n = pG->n; 
    if(visited[start]){
        return;
    }
    printf("%d ", start);
    visited[start] = true;
    for(int i = 0; i < n; i++){
        if(pG->A[start][i] == 1 && !visited[i]){
            DFS1(pG,i,visited);
        }
    }
    printf("\n");
}

//=========================End DFS1======================

int main(){
    // Begin BFS
	// int m;
    // int n, start;
    // Graph G;
    // printf("Nhap so dinh ");
    // scanf("%d", &n);
    // init_Graph(&G,n);
    // scanf("%d", &start);
    // BFS(&G, start);
    // return 0;
    // scanf("%d",&m);
    //================
    // End BFS

    // Begin DFS
    // int n, start;
    // Graph A;
    // printf("Nhap so dinh cua do thi: ");
    // scanf("%d", &n);
    // init_Graph(&A,n);
    // printf("Nhap dinh bat dau: ");
    // scanf("%d", &start);
    // DFS(&A,start);
    // system("pause");
    // return 0;
    //=================
    //End DFS

    //Begin DFS1
    Graph A;
    int n, start;
    bool visited[max] = {false};
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
    init_Graph(&A,n);
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);
    DFS1(&A,start,visited);
    //=================
    //End DFS1
}
