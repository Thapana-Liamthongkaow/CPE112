//66070503416 Thapana Liamthongkaow
//Lab 1.1 Sets
#include <stdio.h>

void findUnique(int n, int arr[], int *m, int unique[]) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            unique[j++] = arr[i];
        }
    }
    *m = j;
}

int main() {
    int n;
    scanf("%d", &n);
    if(n>1000||n<1){
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int m;
    int unique[n];

    findUnique(n, arr, &m, unique);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", unique[i]);
    }

    return 0;
}
