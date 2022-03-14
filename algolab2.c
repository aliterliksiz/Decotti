#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
struct Node {
    char *data;
    struct Node* next;
};

void push(struct Node** head_ref, char *new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int count(struct Node* head, char *search_for)
{
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == search_for)
            count++;
        current = current->next;
    }
    return count;
}

int count2(struct Node* head, char *key)
{
	if (head == NULL)
		return 0;
	if (head->data == key)
		return 1 + count(head->next, key);
	return count(head->next, key);
}
 
int main()
{
    struct Node* head = NULL;
 
    push(&head, '2');
    push(&head, 1);
    push(&head, 2);
    push(&head, 5);
    push(&head, '5');
    push(&head, 5);
    push(&head, '2');
    push(&head, 1);
    
	clock_t t;
    t = clock();
    printf("count of '2' is %d\n", count(head, '2'));
    printf("count of 1 is %d\n", count(head, 1));
    printf("count of 2 is %d\n", count(head, 2));
    printf("count of 5 is %d\n", count(head, 5));
    printf("count of '5' is %d\n", count(head, '5'));
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Iterative took %f mseconds to execute \n", time_taken);
    
    
    printf("\n\n");
    
    clock_t t2;
    t2 = clock();
    printf("count of '2' is %d\n", count2(head, '2'));
    printf("count of 1 is %d\n", count2(head, 1));
    printf("count of 2 is %d\n", count2(head, 2));
    printf("count of 5 is %d\n", count2(head, 5));
    printf("count of '5' is %d\n", count2(head, '5'));
    t2 = clock() - t2;
    
    double time_takenm = ((double)t2)/CLOCKS_PER_SEC; 
    printf("Recursive took %f mseconds to execute \n", time_takenm);
    
    return 0;
}