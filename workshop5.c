#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n *next;
}node;

void bastir(node *r){
    node *iter=r;
    printf("\t %d", iter->x);
    iter=iter->next;
	while(iter != r){
		printf("\t %d", iter->x);
		iter=iter->next;
	}
	printf("\t \n");
}

void ekle(node *r, int y){
    node *iter=r;
	while(iter->next != r){
		iter=iter->next;
	}
	iter->next=(node*)malloc(sizeof(node));
	iter->next->x=y;
	iter->next->next=r;
}

node *ekleSirali(node *r, int z){
	if(r==NULL){//Linkedlist boş durumu
		r=(node*)malloc(sizeof(node));
		r->next=r;
		r->x=z;
		return r;
	}	
	else{
		if(r->x > z){//root'tan küçük bir eleman gelmesi durumu
			node *temp=(node*)malloc(sizeof(node));
			temp->x=z;
			temp->next=r;
            node *iter=r;
            while(iter->next != r){
                iter=iter->next;
            }
            iter->next=temp;
			return temp;
		}
		
		node *iter=r;
		while(iter->next != r && iter->next->x < z){//araya bir eleman eklemesi ve sona eleman eklemesi durumu
			iter=iter->next;
		}
		
		node *temp=(node*)malloc(sizeof(node));
		temp->next=iter->next;
		iter->next=temp;
		temp->x=z;
		return r;
	}
}

node *sil(node *r, int a){
	node *temp;
	node *iter=r;
	
	if(r->x==a){//rootun silinmesi durumu
        while(iter->next != r){
            iter = iter->next;
        }
        iter->next=r->next;
		free(r);
		return iter->next;
	}
	
	while(iter->next != r && iter->next->x != a){//diğer elemanların silinmesi durumu
		iter=iter->next;
	}
	
	if(iter->next == r){//listede elemanın bulunmama durumu
		printf("\tsayi bulunamadi\n");
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
	root=sil(root,50);
	bastir(root);
    root=sil(root, 999);
    bastir(root);
	root = sil(root, 4);
    bastir(root);
	root = sil(root, 450);
	bastir(root);
}
