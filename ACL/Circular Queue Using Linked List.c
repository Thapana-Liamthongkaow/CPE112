#include <stdlib.h>
#include <stdio.h>

// Node structure for our linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Pointer to the first node in the list
Node *head = NULL;

// Pointer to the last node in the list
Node *tail = NULL;

// Function to add a new node to the end of the list
void enqueue(int data) {
    // Create a new node
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    // Check if the list is empty
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        // Link the new node to the tail of the list
        tail->next = new_node;
        tail = new_node;
    }
}

// Function to remove and return the first node in the list
int dequeue() {
    // Check if the list is empty
    if (head == NULL) {
        return -1;
    }

    // Store the data of the first node
    int data = head->data;

    // Check if the list has only one node
    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        // Remove the first node from the list
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return data;
}

// Function to print the contents of the list
void print_list() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("Contents of the list: ");
    print_list();

    int dequeued_data = dequeue();
    printf("Dequeued data: %d\n", dequeued_data);

    printf("Contents of the list: ");
    print_list();

    return 0;
}