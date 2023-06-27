#include<stdio.h>
#include<stdlib.h>
int ele,srch,del,choice,max;
struct tree{
    struct tree *left;
    int data;
    struct tree *right;    
}*newnode,*root;
void search(struct tree *t, int srch) {
    if(t==NULL)
        printf("Data Not Found.");
    else if(srch < t->data)
        search(t->left,srch);
    else if(srch > t->data)
        search(t->right,srch);
    else
        printf("Data Found.");
}
int minimum(struct tree *t) {
    if(t==NULL)
        printf("Underflow.");
    else if(t->left==NULL)
        return t->data;
    else
        minimum(t->left);
}
int maximum(struct tree *t) {
    if(t==NULL)
        printf("Underflow.");
    else if(t->right==NULL)
        return t->data;
    else
        maximum(t->right);
}
int nodes(struct tree *t) {
    if(t==NULL)
        return 0;
    else
        return nodes(t->left)+nodes(t->right)+1;
}
int height(struct tree *t) {
    int leftH,rightH;
    if(t==NULL)
        return 0;
    else
        leftH=height(t->left);
        rightH=height(t->right);
        if(leftH > rightH)
            return leftH+1;
        else
            return rightH+1;
}
struct tree * insert(struct tree *t, int ele) {
    if(t==NULL) {
        newnode=malloc(sizeof(struct tree));
        newnode->data=ele;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    else if(ele < t->data)
        t->left=insert(t->left,ele);
    else
        t->right=insert(t->right,ele);
    return t;
}
struct tree * delete(struct tree *t, int del) {
    if(t==NULL)
        printf("Underflow.");
    else if(del > t->data) 
        t->right=delete(t->right,del);
    else if(del < t->data) 
        t->left=delete(t->left,del);
    else if(t->left!=NULL && t->right!=NULL) {
        max=maximum(t->left);
        t->data=max;
        t->left=delete(t->left,max);
    }
    else if(t->left==NULL && t->right==NULL)
        t=NULL;
    else if(t->left!=NULL)
        t=t->left;
    else
        t=t->right;
    return t;
}
void inOrder(struct tree *t){
    if(t!=NULL){
        inOrder(t->left);
        printf("%d ",t->data);
        inOrder(t->right);
    }
}
void main() {
	clrscr();
    printf("Implementation of Binary Search Tree\n1.Insertion\n2.Deletion\n3.Searching a data\n4.Minimum in a tree\n5.Maximum in a tree\n6.Height of the tree\n7.NodeCount\n8.Display\n9.Exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            case 2:
                printf("Enter the data to be delete: ");
                scanf("%d",&del);
                root=delete(root,del);
                break;
            case 3:
                printf("Enter the search data: ");
                scanf("%d",&srch);
                search(root,srch);
                break;
            case 4:
                if(root==NULL)
                    minimum(root);
                else
                    printf("Minimum data in a tree: %d",minimum(root));
                break;
            case 5:
                if(root==NULL)
                    maximum(root);
                else
                    printf("Maximum data in a tree: %d",maximum(root));
                break;
            case 6:
                printf("Height of a tree: %d",height(root));
                break;
            case 7:
                printf("Total number of nodes in a tree: %d",nodes(root)); 
                break;
            case 8:
                inOrder(root);
                break;
            case 9: 
                exit(0);
            default:
                printf("Invalid Input...");
       }
    }while(choice!=9);
    getch();
}
