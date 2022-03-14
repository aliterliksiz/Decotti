#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void create_tree(struct node *tree){
	tree = NULL;
}
struct node *insertElement(struct node *tree, int val){
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL){
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr != NULL){
			parentptr = nodeptr;
			if(val < nodeptr->data){
				nodeptr=nodeptr->left;
			}
			else{
				nodeptr=nodeptr->right;
			}
		}
		if(val < parentptr->data){
			parentptr->left =ptr;
		}
		else{
			parentptr->right=ptr;
		}
	}
	return tree;
}
void preorderTraversal(struct node *tree){
	if(tree != NULL){
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}
void inorderTraversal(struct node *tree){
	if(tree != NULL){
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}
void postorderTraversal(struct node *tree){
	if(tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}
int main(){
	int option, val;
	struct node *ptr;
	create_tree(tree);
	int i;
	for(i=0; i<10; i++){
		val = rand()%26;
		tree = insertElement(tree, val);
	}
	print(tree);
	printf("\n******************************************\n");
	printf("PRE: ");
	preorderTraversal(tree);
	printf("\nIN: ");
	inorderTraversal(tree);
	printf("\nPOST: ");
	postorderTraversal(tree);
}
