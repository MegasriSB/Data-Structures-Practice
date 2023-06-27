#include <stdio.h>
#include <stdlib.h>
struct node {
    int data,ele,found,n;       
    struct node *next; 
}*start,*newnode,*tmpnode;
void create();
int isempty();
void insertend();
void insertbeg();
void insertafter();
void insertbefore();
void delend();
void delbeg();
void delafter();
void delbefore();
void search();
void display();
void main()
{
    int n, data, ele,choice;
    clrscr();
    create();
    display();
    printf("*****The operations are*****\n");
    printf("1.Insertion at the front\n2.Insertion at the end\n3.Insertion before a node\n4.Insertion after a node\n5.Deletion at the front\n6.Deletion at the end\n7.Deletion before a node\n8.Deletion after a node\n9.Search a node\n10.Display the list\n");
    do
    {
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
	    printf("\nPerforming Insertion at the front\n");
	    insertbeg();
	    break;
	    case 2:
	    printf("\nPerforming Insertion at the end\n");
	    insertend();
	    break;
	    case 3:
	    printf("\nPerforming Insertion before a node\n");
	    insertbefore();
	    break;
	    case 4:
	    printf("\nPerforming Insertion after a node\n");
	    insertafter();
	    break;
	    case 5:
	    printf("\nPrforming Deletion at the front\n");
	    delbeg();
	    break;
	    case 6:
	    printf("\nPerforming Deletion at the end\n");
	    delend();
	    break;
	    case 7:
	    printf("\nPerforming Deletion before a node\n");
	    delbefore();
	    break;
	    case 8:
	    printf("\nPerforming Deletion after a node\n");
	    delafter();
	    break;
	    case 9:
	    printf("\nSearching a node\n");
	    search();
	    break;
	    case 10:
	    printf("\nDisplaying the node\n");
	    display();
	    break;
	    case 11:
	    printf("\nProgram finished\n");
	    exit(0);
	}
    }while(choice<=11);
    isempty();
    getch();
}
void create()
{
    int data, i,n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    if(isempty())
        printf("No memory allocated");
    else
    {
        printf("Memory allocated\n");
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        start->data = data; 
        start->next = NULL;
        tmpnode = start;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if(newnode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newnode->data = data; 
                tmpnode = start;
                while(tmpnode->next != NULL)
                    tmpnode = tmpnode->next;
                tmpnode->next = newnode; 
            }
        }
        printf("List created");
    }
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
void insertend()
{
    int data;
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    newnode = (struct node*)malloc(sizeof(struct node));
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        newnode->data = data; 
        while(tmpnode->next != NULL)
            tmpnode = tmpnode->next;
        tmpnode->next = newnode; 
        newnode->next = NULL;
        printf("\nData inserted at the end");
    }
    display();
}
void insertbeg()
{
    int data;
    printf("\nEnter an element to insert at the beginning: ");
    scanf("%d", &data);
    newnode=(struct node*)malloc(sizeof(struct node));
    if(start == NULL)
        printf("No memory allocated");
    else
    {
        newnode->data = data;
        newnode->next = start;
        start = newnode;
        printf("\nData inserted at the beginning");
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
    if(start==NULL)
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
        printf("\nData inserted after the node");
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
    if(start==NULL)
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
        printf("\nData inserted before the node");
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
        while(tmpnode->next->next != NULL)
        {
            tmpnode = tmpnode->next;
	    newnode = tmpnode->next;
	}
	tmpnode->next = NULL;
	free(newnode);
	printf("\nData deleted at the end");
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
	start=tmpnode->next;
	free(tmpnode);
	printf("\nData deleted at the beginning");
    }
    display();
}
void delafter()
{
    int data,ele;
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
    int data,ele;
    if(isempty())
	printf("No memory allocated");
    else
    {
	printf("\nEnter the element after which the node has to be deleted:");
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
    int found,data;
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        printf("\nEnter the element to search:");
        scanf("%d",&data);
        tmpnode=start;
        while(tmpnode!=NULL)
        {
            if(tmpnode->data==data)
                found=1;
            tmpnode=tmpnode->next;
        }
        if(found==1)
            printf("Element found\n");
        else
            printf("Element not found\n");
    }
}
void display()
{
    printf("\nData in the list \n");
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        while(tmpnode != NULL)
        {
            printf("%d ", tmpnode->data); 
            tmpnode = tmpnode->next;                 
        }
    }
    printf("\n");
}

