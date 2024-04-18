//66070503416 Thapaan Liamthognkaow
//LAB 8.1 MinHeap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);
void minHeapify(int index, int *heap, int size);
void insert(int key, int *heap, int *size);
void delete(int key, int *heap, int *size);
void printHeap(int *heap, int size);

int main(){
    char operation[10];
    int num, heap[999], size = 0;

    while(1){
        scanf("%s", operation);
        if(strcmp(operation, "INSERT") == 0){
            while (scanf("%d", &num) == 1) {
                insert(num, heap, &size);
            }
        }
        else if(strcmp(operation, "DELETE") == 0){
            scanf("%d", &num);
            delete(num, heap, &size);
        }
        else if(strcmp(operation, "PRINT") == 0){
            printHeap(heap, size);
        }
        else if(strcmp(operation, "EXIT") == 0){
            break;
        }
    }
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int index, int *heap, int size){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left<size && heap[left]<heap[smallest]){
        smallest = left;
    }
    if(right<size && heap[right]<heap[smallest]){
        smallest = right;
    }

    if(smallest != index){
        swap(&heap[index], &heap[smallest]);
        minHeapify(smallest, heap, size);
    }
}

void insert(int key, int *heap, int *size){
    if(*size == 999){
        return;
    }

    int i = (*size)++;
    heap[i] = key;

    while(i > 0 && heap[(i - 1) / 2] > heap[i]){
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void delete(int key, int *heap, int *size){
    int i;
    for(i = 0; i < *size; ++i){
        if (heap[i] == key)
            break;
    }

    if(i == *size){
        return;
    }

    swap(&heap[i], &heap[--(*size)]);
    for(i = ((*size) / 2) - 1; i >= 0 ; i--){
        minHeapify(i, heap, *size);
    }
}

void printHeap(int *heap, int size){
    for(int i=0;i<size;++i){
        printf("%d ", heap[i]);
    }
    printf("\n");
}