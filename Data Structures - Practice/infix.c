#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int max = 10, top = -1;
char s[10];
void push(char s[],char);
char pop (char s[]);
void infixtopostfix(char source[],char target[]);
int getpriority(char);
int main()
{
    char in[100],post[100];
    printf("Enter the infix expression:");
    scanf("%s",in);
    strcpy(post,"");
    infixtopostfix(in,post);
    printf("The postfix expression is : %s", post);
    printf("\n");
    return 0;
}
void infixtopostfix(char source[],char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target,"");
    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(s,source[i]);
            i++;
        }
        else if(source[i] == '(')
        {
            while((top != -1) && (s[top] != '('))
            {
                target[j] = pop(s);
                j++;
            }
            if(top == -1)
            {
                printf("Incorrect expression\n");
                exit(1);
            }
            temp = pop(s);
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' ||source[i] == '%')
        {
            while((top != -1) && (s[top] != '(') && (getpriority(s[top]) > getpriority(source[i])))
            {
                target[j] = pop(s);
                j++;
            }
            push(s, source[i]);
            i++;
        }
        else
        {
            printf("Incorrect element in the expression\n");
            exit(1);
        }
    }
    while((top != -1) && (s[top] != '('))
    {
        target[j] = pop(s);
        j++;
    }
    target[j] = '\0';
}
int getpriority(char op)
{
    if(op == '/' || op == '*' || op == '%')
        return 1;
    else if(op == '+' || op == '-')
        return 0;
}
void push(char s[],char c)
{
    if(top == max-1)
        printf("Overflow condition\n");
    else
    {
        top++;
        s[top] = c;
    }
}
char pop(char s[])
{
    char c=' ';
    if(top == -1)
        printf("Stack underflow\n");
    else
    {
        c = s[top];
        top--;
    }
    return c;
}