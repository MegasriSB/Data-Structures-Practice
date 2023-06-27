#include<stdio.h>
#include<stdlib.h>
int ele;
struct node{
    struct node *left;
    int data;
    struct node *right;
}*newnode;
void preorder(struct node *tree){
    if(tree == NULL)
        return;
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}
void inorder(struct node *tree){
    if(tree == NULL)
        return;
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
}
void postorder(struct node *tree){
    if(tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->data);
}
struct node *create(ele){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insertleft(struct node *tree, int ele){
    tree->left = create(ele);
    return tree->left;
}
struct node *insertright(struct node *tree, int ele){
    tree->right = create(ele);
    return tree->right;
}
void main(){
    int ele;
    struct node* tree = create(5);
    clrscr();
    insertleft(tree,14);
    insertright(tree,17);
    insertleft(tree->left,19);
    insertright(tree->right,23);
    printf("Preorder traversal:\n");
    preorder(tree);
    printf("\nInorder traversal:\n");
    inorder(tree);
    printf("\nPostorder traversal:\n");
    postorder(tree);
    getch();
}
