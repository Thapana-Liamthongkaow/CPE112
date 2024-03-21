#include <stdio.h>
#include <stdlib.h>

struct node {
    int node_value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->node_value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *smallest(struct node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return smallest(root->left);
}

int main() {
    struct node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    struct node *smallestNode = smallest(root);
    if (smallestNode != NULL)
        printf("The smallest element is: %d\n", smallestNode->node_value);
    else
        printf("Empty.\n");

    return 0;
}
