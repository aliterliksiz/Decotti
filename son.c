#include <stdio.h>
#include <stdlib.h>
typedef struct N{
    int data;
    struct N* next;
}node;
void print(node *r){
    if(r==NULL){
        printf("List is empty");
    }
    else{
        while(r != NULL){
        printf("%d ", r->data);
        r=r->next;
        }
    }
}
void insertion(node *r, int x){
    if(r==NULL){
        node *root = (node*)malloc(sizeof(node));
        root->data=x;
        root->next=NULL;
    }
    else{
        while(r->next != NULL){
            r=r->next;
        }
        node *temp=(node*)malloc(sizeof(node));
        r->next=temp;
        temp->data=x;
        temp->next=NULL;
    }
}
node *sortInsertion(node *r, int x){
    
}
int main(){
    node *root=(node*)malloc(sizeof(node));
    root->data=5;
    root->next=NULL;
    insertion(root, 10);
    print(root);
}