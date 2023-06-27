#include<stdio.h>
#include<stdlib.h>
struct node{
	int data,height;
	struct node *left;
	struct node *right;
};
int max(int a, int b);
int height(struct node *tree){
	if (tree == NULL)
		return 0;
	return tree->height;
}
int max(int a, int b){
	if(a>b)
		return a;
	else 
		return b;
}
struct node* create(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1; 
	return newnode;
}
struct node *rightRotate(struct node *y){
	struct node *x = y->left;
	struct node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
struct node *leftRotate(struct node *x){
	struct node *y = x->right;
	struct node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}
int getBalance(struct node *tree){
	if (tree == NULL)
		return 0;
	return height(tree->left) - height(tree->right);
}
struct node* insert(struct node* newnode, int data){
	if (newnode == NULL)
		return(create(data));
    if (data < newnode->data)
		newnode->left = insert(newnode->left, data);
	else if (data > newnode->data)
		newnode->right = insert(newnode->right, data);
	else 
		return newnode;
	newnode->height = 1 + max(height(newnode->left),height(newnode->right));
	int balance = getBalance(newnode);
	if (balance > 1 && data < newnode->left->data)
		return rightRotate(newnode);
	if (balance < -1 && data > newnode->right->data)
		return leftRotate(newnode);
	if (balance > 1 && data > newnode->left->data){
		newnode->left = leftRotate(newnode->left);
		return rightRotate(newnode);
	}
	if (balance < -1 && data < newnode->right->data){
		newnode->right = rightRotate(newnode->right);
		return leftRotate(newnode);
	}
	return newnode;
}
struct node * min(struct node* newnode){
	struct node* tmp = newnode;
	while (tmp->left != NULL)
		tmp = tmp->left;
    return tmp;
}
struct node* deletenode(struct node* tree, int data){
	if (tree == NULL)
		return tree;
	if ( data < tree->data )
		tree->left = deletenode(tree->left, data);
	else if( data > tree->data )
		tree->right = deletenode(tree->right, data);
	else{
		if( (tree->left == NULL) || (tree->right == NULL) ){
			struct node *temp = tree->left ? tree->left :tree->right;
			if (temp == NULL){
				temp = tree;
				tree = NULL;
			}
			else
			    *tree = *temp; 
			free(temp);
		}
		else{
			struct node* temp = min(tree->right);
			tree->data = temp->data;
			tree->right = deletenode(tree->right, temp->data);
		}
	}
	if (tree == NULL)
	    return tree;
	tree->height = 1 + max(height(tree->left),height(tree->right));
	int balance = getBalance(tree);
	if (balance > 1 && getBalance(tree->left) >= 0)
		return rightRotate(tree);
	if (balance > 1 && getBalance(tree->left) < 0){
		tree->left = leftRotate(tree->left);
		return rightRotate(tree);
	}
	if (balance < -1 && getBalance(tree->right) <= 0)
		return leftRotate(tree);
	if (balance < -1 && getBalance(tree->right) > 0){
		tree->right = rightRotate(tree->right);
		return leftRotate(tree);
	}
    return tree;
}
void preorder(struct node *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
int main(){
    struct node *tree = NULL;
	tree = insert(tree, 42);
	tree = insert(tree, 49);
	tree = insert(tree, 10);
	tree = insert(tree, 74);
	tree = insert(tree, 51);
	tree = insert(tree, 31);
	tree = insert(tree, 11);
	tree = insert(tree, 96);
	tree = insert(tree, 27);
    printf("Preorder traversal of the constructed AVL tree is \n");
	preorder(tree);
    tree = deletenode(tree, 74);
    printf("\nPreorder traversal after deletion of 74 \n");
	preorder(tree);
	printf("\n");
    return 0;
}
