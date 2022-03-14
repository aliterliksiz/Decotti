#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct N{
    int data;
    struct N *next;
}node;
void bastir(node *r){
    while(r!=NULL){
        printf("%d\n", r->data);
        r=r->next;
    }
}
void ekle(node *r, int x){
    while(r->next != NULL){
        r=r->next;
    }
    r->next=(node*)malloc(sizeof(node));
    r->next->data=x;
    r->next->next=NULL;
}
bool bul(node *r, int x){
    node *iter=r;
    int i=0;
    while(iter->next != NULL){
        if(iter->data==x){
            i++;
            printf("%d. aramada sayi bulundu: %d", i, x);
            return true;
        }
        iter=iter->next; 
    }
    return false;
}

int main(){
    node *root=(node*)malloc(sizeof(node));
    root->data=10;
    root->next=NULL;
    ekle(root, 20);
    ekle(root, 5);
    ekle(root, 15);
    ekle(root, 40);
    ekle(root, 30);
    bul(root, 15);
    bul(root, 44);
}
