#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
	int Height;
};
struct node *root=NULL, *temp, *b;
struct node *insert(struct node *root, int x);
int height(struct node *temp);
struct node *singlerotate_left(struct node *root);
struct node *singlerotate_right(struct node *root);
struct node *doublerotate_left(struct node *root);
struct node *doublerotate_right(struct node *root);
int maxi(int h1, int h2);
void inorder(struct node *root);
void main(){
	int x, i, n;
	clrscr();
	printf("enter the number of elements in the tree:");
	scanf("%d",&n);
	printf("enter the element:");
	scanf("%d",&x);
	root=insert(root, x);
	for(i=1;i<n;i++){
		printf("enter the element:");
		scanf("%d",&x);
		insert(root, x);
	}
	inorder(root);
}
struct node *insert(struct node *root, int x){
	if(root==NULL){
		root=(struct node *)malloc(sizeof(struct node));
		if(root==NULL){
			printf("no memory allocated....");
		}
		else{
			root->data=x;
			root->left=NULL;
			root->right=NULL;
			root->Height=0;
		}
	}
	else if(x < root->data){
		root->left=insert(root->left, x);
		if((height(root->left)-height(root->right))==(2 || -2)){
			if(x < root->left->data){
				root=singlerotate_left(root);
			}
			else{
				root=doublerotate_left(root);
			}
		}
	}
	else if(x > root->data){
		root->right=insert(root->right, x);
		if((height(root->left)-height(root->right))==(2 || -2)){
			if(x > root->right->data){
				root=singlerotate_right(root);
			}
			else{
				root=doublerotate_right(root);
			}
		}
	}
	root->Height=max(height(root->left), height(root->right));
	return root;
}
int height(struct node *temp){
	if(temp==NULL){
		return -1;
	}
	else{
		return temp->Height;
	}
}
struct node *singlerotate_left(struct node *root){
	b=root->left;
	root->left=b->right;
	b->right=root;
	root->Height=max(height(root->left), height(root->right))+1;
	b->Height=max(height(b->left), height(b->right)+1);
	return root;
}
struct node *singlerotate_right(struct node *root){
	b=root->right;
	root->right=b->left;
	b->left=root;
	root->Height=max(height(root->left), height(root->right)+1);
	b->Height=max(height(b->left), height(b->right)+1);
	return root;
}
struct node *doublerotate_left(struct node *root){
	root->left=singlerotate_right(root->left);
	return singlerotate_left(root);
}
struct node *doublerotate_right(struct node *root){
	root->right=singlerotate_left(root->right);
	return singlerotate_right(root);
}
int maxi(int h1, int h2){
	return (h1>h2)?h1:h2;
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
