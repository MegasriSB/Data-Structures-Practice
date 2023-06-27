#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start, *newnode;
int main()
{
    int ele;
    printf("Enter an element to insert:");
    scanf("%d",&ele);
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("No memory allocated");
    else
    {
        newnode->data = ele;
        newnode->next = NULL;
        start = newnode;
    }
    printf("The inserted element is %d\n",start->data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=20;
    newnode->next=NULL;
    start->next=newnode;
    printf("Newnode %d\n",newnode->data);
}