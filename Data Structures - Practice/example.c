#include<stdio.h>
#include<stdlib.h>
int i,j,num,n,pos,a[10],ele,found=0;
int isfull()
{
    int n,flag=0;
    if (n==10)
    {
        flag=1;
    }
    if (flag==1)
        return 1;
    else
        return 0;
}
int isempty()
{
    int n,flag=0;
    if(n==0)
    {
        flag=1;
    }   
    if (flag==1)
        return 1;
    else
        return 0;
}
void insertend()
{
    if(isfull())
    {
        printf("The list is full\n");
    }
    else
    {
        printf("We can add elements\n");
        printf("Enter the number to be inserted : ");
        scanf("%d", &num);
        for(j=n-1;j>=i;j--)
        {
            a[j+1] = a[j];
        }
        a[i] = num;
        n++;
        printf("The array after insertion at the end is : ");
        for(i=0;i<n;i++)
        {
            printf("\n a[%d] = %d", i, a[i]);
        }
        printf("\n");
    }
}
void insertbeg()
{
    if(isfull())
    {
        printf("The list is full\n");
    }
    else
    {
        printf("We can add elements\n");
        printf("Enter the number to be inserted : ");
        scanf("%d", &num);
        pos=0;
        while(i>=pos)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[pos] = num;
        n = n+1;
        printf("The array after insertion at the beginning is : ");
        for(i=0;i<n;i++)
        {
            printf("\n a[%d] = %d", i, a[i]);
        }
        printf("\n");
    }
}
void insertpos()
{
    if(isfull())
    {
        printf("The list is full\n");
        
    }
    else
    {
        printf("We can add elements\n");
        printf("Enter the number to be inserted : ");
        scanf("%d", &num);
        printf("Enter the position at which the number has to be added : ");
        scanf("%d", &pos);
        while(i>=pos)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[pos] = num;
        n = n+1;
        printf("The array after insertion of %d is : \n", num);
        for(i=0;i<n;i++)
            printf("a[%d] = %d\n", i, a[i]);
        printf("\n\n");
    }
}
void delend()
{
    if(isempty())
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The list is having some elements\n");
        for(j=i; j<n-1;j++)
        {
            a[j] = a[j+1];
        }
        n = n-1;
        printf("The array after deletion at end is : ");
        for(i=0;i<n;i++)
        {
            printf("\n a[%d] = %d", i, a[i]);
        }
        printf("\n");
    }
}
void delbeg()
{
    if(isempty())
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The list is having some elements\n");
        pos=0;
        for(i=pos; i<n-1;i++)
        {
            a[i] = a[i+1];
        }
        n--;
        printf("The array after deletion is :\n");
        for(i=0;i<n;i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        printf("\n");
    }
}
void delpos()
{
    if(isempty())
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The list is having some elements\n");
        printf("Enter the position from which the number has to be deleted : ");
        scanf("%d", &pos);
        for(i=pos; i<n-1;i++)
        {
            a[i] = a[i+1];
        }
        n--;
        printf("The array after deletion is :\n");
        for(i=0;i<n;i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        printf("\n");
    }
}
void search()
{
    printf("Enter a number to search:");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(ele==a[i])
        {
        found=1;
        printf("Element %d found at %d\n",ele,i);
        break;
        }
    }
    if(found==0)
    {
        printf("element not found in the array");
    }
    printf("\n");
}
void display()
{
    printf("The list is :\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("\n");
}

void main()
{
    int ch;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("1.Insertion at the end\n2.Insertion at the beginning\n3.Insertion at the nth position\n4.Deletion at the end\n5.Deletion at the beginning\n6.Deletion at the nth position\n7.Searching an element\n8.Printing the list\n");
    do
    {
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insertend();
            break;
            case 2:
            insertbeg();
            break;
            case 3:
            insertpos();
            break;
            case 4:
            delend();
            break;
            case 5:
            delbeg();
            break;
            case 6:
            delpos();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
        }
    }while(ch<=9);
    isfull();
    isempty();
}
