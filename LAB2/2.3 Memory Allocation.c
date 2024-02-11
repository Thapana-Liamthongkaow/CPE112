//66070503416 Thapana Liamthongkaow
//Lab 2.3 Memory Allocation

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

long sum(long *arr, int n) {
    long x = 0;
    for (int i = 0; i < n; i++)
        x += arr[i];
    return x;
}

long difference(long *arr, int n) {
    long x = 0;
    for (int i = 0; i < n; i++)
        x -= arr[i];
    return x;
}

int main() {
    long *arr1 = (long *)calloc(MAX, sizeof(long));
    for (int i = 0; i < MAX; i++)
        arr1[i] = i + 1;

    long *arr2 = (long *)malloc(MAX * sizeof(long));
    for (int i = 0; i < MAX; i++)
        arr2[i] = i + 1;

    printf("%ld \n", sum(arr1, MAX));
    printf("%ld \n", difference(arr2, MAX));

    free(arr1);
    free(arr2);

    return 0;
}
