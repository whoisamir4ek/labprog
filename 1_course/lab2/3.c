#include <stdio.h>

int main() {
    double num1, num2;
    double *ptr1 = &num1, *ptr2 = &num2;

    printf("Введите первое число: ");
    scanf("%lf", ptr1);

    printf("Введите второе число: ");
    scanf("%lf", ptr2);

    if (*ptr1 > *ptr2) {
        printf("Максимальное число: %.2lf\n", *ptr1);
    } else {
        printf("Максимальное число: %.2lf\n", *ptr2);
    }

    return 0;
}