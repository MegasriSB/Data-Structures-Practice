#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
char infix[MAX], postfix[MAX];
int s[MAX],top;
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(int op)
{
	if(top>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	s[++top]=op;
}
int pop()
{
	if(isempty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (s[top--]);
}
int getpriority(char op)
{
	switch(op)
	{
		case '(': 
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		default : 
			return 0;
	}
}
int whitespace(char op)
{
	if( op == ' ' || op == '\t' )
		return 1;
	else
		return 0;
}
void infixtopostfix()
{
	int i,p=0;
	char next,op;
	for(i=0;i<strlen(infix);i++)
	{
		op=infix[i];
		if(!whitespace(op))
		{
			switch(op)
			{
				case '(': 
				push(op);
				break;
				case ')':
				while((next=pop())!='(')
					postfix[p++] = next;
				break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				while( !isempty() && getpriority(s[top])>= getpriority(op) )
					postfix[p++]=pop();
				push(op);
				break;
				default: 
				postfix[p++]=op;
			}
		}
	}
	while(!isempty())
		postfix[p++]=pop();
	postfix[p]='\0';
}
int post()
{
	int a,b,tmp,res,i;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push(postfix[i]-'0');
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+': 
				tmp=b+a; 
				break;
				case '-': 
				tmp=b-a;
				break;
				case '*': 
				tmp=b*a;
				break;
				case '/': 
				tmp=b/a;
				break;
				case '%': 
				tmp=b%a;
				break;
			}
			push(tmp);
		}
	}
	res=pop();
	return res;
}
void main()
{
	int val;
	clrscr();
	top=-1;
	printf("Enter Infix Expression: ");
	scanf("%s",infix);
	infixtopostfix();
	printf("Postfix Expression: %s\n",postfix);
	val=post();
	printf("Value of expression : %d\n",val);
	getch();
}
