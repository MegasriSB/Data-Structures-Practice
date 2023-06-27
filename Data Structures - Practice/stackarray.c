#include<stdio.h>
int i,top=-1,max=5,stack[5],choice;
void push();
void pop();
void peek();
void display();
void main()
{
clrscr();
printf("The stack operations are:\n");
printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
do{
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Performing Push operation\n");
push();
break;
case 2:
printf("Performing Pop operation\n");
pop();
break;
case 3:
printf("Performing Peek operation\n");
peek();
break;
case 4:
printf("Display the stack\n");
display();
break;
default:
printf("The choice is invalid");
}
}while (choice<5);
getch();
}
void push()
{
int ele;
printf("Enter the element:");
scanf("%d",&ele);
if(top==max-1)
printf("Stack overflow");
else
{
top=top+1;
stack[top]=ele;
}
}
void pop()
{
if(top==-1)
printf("Stack underflow");
else
top--;
}
void peek()
{
if(top==-1)
printf("Stack underflow");
else
printf("%d",stack[top]);
printf("\n");
}
void display()
{
if(top==-1)
printf("Stack underflow");
else
{
printf("Elements in the stack are\n");
for(i=top;i>=0;i--)
printf("%d  ",stack[i]);
}
printf("\n");
}
