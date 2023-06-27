#include<stdio.h>
#include<stdlib.h>
int coeff,pow,i,max,ch; 
struct node
{
    int coeff,pow;
    struct node *next;
}*poly1,*poly2,*polyadd,*polymul,*tmpnode,*newnode;
void node1(int coeff, int i)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->pow=i;
    newnode->next=NULL;
}
struct node *create(struct node *p,int max)
{
    for(i=max;i>=0;i--)
    {
        printf("Enter the coefficient of x^%d:",i);
        scanf("%d",&coeff);
        if(p==NULL)
        {
            node1(coeff,i);
            p=newnode;
        }
        else
        {
            node1(coeff,i);
            tmpnode=p;
            while(tmpnode->next!=NULL)
                tmpnode=tmpnode->next;
            tmpnode->next=newnode;
        }
    }
    return p;
}
void addNode()
{
    if(poly1->pow > poly2->pow)
    {
        node1(poly1->coeff,poly1->pow);
        poly1=poly1->next;
    }
    else if(poly1->pow < poly2->pow)
    {
        node1(poly2->coeff,poly2->pow);
        poly2=poly2->next;
    }
    else
    {
        node1(poly1->coeff+poly2->coeff,poly1->pow);
        poly1=poly1->next;
        poly2=poly2->next;
    }
}
void polyAddition()
{
    if(polyadd==NULL)
    {
        addNode();
        polyadd=newnode;
    }
    for(i=0;i<polyadd->pow;i++)
    {
        addNode();
        tmpnode=polyadd;
        while(tmpnode->next!=NULL)
            tmpnode=tmpnode->next;
        tmpnode->next=newnode;
    }
}
void multiplyNode(int coeff, int pow)
{
    if(polymul==NULL)
    {
        node1(coeff,pow);
        polymul=newnode;
    }
    else
    {
        node1(coeff,pow);
        tmpnode=polymul;
        while (tmpnode->next!=NULL)
            tmpnode=tmpnode->next;
        tmpnode->next=newnode;
    }
}
void duplicates(struct node *tmp1, struct node *tmp2)
{
    tmp1=polymul;
    while(tmp1!=NULL && tmp1->next!=NULL)
    {
        tmp2=tmp1;
        while(tmp2->next!=NULL)
        {
            if(tmp1->pow==tmp2->next->pow)
            {
                tmp1->coeff=tmp1->coeff+tmp2->next->coeff;
                tmp2->next=tmp2->next->next;
            }
            else
                tmp2=tmp2->next;
        }
        tmp1=tmp1->next;
    }
}
void polyMul(struct node *tmp1, struct node *tmp2)
{
    while(tmp1!=NULL)
    {
        while(tmp2!=NULL)
        {
            coeff=tmp1->coeff*tmp2->coeff;
            pow=tmp1->pow+tmp2->pow;
            multiplyNode(coeff,pow);
            tmp2=tmp2->next;
        }
        tmp2=poly2;
        tmp1=tmp1->next;
    }
    duplicates(tmp1,tmp2);
}
void print()
{
    while(tmpnode->next!=NULL)
    {
        printf("%dx^%d + ",tmpnode->coeff,tmpnode->pow);
        tmpnode=tmpnode->next;
    }
    printf("%dx^%d",tmpnode->coeff,tmpnode->pow);
}
void main()
{
	clrscr();
    printf("Enter the values for two polynomials:-");
    printf("\nEnter the maximum power of polynomial1:");
    scanf("%d",&max);
    poly1=create(poly1,max);
    printf("\nEnter the maximum power of polynomial2:");
    scanf("%d",&max);
    poly2=create(poly2,max);
    printf("Operations\n1.Addition\n2.Multiplication\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            polyAddition();
            tmpnode=polyadd;
            print();
            break;
        case 2:
            polyMul(poly1,poly2);
            tmpnode=polymul;
            print();
            break;
        default:
            printf("Invalid Input...");
        printf("\n");
        getch();
    }
}
