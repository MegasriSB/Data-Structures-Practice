#include <stdio.h>
int main()
{
    int i, n, temp, j, a[10];
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the elements : ");
        scanf("%d",&a[i]);
    }
    printf("The elements in the array are: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    printf("\nThe array sorted in ascending order is :");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}