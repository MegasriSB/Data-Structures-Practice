#include <stdio.h>
int n, m, i, j;
void create(int adj[][n+1],int a[][2]){
	for(i=0;i<=n;i++) 
        for(j=0;j<=n;j++) 
			adj[i][j]=0;	
	for(i=0;i<m;i++){
		int x=a[i][0];
		int y=a[i][1];
		adj[x][y]=1;
		adj[y][x]=1;
	}
}
void display(int adj[][n+1]){
	printf("The Adjacency matrix is :\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) 
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}
int main(){
	n = 5;
	int a[][2]= {{1,3},{1,2},{3,2},{4,1},{2,4}};
	m = sizeof(a)/sizeof(a[0]);
	int adj[n+1][n+1];
	create(adj,a);
	display(adj);
}
