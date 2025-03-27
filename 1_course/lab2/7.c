#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int **array;

    printf("Введите кол-во строк: ");
    scanf("%d", &rows);
    
    printf("Введите кол-во столбцов: ");
    scanf("%d", &cols);

    array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("\nОшибка выделения памяти\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
        }
    }

    printf("Двумерный массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}