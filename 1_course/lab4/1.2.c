#include <stdio.h>
#include <stdlib.h>

// Функция для обмена значений чётных и нечётных ячеек массива
void swap_even_odd(int *arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main() {
    int *arr = (int *)malloc(12 * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Заполнение массива
    for (int i = 0; i < 12; i++) {
        arr[i] = i + 1;
    }

    printf("Исходный массив:\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    swap_even_odd(arr, 12);

    printf("Массив после обмена:\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
