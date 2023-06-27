#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
}*tree,*temp,*ptr;
struct node *insert(struct node *, int);
struct node *minimum(struct node *);
struct node *maximum(struct node *);
struct node *deleteElement(struct node *, int);
int totalNodes(struct node *tree);
int Height(struct node *tree);
struct node *search(struct node *tree, int val);
void preorder(struct node *tree);
void main(){
    int op, val;
    struct node *ptr;
    clrscr();
    printf("******Binary Search Tree******* \n");
    printf("\n 1. Insertion\n 2. Find the smallest element\n 3. Find the largest element\n 4. Deletion\n 5. Count the total number of nodes\n 6. Determine the height of the tree\n 7. Display the tree\n 8.Search \n 9. Exit");
    do{
        printf("\nEnter your option : ");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("Enter the value of the new node : ");
            scanf("%d", &val);
            tree = insert(tree, val);
            break;
            case 2:
            ptr = minimum(tree);
            printf("Smallest element is :%d",ptr->data);
            break;
            case 3:
            ptr = maximum(tree);
            printf("Largest element is : %d", ptr->data);
            break;
            case 4:
            printf("Enter the element to be deleted : ");
            scanf("%d", &val);
            tree = deleteElement(tree, val);
            break;
            case 5:
            printf("Total no. of nodes = %d", totalNodes(tree));
            break;
            case 6:
            printf("The height of the tree = %d",Height(tree));
            break;
            case 7:
            printf("The Tree is \n");
            preorder(tree);
            break;
            case 8: 
            printf("Enter the value to be searched:");
            scanf("%d",&val);
            tree = search(tree,val);
            if(search(tree,val))
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        }
    }while(op<=8);
    getch();
}
struct node *insert(struct node *tree, int val){
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
    if (tree == NULL){
    	tree = ptr;
    	tree->left = NULL;
    	tree->right = NULL;
	}
    if (val < tree->data)
        tree->left = insert(tree->left, val);
    else if (val > tree->data)
        tree->right = insert(tree->right, val);
    return tree;
}
struct node *minimum(struct node *tree){
    if((tree == NULL) || (tree->left == NULL))
        return tree;
    else
        return minimum(tree ->left);
}
struct node *maximum(struct node *tree){
    if((tree == NULL) || (tree->right == NULL))
        return tree;
    else
        return maximum(tree->right);
}
struct node *deleteElement(struct node *tree, int val){
    if (tree == NULL)
        return tree;
    if (val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        if (tree->left == NULL) {
            temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {
            temp = tree->left;
            free(tree);
            return temp;
        }
        temp = minimum(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}
int totalNodes(struct node *tree){
    if(tree==NULL)
    	return 0;
    else
    	return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int Height(struct node *tree){
    int leftheight, rightheight;
    if(tree==NULL)
        return 0;
    else{
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
struct node *search(struct node *tree, int val){
    if (tree==NULL || tree->data == val)
        return tree;
    if(tree->data < val)
        return search(tree->right, val);
    return search(tree->left, val);
}
void preorder(struct node *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
