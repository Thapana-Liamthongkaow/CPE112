//66070503416 Thapana Liamthongkaow
//Lab 1.2 The foundation of set

#include <stdio.h>

void scanData(int start, int end, int *k, int arr[]) {
    for (int i = 0; i < *k; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < start || arr[i] > end) {
            i--;
            (*k)--;
        }
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                i--;
                (*k)--;
            }
        }
    }
}

int main(void) {
    int start, end, n, m, arr1[10000], arr2[10000], i, j, k = 0;
    int checkIntersec, checkDiffA, checkDiffB;

    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &n);
    scanData(start, end, &n, arr1);

    scanf("%d", &m);
    scanData(start, end, &m, arr2);

    // First line
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    if (n == 0)
        printf("empty");
    printf("\n");

    // Second line
    for (i = 0; i < m; i++)
        printf("%d ", arr2[i]);
    if (m == 0)
        printf("empty");
    printf("\n");

    // Third line
    if (n == 0 && m == 0)
        printf("empty");
    for (i = 0; i < n; i++) {
        for (j = k; j < m; j++) {
            if (arr1[i] <= arr2[j]) {
                if (arr1[i] == arr2[j])
                    k++;
                break;
            } else
                printf("%d ", arr2[j]);
            k++;
        }
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Fourth line
    checkIntersec = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                checkIntersec = 1;
            }
        }
    }
    if (!checkIntersec)
        printf("empty");
    printf("\n");

    // Fifth line
    int NotAllforA = 1;
    for (i = 0; i < n; i++) {
        checkDiffA = 0;
        for (j = 0; j < m; j++)
            if (arr1[i] == arr2[j])
                checkDiffA = 1;
        if (!checkDiffA) {
            printf("%d ", arr1[i]);
            NotAllforA = 0;
        }
    }
    if (NotAllforA)
        printf("empty");
    printf("\n");

    // Sixth line
    int NotAllforB = 1;
    for (i = 0; i < m; i++) {
        checkDiffB = 0;
        for (j = 0; j < n; j++)
            if (arr2[i] == arr1[j])
                checkDiffB = 1;
        if (!checkDiffB) {
            printf("%d ", arr2[i]);
            NotAllforB = 0;
        }
    }
    if (NotAllforB)
        printf("empty");
    printf("\n");

    // Seventh line
    int NoComplementA = 0;
    for (i = start; i <= end; i++) {
        int checkComplementA = 0;
        for (j = 0; j < n; j++)
            if (i == arr1[j])
                checkComplementA = 1;
        if (!checkComplementA) {
            printf("%d ", i);
            NoComplementA = 1;
        }
    }
    if (!NoComplementA)
        printf("empty");
    printf("\n");

    // Eighth line
    int NoComplementB = 0;
    for (i = start; i <= end; i++) {
        int checkComplementB = 0;
        for (j = 0; j < m; j++)
            if (i == arr2[j])
                checkComplementB = 1;
        if (!checkComplementB) {
            printf("%d ", i);
            NoComplementB = 1;
        }
    }
    if (!NoComplementB)
        printf("empty");

    return 0;
}
