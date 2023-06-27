#include<stdio.h>
void main(){
        int alloc[10][10], max[10][10], avail[10], need[10][10], i, j, k, work[10], n, m, f[10], flag = 0, ind =0, ans[10];
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        printf("Enter the number of resources: ");
        scanf("%d", &m);
        printf("Enter the allocation matrix:\n");
        for(i = 0; i < n; i++)
            for(j= 0;j<m;j++)
                scanf("%d", &alloc[i][j]);
        printf("Enter the max matrix:\n");
        for(i = 0; i < n; i++)
            for(j= 0;j<m;j++)
                scanf("%d", &max[i][j]);
        printf("Enter the available matrix: ");
        for(i = 0; i < m; i++){
            scanf("%d", &avail[i]);
            f[i] = 0;
        }
        for(i = 0; i < n; i++)
            for(j= 0;j<m;j++)
                need[i][j] = max[i][j] - alloc[i][j];
        printf("Allocation matrix\n");
        for(i = 0; i < n; i++){
            for(j= 0;j<m;j++)
                printf("%d ",alloc[i][j]);
                printf("\n");
        }
        printf("Max matrix:\n");
        for(i = 0; i < n; i++){
            for(j= 0;j<m;j++)
                printf("%d ",max[i][j]);
                printf("\n");
        }
        printf("available matrix: ");
        for(i = 0; i < m; i++)
            printf("%d ", avail[i]);
        printf("\n"); 
        printf("Need matrix:\n");
        for(i = 0; i < n; i++){
            for(j= 0;j<m;j++)
                printf("%d ",need[i][j]);
                printf("\n");
        }
        for(i= 0;i<m;i++)
            work[i] = avail[i]; 
        for(i= 0;i<n;i++){
            for(j= 0;j<m;j++){
                if(f[i] == 0){
                    if(need[i][j] <= work[i])
                        flag = 0;
                }
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            printf("The following system is not safe\n");
        else{
            for(i= 0;i<n;i++){
                for(j= 0;j<m;j++){
                    ans[ind++] = i;
                        work[i] = work[i] + alloc[i][j];
                        // ans[i] = work[i];
                        f[i] = 1;
                    }
                }
                printf("The following system is safe\n");
        printf("The safe sequence is \n");
        for(i = 0; i < n-1; i++)
            printf("P%d ->", ans[i]);
        printf("P%d", ans[n-1]);
            }
        // if(flag == 0){
        // printf("The following system is safe\n");
        // printf("The safe sequence is \n");
        // for(i = 0; i < n-1; i++)
        //     printf("P%d ->", ans[i]);
        // printf("P%d", ans[n-1]);
        // }
}

        
        