#include <stdio.h>
#include <stdlib.h>
struct node {
    int data,ele,found,n;       
    struct node *next; 
}*start;
void create();
bool isempty();
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
int main()
{
    int n, data, ele,choice;
    create();
    display();
    printf("*****The operations are*****\n");
    printf("1.Insert at the end\n2.Insert at the beginning\n3.Insert after a node\n4.Insert before a node\n5.Delete at the end\n6.Delete at the beginning\n7.Delete after a node\n8.Delete before a node\n9.Search a node\n10.Display the list\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertend();
            break;
            case 2:
            insertbeg();
            break;
            case 3:
            insertafter();
            break;
            case 4:
            insertbefore();
            break;
            case 5:
            delend();
            break;
            case 6:
            delbeg();
            break;
            case 7:
            delafter();
            break;
            case 8:
            delbefore();
            break;
            case 9:
            search();
            break;
            case 10:
            display();
            break;
            case 11:
            exit(0);
        }
    }while(choice<=11);
    return 0;
}
void create()
{
    struct node *newnode, *tmpnode;
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
bool isempty()
{
    int flag;
    if(start == NULL)
        flag=1;
    if(flag==0)
        return true;
    else
        return false;
}
void insertend()
{
    struct node *newnode, *tmpnode;
    int data;
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    newnode = (struct node*)malloc(sizeof(struct node));
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        newnode->data = data; 
        tmpnode = start;
        while(tmpnode->next != NULL)
            tmpnode = tmpnode->next;
        tmpnode->next = newnode; 
        printf("\nData inserted at the end");
    }
    display();
}
void insertbeg()
{
    struct node *newnode;
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
    }
    printf("\nData inserted at the beginning");
    display();
}
void insertafter()
{
    struct node *tmpnode, *newnode;
    int data, ele;
    printf("\nEnter an already existing element so that you can insert after that node: ");
    scanf("%d",&data);
    printf("Enter a node to insert after a node: ");
    scanf("%d",&ele);
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        while(tmpnode->data != data)
            tmpnode = tmpnode->next;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ele;
        newnode->next = tmpnode->next;
        tmpnode->next = newnode;
        printf("\nData inserted after");
    }
    display();
}
void insertbefore()
{
    struct node *tmpnode, *newnode;
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
        printf("\nData inserted before");
    }
    display();
}
void delend()
{
    struct node *newnode, *tmpnode;
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        tmpnode = start;
        while(tmpnode->next != NULL)
        {
            newnode=tmpnode;
            tmpnode = tmpnode->next;
        }
        if(tmpnode==start)
            start==NULL;
        else
            newnode->next=NULL;
        free(tmpnode);
        printf("\nData deleted at the end");
    }
    display();
}
void delbeg()
{
    struct node *newnode;
    if(start==NULL)
        printf("No memory allocated");
    else
    {
        newnode=start;
        start=start->next;
        free(newnode);
        printf("\nData deleted at the beginning");
    }
    display();
}
void delafter()
{
    struct node *newnode, *tmpnode;
    int ele,data;
    if(start==NULL)
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
        printf("Element deleted after the node");
    }
    display();
}
void delbefore()
{
    struct node *newnode, *tmpnode;
    int ele,data;
    if(start==NULL)
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
        printf("\nData deleted before");
    }
    display();
}
void search()
{
    struct node *tmpnode;
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
    struct node *tmpnode;
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