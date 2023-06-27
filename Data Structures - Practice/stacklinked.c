#include<stdio.h>
#include<stdlib.h>
struct node
{
int data,ele;
struct node *next;
}*top=NULL,*newnode,*ptr;
void push();
void pop();
void search();
void display();
int main()
{
int choice;
printf("The stack operations are:\n");
printf("1.Push\n2.Pop\n3.Display\n4.Search\n");
do
{
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
search();
break;
default:
printf("The choice is invalid\n");
}
}while (choice<=4);
}
void push()
{
int ele;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the element:");
scanf("%d",&ele);
if(newnode==NULL)
printf("No memory allocated\n");
else
{
newnode->data=ele;
if(top==NULL)
{
newnode->next=NULL;
top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}
printf("Elements in the stack are after push:\n");
display();
}
void pop()
{
if(top==NULL)
printf("Underflow");
else
{
ptr=top;
top=top->next;
free(ptr);
}
printf("Elements in the stack after pop:\n");
display();
}
void search()
{
int ele,found=0;
printf("\nEnter the element to search:");
scanf("%d",&ele);
ptr=top;
while(ptr->next!=NULL)
{
if(ptr->data==ele)
{
found=1;
break;
}
ptr=ptr->next;
}
if(ptr->data==ele)
{
found=1;
}
if(found==1)
printf("Element found\n");
else
printf("Element not found\n");
}
void display()
{
ptr = top;
while(ptr != NULL)
{
printf("%d ", ptr->data);
ptr = ptr->next;
}
printf("\n");
}
