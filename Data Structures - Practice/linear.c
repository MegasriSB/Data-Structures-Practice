#include<stdio.h>
int main(){
    int i,n,a[10],ele,found=0;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter an element : ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter an element to search:");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(ele==a[i]){
            found=1;
            printf("Element %d found at %d\n",ele,i);
            break;
        }
    }
    if(found==0)
        printf("element not found in the array");
}
