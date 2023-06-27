#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
float s[10];
int max = 10;
int top = -1;
void push(float s[],float c);
float pop (float s[]);
float postfix(char ex[]);
int main()
{
    float c;
    char ex[10];
    printf("Enter the postfix expression:");
    scanf("%s",ex);
    c = postfix(ex);
    printf("Value of the postfix expression is : %.2f", c);
    printf("\n");
    return 0;
}
float postfix(char ex[])
{
    int i = 0;
    float op1, op2, value;
    while(ex[i] != '\0')
    {
        if(isdigit(ex[i]))
            push(s,(float)ex[i]-'0');
        else
        {
            op2 = pop(s);
            op1 = pop(s);
            switch(ex[i])
            {
                case '+':
                value = op1 + op2;
                break;
                case '-':
                value = op1 - op2;
                break;
                case '*':
                value = op1 * op2;
                break;
                case '/':
                value = op1 / op2;
                break;
                case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(s,value);
        }
        i++;
    }
    return pop(s);
}
void push(float s[],float c)
{
    if(top == max-1)
        printf("Overflow condition\n");
    else
    {
        top++;
        s[top] = c;
    }
}
float pop(float s[])
{
    float c=-1;
    if(top == -1)
        printf("Stack underflow\n");
    else
    {
        c = s[top];
        top--;
    }
    return c;
}