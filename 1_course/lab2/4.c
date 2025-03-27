#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *arr;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", arr + i);
    }

    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}