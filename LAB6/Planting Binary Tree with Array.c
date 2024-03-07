//66070503416 Thapana Liamthongkaow
//Lab 6.2 Planting Binary Tree with Arrays
#include <stdio.h>
#include <string.h>
#define MAX_NODES 100

int tree[MAX_NODES];
int n;                

void initTree() {
    memset(tree, -1, sizeof(tree));
}

int insertLeft(int par, int val) {
    int leftChildIndex = 2 * par + 1;
    if (leftChildIndex >= n) {
        printf("overflow\n");
        return 0;
    } else if (tree[leftChildIndex] == -1) {
        tree[leftChildIndex] = val;
        return 1; 
    } else {
        printf("node already presented\n");
        return 0;
    }
}

int insertRight(int par, int val) {
    int rightChildIndex = 2 * par + 2;
    if (rightChildIndex >= n) {
        printf("overflow\n");
        return 0;
    } else if (tree[rightChildIndex] == -1) {
        tree[rightChildIndex] = val;
        return 1;
    } else {
        printf("node already presented\n");
        return 0;
    }
}

int findNode(int val) {
    for (int i = 0; i < n; i++) {
        if (tree[i] == val) {
            return i;
        }
    }
    return -1; 
}

void levelOrder() {
    for (int i = 0; i < n; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        }
        else {
            printf("null ");
        }
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    if (n<1){
        return 0;
    }
    initTree();

    char command[10];
    int par, val;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0) {
            break;
        }

        if (strcmp(command, "ROOT") == 0) {
            scanf("%d", &val);
            if (tree[0] != -1) {
                printf("cannot create duplicated root\n");
            } else {
                tree[0] = val;
            }
        } else if (strcmp(command, "INSL") == 0) {
            scanf("%d %d", &par, &val);
            int parIndex = findNode(par);
            if (parIndex == -1) {
                printf("not found\n");
            } else {
                insertLeft(parIndex, val);
            }
        } else if (strcmp(command, "INSR") == 0) {
            scanf("%d %d", &par, &val);
            int parIndex = findNode(par);
            if (parIndex == -1) {
                printf("not found\n");
            } else {
                insertRight(parIndex, val);
            }
        } else {
            printf("Invalid command\n");
        }
    }

    levelOrder();
    return 0;
}

