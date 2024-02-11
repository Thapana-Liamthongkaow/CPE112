//66070503416 Thapana Liamthongkaow
//Lab 3.1 Linked Lists Insertion

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void insertAtFornt(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid\n");
        return 0;
    }

    int option;
    scanf("%d", &option);

    if (option != 1 && option != 2) {
        printf("Invalid\n");
        return 0;
    }

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        if (option == 1) {
            insertAtFornt(&head, value);
        } else {
            insertAtEnd(&head, value);
        }
    }

    printLinkedList(head);

    return 0;
}
