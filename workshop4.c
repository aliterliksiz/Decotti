#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int x;
	struct N *next;
}node;

void bastir(node *r){
	while(r != NULL){
		printf("%d\n", r->x);
		r=r->next;
	}
}

void ekle(node *r, int y){
	while(r->next != NULL){
		r=r->next;
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=y;
	r->next->next=NULL;
}

node *ekleSirali(node *r, int z){
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r->x=z;
		return r;
	}
	else{
		if(r->x > z){
			node *temp = (node*)malloc(sizeof(node));
			temp->x=z;
			temp->next=r;
			return temp;
		}
		
		node *iter=r;
		while(iter->next != NULL && iter->next->x < z){
			iter = iter->next;
		}
		
		node *temp = (node*)malloc(sizeof(node));
		temp->next=iter->next;
		iter->next=temp;
		temp->x=z;
		return r;
	}
}

node *sil(node *r, int a){
	node *temp;
	node *iter=r;
	
	if(r->x == a){
		temp=r;
		r=r->next;
		free(temp);
		return r;
	}
	while(iter->next != NULL && iter->next->x != a){
		iter=iter->next;
	}
	
	if(iter->next == NULL){
		printf("sayi bulunamadi \n");
		return r;
	}
	
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}

int main(){
	node *root;
 	root = NULL;
 	
 	root = ekleSirali(root, 400);
 	root = ekleSirali(root, 40);
 	root = ekleSirali(root, 4);
 	root = ekleSirali(root, 450);
 	root = ekleSirali(root, 50);
	bastir(root);
	printf("\n\n\n\n");
	root = sil(root, 50);
	root = sil(root, 40);
	root = sil(root, 450);
	bastir(root);
}
