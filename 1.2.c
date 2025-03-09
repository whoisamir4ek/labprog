#include <stdio.h>

int main() {
    int a, b, sum;
    printf("Введите первое число: ");
    scanf("%d", &a);
    printf("Введите второе число: ");
    scanf("%d", &b);
    sum = a + b;
    printf("Сумма: %d\n", sum);
    return 0;
}