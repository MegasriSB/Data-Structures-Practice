#include <stdio.h>

int main(){
  int mat[20][20];
  int i,j,max,x,y,right,down,diag;
  max=0;
  for (i=0;i<20;i++)
    for (j=0;j<20;j++){
      scanf("%d",&x);
      mat[i][j]=x;
      }

  for (i=0;i<20;i++)
    for (j=0;j<17;j++){
    right = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];
    if (right>max)
      max=right;  
    }

  for (i=0;i<17;i++)
    for (j=0;j<20;j++){
    down = mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j];
    if (down>max)
      max=down;
    }

  for (i=0;i<17;i++)
    for (j=0;j<17;j++){
    diag = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3];
    if (diag>max)
      max=diag;
    }

  for (i=0;i<17;i++)
    for (j=3;j<20;j++){
    diag = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
    if (diag>max)
      max=diag;
    }

  printf("%d",max);

  return 0;
}
