#include <stdio.h>
#include <stdlib.h>
typedef struct n{
	int data;
	struct n *next;
}node;
node *root = NULL;
node *son = NULL;
void bastir(node *root){
	while(root != NULL){
		printf("%d\n", root->data);
		root=root->next;
	}
}
void enqueue(int x){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
		son = root;
	}
	else{
		son->next = (node*)malloc(sizeof(node));
		son->next->data =x;
		son=son->next;
		son->next=NULL;
	}
}
int dequeue(){
	if(root==NULL){
		printf("linkedlist bos");
		return -1;
	}
	int rvalue = root->data;
	node *temp=root;
	root=root->next;
	free(temp);
	return rvalue;
}
int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	bastir(root);
	printf("enqueue bitti\n");
	dequeue();
	dequeue();
	dequeue();
	bastir(root);
}
