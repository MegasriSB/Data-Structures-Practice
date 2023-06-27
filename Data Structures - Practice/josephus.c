#include<stdio.h>
#include<stdlib.h>
struct node
{
	int id;
	struct node *next;
}*start,*tmpnode,*newnode;
void main()
{
	int n,k,i,count;
	clrscr();
	printf("Enter the number of players:");
	scanf("%d",&n);
	printf("Enter the value of k:");
	scanf("%d",&k);
	start=(struct node*)malloc(sizeof(struct node));
	start->id=1;
	tmpnode=start;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		tmpnode->next=newnode;
		newnode->id=i;
		newnode->next=start;
		tmpnode=newnode;
	}
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
			tmpnode=tmpnode->next;
		tmpnode->next=tmpnode->next->next;
	}
	printf("The winner is player %d\n",tmpnode->id);
	getch();
}

