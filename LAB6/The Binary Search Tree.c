//66070503416 Thapana Liamthogkaow 
//Lab 6.2 The Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printSorted(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printSorted(root->left);
    printf("%d ", root->data);
    printSorted(root->right);
}

int main() {
    struct Node* root = NULL;
    char command[10];
    int value;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "INS") == 0) {
            scanf("%d", &value);
            root = insert(root, value);
        } else if (strcmp(command, "PREORDER") == 0) {
            preorder(root);
            printf("\n");
        } else if (strcmp(command, "INORDER") == 0) {
            inorder(root);
            printf("\n");
        } else if (strcmp(command, "POSTORDER") == 0) {
            postorder(root);
            printf("\n");
        } else if (strcmp(command, "END") == 0) {
            printSorted(root);
            printf("\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

