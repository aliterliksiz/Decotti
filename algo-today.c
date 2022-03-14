#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
int smallestElement(struct Node* head)
{
    // Declare a min variable and initialize
    // it with INT_MAX value.
    // INT_MAX is integer type and its value
    // is 32767 or greater.
    int min = INT_MAX;
  
    // Check loop while head not equal to NULL
    while (head != NULL) {
  
        // If min is greater then head->data then
        // assign value of head->data to min
        // otherwise node point to next node.
        if (min > head->data)
            min = head->data;
  
        head = head->next;
    }
    return min;
}
  
// Function that push .
void push(struct Node** head, int data)
{
    // Allocate dynamic memory for newNode.
    struct Node* newNode = 
         (struct Node*)malloc(sizeof(struct Node));
  
    // Assign the data into newNode.
    newNode->data = data;
  
    // newNode->next assign the address of
    // head node.
    newNode->next = (*head);
  
    // newNode become the headNode.
    (*head) = newNode;
}
  
// Display linked list.
void printList(struct Node* head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    cout << "NULL" << endl;
}
  
// Driver program to test the functions
int main()
{
    // Start with empty list
    struct Node* head = NULL;
  
    // Using push() function to construct
    // singly linked list
    // 17->22->13->14->15
    push(&head, 15);
    push(&head, 14);
    push(&head, 13);
    push(&head, 22);
    push(&head, 17);
    cout << "Linked list is : " << endl;
  
    // Call printList() function to display
    // the linked list.
    printList(head);
    cout << "Maximum element in linked list:";
  
    // Call largestElement() function to get largest
    // element in linked list.
    cout << "Minimum element in linked list:";
  
    // Call smallestElement() function to get smallest
    // element in linked list.
    cout << smallestElement(head) << endl;
  
    return 0;
}
