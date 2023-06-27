#include<stdio.h>
void sort(int a[],int n){
    int i,min,j,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(a[min]>a[j])
                min=j;
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("\nThe sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    int i,j,n,a[10],search,start,stop,mid,min,temp;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number:");
        scanf("%d",&a[i]);
    }
    printf("The numbers in the array are:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    sort(a,n);
    printf("\nEnter a number to search:");
    scanf("%d",&search);
    start=0;
    stop=n-1;
    while(start<=stop){
        mid=(start+stop)/2;
        if(search==a[mid]){
            printf("Element %d found at %d\n",search,mid);
            break;
        }
        else if(search<a[mid])
            stop=mid-1;
        else
            start=mid+1;
    }
    if(start>stop)
        printf("Element not found in the array\n");
}
