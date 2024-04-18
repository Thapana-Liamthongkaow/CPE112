//66070503416 ThapanaLiamthongkaow
//LAb8 Bubble Sort
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    int flag = 0;
    int count =0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                flag = 1;
                count ++;
                swap(&arr[j], &arr[j + 1]);
                printf("Count = %d ", count);
                printf("\n");
            }
        }
        if (flag == 0){ //array is already sorted
            return ;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("array is sorted \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
