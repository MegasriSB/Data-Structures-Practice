#include <stdio.h>
#include <limits.h>
int heap[100], size;
void Init(){
    size = 0;
    heap[0] = -INT_MAX;
}
void Insert(int ele){
    size++;
    heap[size] = ele;
    int now = size;
    while (heap[now / 2] > ele{
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = ele;
}
int DeleteMin(){
    int min, last, child, now;
    min = heap[1];
    last = heap[size--];
    for (now = 1; now * 2 <= size; now = child){
        child = now * 2;
        if (child != size && heap[child + 1] < heap[child])
            child++;
        if (last > heap[child])
            heap[now] = heap[child];
        else
            break;
    }
    heap[now] = last;
    return min;
}
int main(){
    int n, i, ele;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    Init();
    for (i = 0; i < n; i++){
    	printf("Enter the element: ");
        scanf("%d", &ele);
        Insert(ele);
    }
    printf("Deletion of root element : %d\n ", DeleteMin());
    printf("The elements in the heap are : ");
    for (i = 0; i < n-1; i++)
        printf("%d ", DeleteMin());
}
