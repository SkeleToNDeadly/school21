#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void swap_rows(double **matrix, int row1, int row2);
double det(double **matrix, int size, double epsilon);
void input(double ***matrix, int *n, int *m);
void output(double **matrix, int size);

void calculate_inverse_matrix(double **matrix, double **inverse, int size);

int main() {
    int n, m;
    char c;
    double **matrix;

    input(&matrix, &n, &m);

    if (n == m) {
        double determinant = det(matrix, n, 1e-9);  // Уточнение epsilon
        if (determinant != 0) {
            // Нахождение обратной матрицы
            double **inverse_matrix = (double **)malloc(n * sizeof(double *));
            for (int i = 0; i < n; i++) {
                inverse_matrix[i] = (double *)malloc(n * sizeof(double));
                for (int j = 0; j < n; j++) {
                    inverse_matrix[i][j] = (i == j) ? 1.0 : 0.0;
                }
            }

            calculate_inverse_matrix(matrix, inverse_matrix, n);
            output(inverse_matrix, n);

            // Освобождение памяти для inverse_matrix
            for (int i = 0; i < n; i++) {
                free(inverse_matrix[i]);
            }
            free(inverse_matrix);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }

    // Освобождение выделенной памяти для матрицы
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void swap_rows(double **matrix, int row1, int row2) {
    double *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

double det(double **matrix, int size, double epsilon) {
    int pivot_index;
    double pivot_value, determinant = 1.0;

    for (int i = 0; i < size; i++) {
        pivot_index = i;
        pivot_value = fabs(matrix[i][i]);

        for (int j = i + 1; j < size; j++) {
            if (fabs(matrix[j][i]) > pivot_value) {
                pivot_index = j;
                pivot_value = fabs(matrix[j][i]);
            }
        }

        if (pivot_value < epsilon) {
            // Матрица вырождена
            return 0;
        }

        if (pivot_index != i) {
            // Обменять строки местами
            swap_rows(matrix, pivot_index, i);
            determinant *= -1;
        }

        for (int j = i + 1; j < size; j++) {
            if (matrix[j][i] != 0) {
                double multiplier = matrix[j][i] / matrix[i][i];

                for (int k = i; k < size; k++) {
                    matrix[j][k] -= matrix[i][k] * multiplier;
                }
            }
        }

        determinant *= matrix[i][i];
    }

    return determinant;
}

void input(double ***matrix, int *n, int *m) {
    char c;

    if (scanf("%d%c%d%c", n, &c, m, &c) == 4 && (*n == *m) && (c == ' ' || c == '\n')) {
        // Выделение памяти для матрицы
        *matrix = (double **)malloc(*n * sizeof(double *));
        for (int i = 0; i < *n; i++) {
            (*matrix)[i] = (double *)malloc(*m * sizeof(double));
        }

        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                if (scanf("%lf%c", &(*matrix)[i][j], &c) == 2 && (c == ' ' || c == '\n')) {
                } else {
                    printf("n/a");
                    return;
                }
            }
        }
    } else {
        printf("n/a");
        return;
    }
}

void output(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.6lf", matrix[i][j]);
            if (j < size - 1) {
                printf(" ");
            }
        }
        if (i < size - 1) {
            printf("\n");
        }
    }
}

void calculate_inverse_matrix(double **matrix, double **inverse, int size) {
    // Проход по всем столбцам
    for (int i = 0; i < size; i++) {
        // Сохранение главного элемента
        double main_diagonal_element = matrix[i][i];

        // Деление строки на главный элемент
        for (int j = 0; j < size; j++) {
            matrix[i][j] /= main_diagonal_element;
            inverse[i][j] /= main_diagonal_element;
        }

        // Обнуление всех остальных элементов в столбце
        for (int k = 0; k < size; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < size; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
}
