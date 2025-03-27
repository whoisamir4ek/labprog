#include <stdio.h>

int main() {
    double num1, num2, sum;
    double *ptr1 = &num1, *ptr2 = &num2;

    printf("Введите первое число: ");
    scanf("%lf", ptr1);

    printf("Введите второе число: ");
    scanf("%lf", ptr2);

    sum = *ptr1 + *ptr2;

    printf("Сумма чисел: %.2lf\n", sum);

    return 0;
}