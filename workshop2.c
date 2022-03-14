#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int x;
	struct N * next;
}node;

void bastir(node * r){
	while(r!=NULL){
		printf("%d\n", r->x);
		r=r->next;
	}
}

void ekle(node *r, int y){
	while(r->next != NULL){
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x=y;
	r->next ->next = NULL;
}

int main(){
	node * root;
	root = (node*)malloc(sizeof(node));
	root -> next = NULL;
	root -> x = 500;	
	int j=0;
	for(j=0; j<5; j++){
		ekle(root, j*10);
	}
	bastir(root);
}
