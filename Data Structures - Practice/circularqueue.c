#include<stdio.h>
#include<stdlib.h>
int i,front=-1,rear=-1,max=5,queue[5],choice,flag=0;
void enqueue();
void dequeue();
void search();
void display();
int main()
{
    printf("The Circular Queue operations are:\n");
    printf("1.enqueue\n2.dequeue\n3.Search\n4.Display\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Performing enqueue operation\n");
            enqueue();
            break;
            case 2:
            printf("Performing dequeue operation\n");
            dequeue();
            break;
            case 3:
            printf("Displaying the queue\n");
            display();
            break;
            case 4:
            printf("Performing Search operation\n");
            search();
            break;
            default:
            printf("The choice is invalid\n");
        }
    }while (choice<5);
}
void enqueue()
{
	int ele;
	printf("Enter an element to search:");
	scanf("%d",&ele);
	if(front==0 && rear==max-1 || front==rear+1)
		printf("Overflow condition");
	else if(rear==-1 && front==-1)
		front=rear=0;
	else if(front!=0 && rear==max-1)
		rear=0;
	else
		rear++;
	queue[rear]=ele;
	display();
}
void dequeue()
{
	if(front==-1 && rear==-1)
		printf("Overflow condition");
	else if(front==max-1)
		front=0;
	else if(front==rear)
		front=rear-1;
	else
		front++;
	display();
}
void display()
{
    if(front==-1 && rear==-1)
        printf("The queue is empty\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
    printf("\n");
}
void search()
{
    int ele;
    printf("Enter a number to search:");
    scanf("%d",&ele);
    for(i=front;i<=rear;i++)
    {
        if (ele==queue[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Element found\n");
    else
        printf("Element not found\n");
}
