//66070503416 Thapana liamthongkaow
//Lab 2.1 No Bracket

#include <stdio.h>

void bracket(int arr[], int n, int mode) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((mode == 1 && arr[j] > arr[j + 1]) || (mode == 0 && arr[j] < arr[j + 1]))
                arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
}

int main() {
    int n, mode;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &mode);

    for (int i = mode; i < n; i += 2)
        printf("%d ", arr[i]);

    printf(n == 0 || mode >= n ? "none" : "");

    return 0;
}
