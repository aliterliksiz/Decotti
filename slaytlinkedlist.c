#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}node;

void bastir(node *r){
    while(r != NULL){
        printf("%d ", r->data);
        r = r->next;
    }
}

void ekle(node *r, int x){
    while(r->next != NULL){
        r=r->next;
    }
    r->next=(node*)malloc(sizeof(node));
    r->next->data = x;
    r->next->next=NULL;
}

node *ekleSirali(node *r, int x){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->data = x;
        r->next = NULL;
        return r;
    }

    else{
        if(r->data > x){
            node *temp = (node*)malloc(sizeof(node));
            temp->next=r;
            temp->data=x;
            return temp;
        }

        else{
            node *iter=r;
            while(iter->next != NULL && iter->next->data < x){
                iter=iter->next;
            }
            node *temp = (node*)malloc(sizeof(node));
            temp->next=iter->next;
            iter->next=temp;
            temp->data=x;
            return r;
        }
    }
}

node *sil(node *r, int i){
    node *temp;
    node *iter=r;
    int j;
    for(j=0; j<i-2; j++){
        iter=iter->next;
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
    root = ekleSirali(root, 50);
    root = ekleSirali(root, 450);
    root = ekleSirali(root, 45);
    root = ekleSirali(root, 4500);
    root = ekleSirali(root, 455);
    root = ekleSirali(root, 405);
    root = ekleSirali(root, 505);

    bastir(root);

    printf("\n\n\n");

    root=sil(root, 5);

    bastir(root);
}
