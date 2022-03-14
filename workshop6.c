#include <stdio.h>
#include <stdlib.h>
typedef struct N{
    int data;
    struct N* next;
    struct N* prev;
}node;
void bastir(node *r){
    while(r->next != NULL){
        printf("%d ", r->data);
        r=r->next;
    }
}
node *ekleSirali(node *r, int x){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->data=x;
        r->next=NULL;
        r->prev=NULL;
        return r;
    }
    else{
        if(r->data > x){
            node *temp=(node*)malloc(sizeof(node));
            r->prev=temp;
            temp->next=r;
            temp->prev=NULL;
            temp->data=x;
            return temp;
        }
        else{
            node *iter=r;
            while(iter->next != NULL && iter->next->data < x){
                iter=iter->next;
            }
            node *temp=(node*)malloc(sizeof(node));
            temp->next=iter->next;
            iter->next=temp;
            temp->prev=iter;
            if(temp->next != NULL){
                temp->next->prev=temp;
            }
            temp->data=x;
            return r;
        }
    }
}
node *sil(node *r, int x){
    node *temp;
    node *iter=r;
    if(r->data==x){
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    else{
        if(iter->next == NULL){
		    printf("sayi bulunamadi \n");
		    return r;
	    }
        else{
            while(iter->next != NULL && iter->next->data != x){
                iter=iter->next;
            }
            temp=iter->next;
            iter->next=iter->next->next;
            free(temp);
            if(temp->next != NULL){
                temp->next->prev=temp;
            }
            iter->next->prev=iter;
            return r;
        }
        
    }
}