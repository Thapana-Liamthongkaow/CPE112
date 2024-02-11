//66070503416 Thapana Liamthogkaow
//Lab 2.6 Sum of Diagonal Matrix

#include <stdio.h>

int main() {
    int row, col, i, j, primarySum = 0, secondarySum = 0;

    scanf("%d %d", &row, &col);

    if (row != col) {
        printf("ERROR");
        return 1;
    }

    int matrix[row][col];

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for (i = 0; i < row; i++) {
        primarySum += matrix[i][i];
    }

    // Calculate secondary diagonal sum
    for (i = 0; i < row; i++) {
        secondarySum += matrix[i][col - 1 - i];
    }

    printf("%d\n", primarySum);
    printf("%d", secondarySum);

    return 0;
}
