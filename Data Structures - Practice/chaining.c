#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
    int data;
    struct node *next;
}*newnode,*temp;
struct node *chain[size];
void insert(int value){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
        chain[key] = newnode;
    else{
        temp = chain[key];
        while(temp->next)
            temp = temp->next;
		temp->next = newnode;
    }
}
void print(){
    int i;
	for(i = 0; i < size; i++){
        temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp){
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
	int i,n,value;
	printf("Enter number of elements : ");
	scanf("%d",&n);
    for(i = 0; i < size; i++)
        chain[i] = NULL;
    for(i=0;i<n;i++){
    	scanf("%d",&value);
    	insert(value);
    }
	print();
	return 0;
}
