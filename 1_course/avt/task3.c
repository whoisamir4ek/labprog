#include <stdio.h>
#include <stdlib.h>

// Функция выделения памяти под треугольник Паскаля
int** allocate_pascal(int n) {
    // Выделяем память для массива указателей на строки
    int **triangle = (int **)malloc(n * sizeof(int *));
    if (triangle == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    // Заполняем каждую строку
    for (int i = 0; i < n; i++) {
        // Выделяем память для текущей строки (i+1 элементов)
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
        if (triangle[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        
        // Первый и последний элемент строки всегда 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        // Заполняем остальные элементы
        for (int j = 1; j < i; j++) {
            // Каждый элемент равен сумме двух элементов из предыдущей строки
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    return triangle;
}

// Функция вывода треугольника Паскаля
void print_pascal(int **triangle, int n) {
    for (int i = 0; i < n; i++) {
        // Выводим все элементы текущей строки
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");  // Переход на новую строку
    }
}

// Функция освобождения памяти
void free_pascal(int **triangle, int n) {
    // Освобождаем память для каждой строки
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    // Освобождаем массив указателей
    free(triangle);
}

int main() {
    int n;
    printf("Введите количество строк треугольника Паскаля: ");
    scanf("%d", &n);  // Чтение количества строк
    
    // Создаем треугольник Паскаля
    int **triangle = allocate_pascal(n);
    
    // Выводим треугольник
    print_pascal(triangle, n);
    
    // Освобождаем память
    free_pascal(triangle, n);
    
    return 0;
}
