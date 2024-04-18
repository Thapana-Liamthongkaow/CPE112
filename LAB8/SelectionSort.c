//66070503416 Thapana Liamthongkaow
//LAB 8 Selection Sort
#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int *arr, int n);
void printArray(int *arr, int n);

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
        printArray(arr, n);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
