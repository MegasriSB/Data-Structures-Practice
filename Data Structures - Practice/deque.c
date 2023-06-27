#include<stdio.h>
#include<stdlib.h>
int deque[5],max=5,front=-1,rear=-1,choice;
void enqueue_front();
void enqueue_rear();
void dequeue_front();
void dequeue_rear();
void display();
int main()
{
	int choice;
	printf("The deque operations are\n");
	printf("1)Insertion at the front\n2)Insertion at the rear\n3)Deletion at the front\n4)Deletion at the rear\n");
	do
	{
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			printf("Performing Insertion at the front\n");
			enqueue_front();
			break;
			case 2:
			printf("Performing Insertion at the rear\n");
			enqueue_rear();
			break;
			case 3:
			printf("Performing Deletion at the front\n");
			dequeue_front();
			break;
			case 4:
			printf("Performing Deletion at the rear\n");
			dequeue_rear();
			break;
			default:
			printf("Incorrect choice\n");
		}
	}while(choice<5);
}
void enqueue_front()
{
	int ele;
	printf("Enter an element to insert at the front:");
	scanf("%d",&ele);
	if(front==0 && rear==max-1 || front==rear+1)
		printf("Overflow condition");
	if(front == -1)
		front=rear=0;
	else
	{
		if(front==0)
			front=max-1;
		else
			front--;
	}
	deque[front]=ele;
	display();
}
void enqueue_rear()
{
	int ele;
	printf("Enter an element to insert at the rear:");
	scanf("%d",&ele);
	if(front==0 && rear==max-1 || front==rear+1)
		printf("Overflow condition");
	if(front == -1)
		front=rear=0;
	else
	{
		if(rear==max-1)
			rear=0;
		else
			rear++;
	}
	deque[rear]=ele;
	display();
}
void dequeue_front()
{
	if(front==-1)
		printf("Overflow condition");
	if(front == rear)
		front=rear=-1;
	else
	{
		if(front==max-1)
			front=0;
		else
			front++;
	}
	display();
}
void dequeue_rear()
{
	if(front==-1)
		printf("Overflow condition");
	if(front == rear)
		front=rear==-1;
	else
	{
		if(rear==0)
			rear=max-1;
		else
			rear--;
	}
	display();
}
void display()
{
	int i,left=front,right=rear;
    if(left==-1)
        printf("The queue is empty\n");
    if(left<=rear)
    {
    	while(left<=rear)
    	{
    		printf("%d ",deque[left]);
    		left++;
		}
	}
	else
	{
		while(left<=max-1)
		{
			printf("%d ",deque[left]);
			left++;
		}
		left=0;
		while(left<=right)
		{
			printf("%d ",deque[left]);
			left++;
		}
	}
    printf("\n");
}
