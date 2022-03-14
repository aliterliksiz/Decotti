#include <stdio.h>
#include <stdlib.h> 
   
typedef struct N{  
    int data;  
    struct N *next;  
}node;    
   
node *head, *tail = NULL;  
   
void addNode(int data) {  
    node *newNode = (node*)malloc(sizeof(node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    if(head == NULL) {   
        head = newNode;  
        tail = newNode;  
    }  
    else {    
        tail->next = newNode;  
        tail = newNode;  
    }  
} 
    
void minNode() {  
    
    node *ptr = head;
    node *temp = head;
    int min = ptr->data;
    while (ptr != NULL && ptr->next != NULL)
    {
        if(ptr->next->data < min)
        {
            min = ptr->next->data;
            temp = ptr;
        }
        ptr = ptr->next;
    }
    node *minNode = temp->next;
    temp->next = temp->next->next;
    minNode->next = head;
    head = minNode;
}  

void print( node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
      
int main()  
{   
    addNode(7);  
    addNode(1);  
    addNode(9);
    addNode(15);
    addNode(3);
    
    print(head);
    
    minNode();  
    
    print(head);
    
    return 0;  
}