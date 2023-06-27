#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,ele,found;
	struct node *next;
}*front,*rear,*newnode,*tmpnode;
void enqueue();
void dequeue();
void display();
void search();
int main()
{
	int choice;
	printf("The circular queue linked list operations are:\n");
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n");
	do
	{
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Performing Enqueue operation\n");
			enqueue();
			break;
			case 2:
			printf("Performing Dequeue operation\n");
			dequeue();
			break;
			case 3:
			printf("Performing Display operation\n");
			display();
			break;
			case 4:
			printf("Performing Search operation\n");
			search();
			break;
			default:
			printf("Incorrect choice\n");
		}
	}while(choice <= 4);
}
void enqueue()
{
	int ele;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert:");
	scanf("%d",&ele);
	newnode->data = ele;
	newnode->next = NULL;
	if(rear==NULL)
	{
		front=rear=newnode;
		rear->next=front;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=front;
	}
	display();
}
void dequeue()
{
	tmpnode=front;
	if(rear==NULL)
		printf("Queue is empty");
	else if(front==rear)
	{
		front=rear=NULL;
		free(tmpnode);
	}
	else
	{
		front=front->next;
		rear->next=front;
		free(tmpnode);
	}
	display();
}
void display()
{
	tmpnode = front;
	if(front == NULL && rear==NULL)
		printf("The queue is empty\n");
	else
	{
		while(tmpnode->next != front)
		{
			printf("%d ",tmpnode->data);
			tmpnode = tmpnode->next;
		}
		printf("%d ",tmpnode->data);
		printf("\n");
	}
}
void search()
{
	int ele,found = 0;
	tmpnode = front;
	printf("Enter the value to search:");
	scanf("%d",&ele);
	while(tmpnode->next != NULL)
	{
		if(tmpnode->data == ele)
		{
			found = 1;
			break;
		}
		tmpnode= tmpnode->next;
	}
	if(tmpnode->data == ele)
		found = 1;
	if(found == 1)
		printf("Element found\n");
	else
		printf("Element not found\n");
}






