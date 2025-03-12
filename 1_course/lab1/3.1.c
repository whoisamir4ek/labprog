#include <stdio.h>

int main() {
    int n;

    printf("Введите размер вектора: ");
    scanf("%d", &n);

    int X[n], Y[n];

    printf("Введите элементы вектора X: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < n; i++) {
        Y[i] = X[i] * X[i];
    }

    printf("Вектор Y = X * X: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    return 0;
}