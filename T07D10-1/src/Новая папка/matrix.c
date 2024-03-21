#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
int** createMatrixSingleArray(int rows, int cols) {
    int** single_array_matrix = malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
    int* ptr = (int*)(single_array_matrix + rows);

    for (int i = 0; i < rows; i++) {
        single_array_matrix[i] = ptr + cols * i;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &single_array_matrix[i][j]) != 1) {
                printf("n/a");
                freeMatrix(single_array_matrix, rows);  // Free allocated memory before returning
                return NULL;
            }
        }
    }

    // Print the matrix
    printMatrix(single_array_matrix, rows, cols);

    freeMatrix(single_array_matrix, rows);  // Free allocated memory before returning

    return single_array_matrix;
}

int** createMatrixPointerArray(int rows, int cols) {
    int** pointer_array = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        pointer_array[i] = malloc(cols * sizeof(int));
    }

    // Input values into the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &pointer_array[i][j]) != 1) {
                printf("n/a");
                return NULL;
            }
        }
    }

    // Print the matrix
    printMatrix(pointer_array, rows, cols);

    return pointer_array;
}

int** createMatrixMixed(int rows, int cols) {
    int** pointer_array = malloc(rows * sizeof(int*));
    int* values_array = malloc(rows * cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        pointer_array[i] = values_array + cols * i;
    }

    // Input values into the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &pointer_array[i][j]) != 1) {
                printf("n/a");
                return NULL;
            }
        }
    }

    // Print the matrix
    printMatrix(pointer_array, rows, cols);

    return pointer_array;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    free(matrix[0]);
    free(matrix);
}
void staticAllocation(int rows, int cols) {
    int matrix[100][100];
    char c;
    // Input matrix elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (scanf("%d%c", &matrix[i][j], &c) != 2 && (c!= ' ' || c!='\n')) {
                printf("n/a");
                return;
            }
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
        }
    }
}

void dynamicAllocation(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    char c;

    if (matrix == NULL) {
        printf("n/a");
        return;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));

        if (matrix[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            printf("n/a");
            return;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (scanf("%d%c", &matrix[i][j],&c) != 2 && (c!= ' ' || c!='\n')) {
                for (int k = 0; k <= i; ++k) {
                    free(matrix[k]);
                }
                free(matrix);
                printf("n/a");
                return;
            }
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int choice;
    int rows, cols;
            char c;
    if (scanf("%d%c", &choice, &c) != 2 && ( choice < 1 || choice > 4) && (c!=' ' || c!='\n')) {
        printf("n/a");
        return 1;
    }

    
    if (scanf("%d%c%d%c", &rows, &cols, &c) != 4 && (c!=' ' || c!='\n')) {
        printf("n/a");
        return 1;
    }

    switch (choice) {
        case 1:
            staticAllocation(rows, cols);
            break;
        case 2:
            dynamicAllocation(rows, cols);
            break;
        case 3:
            dynamicAllocation(rows, cols);
            break;
        case 4:
            dynamicAllocation(rows, cols);
            break;
        default:
            printf("n/a");
            break;
    }

    return 0;
}
      
