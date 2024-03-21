#include <stdio.h>
#include <stdlib.h>

// Функция для суммирования двух матриц
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Функция для умножения двух матриц
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Функция для транспонирования матрицы
void transposeMatrix(int **matrix, int **result, int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

// Функция для освобождения памяти, выделенной под матрицы
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int operation;
    scanf("%d", &operation);

    int rows1, cols1, rows2, cols2;

    // Ввод размеров и элементов первой матрицы
    scanf("%d %d", &rows1, &cols1);
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Ввод размеров и элементов второй матрицы (если необходимо)
    if (operation == 1 || operation == 2) {
        scanf("%d %d", &rows2, &cols2);

        int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
        for (int i = 0; i < rows2; i++) {
            matrix2[i] = (int *)malloc(cols2 * sizeof(int));
            for (int j = 0; j < cols2; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }

        // Выполнение операции в зависимости от введенного кода
        if (operation == 1) {
            // Суммирование двух матриц
            if (rows1 == rows2 && cols1 == cols2) {
                int **result = (int **)malloc(rows1 * sizeof(int *));
                for (int i = 0; i < rows1; i++) {
                    result[i] = (int *)malloc(cols1 * sizeof(int));
                }
                addMatrices(matrix1, matrix2, result, rows1, cols1);

                // Вывод результата
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols1; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }

                // Освобождение памяти
                freeMatrix(result, rows1);
            } else {
                printf("n/a\n");
            }
        } else if (operation == 2) {
            // Умножение матриц
            if (cols1 == rows2) {
                int **result = (int **)malloc(rows1 * sizeof(int *));
                for (int i = 0; i < rows1; i++) {
                    result[i] = (int *)malloc(cols2 * sizeof(int));
                }
                multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

                // Вывод результата
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols2; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }

                // Освобождение памяти
                freeMatrix(result, rows1);
            } else {
                printf("n/a\n");
            }
        }

        // Освобождение памяти для второй матрицы
        freeMatrix(matrix2, rows2);
    } else if (operation == 3) {
        // Транспонирование матрицы
        int **result = (int **)malloc(cols1 * sizeof(int *));
        for (int i = 0; i < cols1; i++) {
            result[i] = (int *)malloc(rows1 * sizeof(int));
        }
        transposeMatrix(matrix1, result, rows1, cols1);

        // Вывод результата
        for (int i = 0; i < cols1; i++) {
            for (int j = 0; j < rows1; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        // Освобождение памяти
        freeMatrix(result, cols1);
    } else {
        printf("n/a\n");
    }

    // Освобождение памяти для первой матрицы
    freeMatrix(matrix1, rows1);

    return 0;
}
