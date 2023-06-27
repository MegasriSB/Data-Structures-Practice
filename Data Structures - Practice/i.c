#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char a[100],b[100],e[100];
int j=-1,k=-1,n,x=0,c[100];
int operation(int a,int b, char c)
{
if(c=='*')
return a*b;
if(c=='+')
return a+b;
if(c=='-')
return a-b;
if(c=='%')
return a%b;
if(c=='/')
return a/b;
return a^b;
}
void pop(char c)
{
if(k<0)
return;
if(c==')')
{
if(b[k]=='(')
{--k;return;}
else
{
a[++j]=b[k--];
pop(c);
}
}
if(c=='+'||c=='-')
{
if(b[k]=='*'||b[k]=='/'||b[k]=='%'||b[k]=='^')
{
a[++j]=b[k--];
pop(c);
}
if(b[k]=='+'||b[k]=='-')
a[++j]=b[k--];
}
else if(c=='*'||c=='/'||c=='%')
{
if(b[k]=='^')
{
a[++j]=b[k--];
pop(c);
}
if(b[k]=='*'||b[k]=='/'||b[k]=='%')
a[++j]=b[k--];
}
}
int main()
{
int i;
printf("enter the expression \n");
scanf("%s",e);
n=sizeof(e);
for(i=0;i<=n;i++)
{
if(isdigit(e[i]))
a[++j]=e[i];
else
{
pop(e[i]);
b[++k]=e[i];
}
}
for(i=k;i>=0;i--)
a[++j]=b[i];
printf("the postfix expression is: \n");
for(i=0;i<=j;i++)
printf("%c",a[i]);
i=0; k=-1;
while(i<=j)
{
if(isdigit(a[i]))
c[++k]=(int)a[i];
else
{
x=operation(c[k-1],c[k],a[i]);
c[--k]=x;
}
++i;
}
printf("%d",x);
}