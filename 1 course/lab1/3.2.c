#include <stdio.h>

int main() {
    int n;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    int X[n];

    printf("Введите элементы массива X: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    printf("Массив в обратном порядке: \n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}