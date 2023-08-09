#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL; // Initialize an empty linked list
    
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
    printf("Linked List: ");
    display(head);
    
    return 0;
}
