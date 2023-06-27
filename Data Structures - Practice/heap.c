#include<stdio.h>
int n, size=-1, heap[100];
void ins(int x);
void del();
void print(int n);
void main(){
	int ele,i;
	clrscr();
	printf("enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter element:");
		scanf("%d",&ele);
		ins(ele);
	}
	print(n);
	printf("\nAfter deletion\n");
	del();
	print(n);
	getch();
	
}
void ins(int x) {
    int a,temp, parent;
    size=size+1;
    heap[size] = x; 
    temp = size;
    while (temp>0) {
        parent=temp/2;
		if(heap[parent] < heap[temp]){
			a=heap[temp];
		    heap[temp] = heap[parent];
		    heap[parent]=a;
		}
        temp=parent;
    }
}
void del()
{
    int last, ptr = 0, left = 1, right = 2, temp;
    last = n-1;
    n = n-1;
    heap[ptr] = heap[last];
    while(left<n && right<n)
    {	
        if(heap[ptr]<heap[left] && heap[ptr]<heap[right]){
        	if(heap[right] <= heap[left]){
                temp = heap[ptr];
                heap[ptr] = heap[left];
                heap[left] = temp;
                ptr = left;
            }
            else
            {
                temp = heap[ptr];
                heap[ptr] = heap[right];
                heap[right] = temp;
                ptr = right;
            }
		}
		else if(heap[ptr]<heap[left]){
			temp = heap[ptr];
            heap[ptr] = heap[left];
            heap[left] = temp;
            ptr = left;
		}
		else if(heap[ptr]<heap[right]){
			temp = heap[ptr];
            heap[ptr] = heap[right];
            heap[right] = temp;
            ptr = right;
		}
		else{
			break;
		}
        left = 2*ptr+1;
        right = left+1;
    }
}
void print(int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",heap[i]);
	}
}
