#include <stdio.h>
#include <stdlib.h>

// Функция для выделения памяти под матрицу
double **allocate_matrix(int rows, int cols) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Функция для освобождения памяти матрицы
void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для заполнения матрицы
void fill_matrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j + 0.5;
        }
    }
}

// Функция для вывода матрицы
void print_matrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3, cols = 3;
    double **matrix = allocate_matrix(rows, cols);
    if (matrix == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    fill_matrix(matrix, rows, cols);
    printf("Матрица:\n");
    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);
    return 0;
}
