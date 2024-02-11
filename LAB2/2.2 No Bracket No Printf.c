//66070503416 Thapana Liamthongkaow
//lab 2.2 No Bracket No Printf

#include <stdio.h>

void a(int arr[], int n, int *max, int *min, int *maxIndex, int *minIndex) {
    *max = *min = arr[0];
    *maxIndex = *minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > *max) *max = arr[i], *maxIndex = i;
        if (arr[i] < *min) *min = arr[i], *minIndex = i;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    int max, min, maxIndex, minIndex;
    a(arr, n, &max, &min, &maxIndex, &minIndex);
    printf("%d %d\n%d %d\n", max, maxIndex, min, minIndex);

    return 0;
}
