#include <stdio.h>
#include <stdlib.h>
#define N 6
int i;
struct Graph{
    struct node* head[N];
};
struct node{
    int dest;
    struct node* next;
};
struct Edge{
    int src, dest;
};
struct Graph* create(struct Edge e[], int n){
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    for (i = 0; i < N; i++) {
        g->head[i] = NULL;
    }
    for (i = 0; i < n; i++){
        int src = e[i].src;
        int dest = e[i].dest;
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->dest = dest;
        newnode->next = g->head[src];
        g->head[src] = newnode;
    }
	return g;
}
void print(struct Graph* g){
	printf("The graph is \n");
    for (i = 0; i < N; i++){
        struct node* ptr = g->head[i];
        while (ptr != NULL){
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
		printf("\n");
    }
}
int main(){
    
	struct Edge e[] ={ {0, 1}, {1, 2}, {1,5}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}, {5,1} };
    int n = sizeof(e)/sizeof(e[0]);
    struct Graph *g = create(e, n);
    print(g);
	return 0;
}
