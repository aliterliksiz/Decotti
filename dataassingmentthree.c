#include <stdio.h>
#include <stdlib.h>
typedef struct n {
	int data;
	struct n*left;
	struct n*right;
}node;
node *insertion(node *tree, int x){
	if(tree == NULL){
		node *root = (node*)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		root->data=x;
		return root;
	}
	if(tree->data < x){
		tree->right = insertion(tree->right,x);
		return tree;
	}
	tree->left=insertion(tree->left,x);
	return tree;
}
void print(node *tree){
    if(tree == NULL){
        return;
    }
    print(tree->left);
    printf("%d ", tree->data);
    print(tree->right);
}
int main(){
	node *tree = NULL;
	int i;
	for(i=0; i<10; i++){
		tree = insertion(tree, rand()%26);
	}
	print(tree);
}
