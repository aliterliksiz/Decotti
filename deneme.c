#include <stdio.h>
#include <stdlib.h>
typedef struct n{
	int data;
	struct n *left;
	struct n *right;
}node;
node *insertion(node *tree, int x){
	if(tree == NULL){
		tree = (node*)malloc(sizeof(node));
		tree->data = x;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	else{
		if(tree->data < x){
			tree->right = insertion(tree->right,x);
			return tree;
		}
		else{
			tree->left = insertion(tree->left,x);
			return tree;
		}
	}
}
void preorderTraversal(node *tree){
	if(tree != NULL){
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}
void inorderTraversal(node *tree){
	if(tree != NULL){
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}
void postorderTraversal(node *tree){
	if(tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}
int main(){
	node *tree = NULL;
	printf("The number bein placed in the tree are:\n");
	int i;
	for(i=0; i<10; i++){
		int random = rand()%26;
		printf("%d\t", random);
		tree = insertion(tree, random);
	}
	printf("\nThe preorder traversal:\n");
	preorderTraversal(tree);
	printf("\nThe inorder traversal:\n");
	inorderTraversal(tree);
	printf("\nThe postorder traversal:\n");
	postorderTraversal(tree);
	
}
