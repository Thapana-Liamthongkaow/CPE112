//66070503416 Thapana Liamthongkaow
//Assignment 2.5 Spiral Array Printer

#include <stdio.h>
#include <stdlib.h>

void printSpiral(int **matrix, int row, int col) {
    int top = 0, bottom = row - 1, left = 0, right = col - 1, direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                printf("%d ", matrix[top][i]);
            }
            top++;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                printf("%d ", matrix[i][right]);
            }
            right--;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printSpiral(matrix, row, col);

    return 0;
}

