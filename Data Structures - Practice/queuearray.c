#include<stdio.h>
int i,front=-1,rear=-1,max=5,queue[5],choice,flag=0;
int isfull();
int isempty();
void enqueue();
void dequeue();
void search();
void display();
int main()
{
    printf("The Queue operations are:\n");
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
int isempty()
{
    if(front==-1 && rear==-1 || front>rear)
        flag=1;
    if(flag==1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(rear==max-1)
        flag=1;
    if(flag==1)
        return 1;
    else
        return 0;
}
void enqueue()
{
    int ele;
    printf("Enter the number to insert:");
    scanf("%d",&ele);
    if(isfull())
        printf("The queue is full\n");
    else if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    queue[rear]=ele;
}
void dequeue()
{
    if(isempty())
        printf("The queue is empty\n");
    else
    {
        printf("%d",queue[front]);
        printf("\n");
        front=front+1;
    }
}
void display()
{
    if(isempty())
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
