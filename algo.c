#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}node;

node *sil(node *r, int a){
    node *iter = r;
    node *temp;

    if(r->data == a){
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while(iter->next != NULL && iter->next->data != a){
        iter=iter->next;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}
