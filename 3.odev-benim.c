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
void print(node *tree){
	if(tree==NULL){
		//printf("Tree is empty");
		return;
	}
	print(tree->left);
	printf("%d ", tree->data);
	print(tree->right);
}
int main(){
	node *tree = NULL;
	tree = insertion(tree, 16);
	tree = insertion(tree, 7);
	tree = insertion(tree, 14);
	tree = insertion(tree, 24);
	tree = insertion(tree, 8);
	tree = insertion(tree, 5);
	tree = insertion(tree, 11);
	tree = insertion(tree, 23);
	tree = insertion(tree, 9);
	tree = insertion(tree, 12);
	print(tree);
	
	
}
