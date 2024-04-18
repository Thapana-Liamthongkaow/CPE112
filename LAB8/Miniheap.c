/*
Minheap
Current Node	arr[i]
Parent Node	arr[(i-1)/2]
Left Child	arr[(2*i) + 1]
Right Child	arr[(2*i )+ 2]
The root of the whole tree is at arr[0].
Instructions
The program should implement the following operations on the min heap binary tree:

Insertion : Inserting a node into the min heap binary tree.

Deletion : Removing a node from min heap binary tree.

Print : To display the array of min heap binary tree.

Input
There are 4 mode of operations. The user can select any of the following operations. The program will continue the last operation until the user selects the new option.

INSERT : Insert all following nodes into the min heap binary tree.
DELETE : Delete all following nodes from the min heap binary tree. Assuming all following nodes exists in the binary tree.
PRINT : Call the print function to display the min heap binary tree. Assuming that there is always at least one node in the binary tree.
EXIT : Exit the program.
Output
The output will depend on the operation selected by the user.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_COMMAND_LENGTH 10

typedef struct node {
    int data;
} node;

typedef struct heap {
    node *array;
    int size;
} heap;

heap *createHeap() {
    heap *heap_ptr = (heap *)malloc(sizeof(heap));
    if (heap_ptr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    heap_ptr->size = 0;
    heap_ptr->array = (node *)malloc(sizeof(node) * MAX);
    if (heap_ptr->array == NULL) {
        // Handle memory allocation failure
        free(heap_ptr);
        return NULL;
    }

    return heap_ptr;
}

void insertHeap(heap *heap, int data) {
    if (heap->size == MAX) {
        printf("Heap is full\n");
        return;
    }

    int i = heap->size;
    heap->array[i].data = data;
    heap->size++;
    heapifyUp(heap, i);
}

void heapifyUp(heap *heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->array[index].data < heap->array[parent].data) {
        // Swap current node with its parent
        node temp = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = temp;
        // Move up to the parent level
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(heap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->array[left].data < heap->array[smallest].data) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right].data < heap->array[smallest].data) {
        smallest = right;
    }

    if (smallest != index) {
        // Swap current node with the smallest child
        node temp = heap->array[index];
        heap->array[index] = heap->array[smallest];
        heap->array[smallest] = temp;
        // Move down to the smallest child
        heapifyDown(heap, smallest);
    }
}

void deleteHeap(heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return;
    }

    // Swap root node with the last node
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Heapify down from the root
    heapifyDown(heap, 0);
}

void printHeap(heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i].data);
    }
    printf("\n");
}

int main() {
    heap *my_heap = createHeap();
    if (my_heap == NULL) {
        // Handle heap creation failure
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    int val;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "INSERT") == 0) {
            while (scanf("%d", &val) == 1) {
                insertHeap(my_heap, val);
            }
        }
        else if (strcmp(command, "DELETE") == 0) {
            while (scanf("%d", &val) == 1) {
                deleteHeap(my_heap);
            }
        }
        else if (strcmp(command, "PRINT") == 0) {
            printHeap(my_heap);
        }
        else if (strcmp(command, "EXIT") == 0) {
            free(my_heap->array);
            free(my_heap);
            return 0;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
