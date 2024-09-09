#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 100
typedef int ElementType;

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

typedef struct {
    ElementType A[max][max];
    int m,n; 
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int i = 0; i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&pG->A[i][j]);
        }
    }
}
void add_edge(Graph *pG, int u,int v){
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

void print_graph(Graph *pG){
    int lg = pG->n;
    for(int i = 0; i<lg;i++){
        for(int j = 0; j<lg;j++){
            printf("%d ",pG->A[i][j]);
        }
        printf("/n");
    }
}


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

int main(){
	//freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}

}
