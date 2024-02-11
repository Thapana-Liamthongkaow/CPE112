//66070503416 Thapana Liamthongkaow
//Assignment 2.3 Symmetric Matrix

#include <stdio.h>
#include <stdlib.h>

int is_symmetric(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // False
            }
        }
    }
    return 1; // True
}

int is_skew_symmetric(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i != j && matrix[i][j] != -matrix[j][i]) {
                return 0; // False
            }
        }
    }
    return 1; // True
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (is_symmetric(matrix, n, m)) {
        printf("The matrix is symmetric\n");
    } else if (is_skew_symmetric(matrix, n, m)) {
        printf("The matrix is skew-symmetric\n");
    } else {
        printf("None\n");
    }

    // Free dynamically allocated memory
    free_matrix(matrix, n);

    return 0;
}
