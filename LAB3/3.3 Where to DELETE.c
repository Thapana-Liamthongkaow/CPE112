//6607050416 Thapana Liamthnogkaow
//Lab 3.3 Where to DELETE
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void traverse(Node *start) {
    Node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

Node* deleteFirst(Node *src) {
    if (src == NULL || src->next == NULL)
        return NULL;

    Node *newHead = src->next;
    free(src);
    return newHead;
}

Node* deleteLast(Node *src) {
    if (src == NULL || src->next == NULL)
        return NULL;

    Node *ptr = src;
    Node *prev = NULL;

    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev != NULL) {
        free(ptr);
        prev->next = NULL;
    } else {
        // Deleting the only node in the list
        free(ptr);
        src = NULL;
    }

    return src;
}

Node* deleteNode(Node *src) {
    int num;
    scanf("%d", &num);

    if (src == NULL)
        return NULL;

    if (src->val == num) {
        Node *newHead = src->next;
        free(src);
        return newHead;
    }

    Node *ptr = src;
    Node *prev = NULL;

    while (ptr != NULL && ptr->val != num) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        prev->next = ptr->next;
        free(ptr);
    }

    return src;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n < 1) {
        printf("none");
        return 0;
    }

    Node *head = NULL;
    Node *ptr = head;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        new_node->val = val;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            ptr = head;
        } else {
            ptr->next = new_node;
            ptr = new_node;
        }
    }

    char choice;
    do {
        scanf(" %c", &choice);
        if (choice == 'F') {
            head = deleteFirst(head);
        } else if (choice == 'N') {
            head = deleteNode(head);
        } else if (choice == 'L') {
            head = deleteLast(head);
        } else {
            break;
        }
    } while (choice == 'F' || choice == 'N' || choice == 'L');

    if (head == NULL) {
        printf("none");
    } else {
        traverse(head);
    }

    // Free allocated memory
    ptr = head;
    while (ptr != NULL) {
        Node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    return 0;
}
