//66070503416 ThapanaLiamthongkaow
//LAB Insertion Sort
#include <stdio.h>

void insertionSort(int *arr, int n) {
    int i, j, key;
    int count = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        count ++;
        printf("Count = %d",count);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
