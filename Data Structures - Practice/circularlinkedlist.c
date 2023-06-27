#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,ele,found,n;
	struct node *next;
}*start,*newnode,*tmpnode;
void create();
int isempty();
void display();
void insertbeg();
void insertend();
void insertafter();
void insertbefore();
void delbeg();
void delend();
void delafter();
void delbefore();
void search();
void display();
int main()
{
    printf("Circular linked list");
	create();
	insertbeg();
    insertend();
    insertafter();
    insertbefore();
    delbeg();
    delend();
    delafter();
    delbefore();
    search();
    display();
    isempty();
}
void create()
{
	int data,i,n;
    printf("Enter the number of elements:");
	scanf("%d",&n);
	newnode=(struct node *)malloc((sizeof(struct node)));
	if(newnode==NULL)
		printf("No memory allocated");
	else
	{
		printf("Enter the element:");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=start;
		start=newnode;
	}
	tmpnode=start;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc((sizeof(struct node)));
	    if(newnode==NULL)
		    printf("No memory allocated");
	    else
	    {
		    printf("Enter the element:");
		    scanf("%d",&data);
		    newnode->data=data;
		    tmpnode->next=newnode;
		    newnode->next=start;
		    tmpnode=newnode;
	   }
	}
}
void display()
{
	int data;
	if(start==NULL)
	{
		printf("list is empty");
	}
	else
	{
		printf("%d ",start->data);
	    tmpnode=start->next;
	    while(tmpnode!=start)
	    {
		    printf("%d ",tmpnode->data);
		    tmpnode=tmpnode->next;
	    }
	}
    printf("\n");
}
int isempty()
{
    int flag;
    if(start == NULL)
        flag=1;
    if(flag==0)
        return 1;
    else
        return 0;
}
void insertbeg()
{
	int data;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("no memory allocated");
	}
	else
	{
		printf("enter the element to be inserted:");
		scanf("%d",&data);
		newnode->data=data;
		tmpnode=start;
		while(tmpnode->next!=start)
			tmpnode=tmpnode->next;
		tmpnode->next=newnode;
		newnode->next=start;
		start=newnode;
        printf("Data inserted at the beginning\n");
	}
    display();
}
void insertend()
{
    int data;
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        newnode->data = data; 
        while(tmpnode->next != start)
            tmpnode = tmpnode->next;
        tmpnode->next = newnode; 
        newnode->next = start;
        printf("Data inserted at the end\n");
    }
    display();
}
void insertafter()
{
    int data, ele;
    printf("\nEnter an already existing element so that you can insert after that node: ");
    scanf("%d",&data);
    printf("Enter a node to insert after a node: ");
    scanf("%d",&ele);
    if(newnode==NULL)
        printf("No memory allocated");
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ele;
        tmpnode = start;
        while(tmpnode->data != data)
            tmpnode = tmpnode->next;
        newnode->next = tmpnode->next;
        tmpnode->next = newnode;
        printf("Data inserted after the node\n");
    }
    display();
}
void insertbefore()
{
    int data,ele;
    printf("\nEnter an already existing element so that you can insert before that node: ");
    scanf("%d",&data);
    printf("Enter a node to insert before a node: ");
    scanf("%d",&ele);
    if(newnode==NULL)
        printf("No memory allocated");
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data=ele;
        tmpnode = start;
        if(tmpnode->data!=data)
        {
            while(tmpnode->next->data != data)
                tmpnode = tmpnode->next;
            newnode->next = tmpnode->next;
            tmpnode->next = newnode;
        }
        printf("Data inserted before the node\n");
    }
    display();
}
void delbeg()
{
    if(isempty())
        printf("No memory allocated");
    else
    {
        tmpnode=start;
        newnode=tmpnode;
        while(tmpnode->next != start)
            tmpnode = tmpnode->next;
        start=newnode->next;
        tmpnode->next=start;
        free(newnode);
        printf("Data deleted at the beginning\n");
    }
    display();
}
void delend()
{
    if(isempty())
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        newnode=tmpnode;
        while(tmpnode->next->next != start)
        {
            tmpnode = tmpnode->next;
            newnode=tmpnode->next;
        }
        tmpnode->next = start;
        free(newnode);
        printf("Data deleted at the end\n");
    }
    display();
}
void delafter()
{
    int ele,data;
    if(isempty())
        printf("No memory allocated");
    else
    {
        printf("Enter the element after which the node has to be deleted:");
        scanf("%d",&ele);
        tmpnode=start;
        while(newnode->data!=ele)
        {
            newnode=tmpnode;
            tmpnode=tmpnode->next;
        }
        newnode->next=tmpnode->next;
        free(tmpnode);
        printf("Data deleted after the node");
    }
    display();
}
void delbefore()
{
    int ele,data;
    if(isempty())
        printf("No memory allocated");
    else
    {
        printf("\nEnter the element before which the node has to be deleted:");
        scanf("%d",&ele);
        tmpnode = start;
        if(tmpnode->data!=ele)
        {
            while(tmpnode->next->data != ele)
            {
                newnode = tmpnode;
                tmpnode = tmpnode->next;
            }
            newnode->next = tmpnode->next;
            free(tmpnode);
        }
        printf("\nData deleted before the node");
    }
    display();
}
void search()
{
    int found=0,data;
    if(newnode==NULL)
        printf("No memory allocated");
    else
    {
        printf("\nEnter the element to search:");
        scanf("%d",&data);
        tmpnode=start;
        while(tmpnode->next != start)
        {
            if(tmpnode->data==data)
            {
                found=1;
                break;
            }
            tmpnode=tmpnode->next;
        }
        if(tmpnode->data==data)
            found = 1;
        if(found==1)
            printf("Element found\n");
        else
            printf("Element not found\n");
    }
}