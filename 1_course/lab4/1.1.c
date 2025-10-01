#include <stdio.h>

// Функция для вычисления факториала с использованием цикла
unsigned long long factorial_loop(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция для вычисления факториала с использованием рекурсии
unsigned long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main() {
    int num;
    printf("Введите число для вычисления факториала: ");
    scanf("%d", &num);

    printf("Факториал (цикл): %llu\n", factorial_loop(num));
    printf("Факториал (рекурсия): %llu\n", factorial_recursive(num));

    return 0;
}
