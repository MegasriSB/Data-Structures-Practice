#include<stdio.h>
#define INFINITY 9999
#define MAX 10
void dijikstra(int G[MAX][MAX], int n, int start);
int main(){
	int G[MAX][MAX], i, j, n, u;
	printf("\nEnter the no. of vertices: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node: ");
	scanf("%d", &u);
	dijikstra(G,n,u);
}
void dijikstra(int G[MAX][MAX], int n, int start){
	int cost[MAX][MAX], distance[MAX], pred[MAX],next;
	int visited[MAX], count, mindistance, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++){
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
		}
	for(i=0;i< n;i++){
		distance[i]=cost[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	distance[start]=0;
	visited[start]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance && !visited[i]){
				mindistance=distance[i];
				next=i;
			}
		visited[next]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[next][i] < distance[i]){
					distance[i]=mindistance+cost[next][i];
					pred[i]=next;
				}
		count++;
	}
	for(i=0;i < n;i++)
		if(i!=start){
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do{
				j=pred[j];
				printf(" <-%d", j);
			}while(j!=start);
		}
}
