#include <stdio.h>
#include <math.h>

// Структура для представления комплексного числа
typedef struct {
    double real;    // действительная часть
    double imag;    // мнимая часть
} Complex;

// Функция сложения комплексных чисел
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Функция умножения комплексных чисел
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Функция деления комплексного числа на вещественное
Complex divide_by_scalar(Complex a, double scalar) {
    Complex result;
    result.real = a.real / scalar;
    result.imag = a.imag / scalar;
    return result;
}

// Функция вычисления факториала
double factorial(int n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция вычисления комплексной экспоненты (ряд Тейлора)
Complex complex_exp(Complex z, int terms) {
    Complex result = {1.0, 0.0};  // Начальное значение (первый член ряда)
    Complex current_term = {1.0, 0.0};  // Текущий член ряда (z^n/n!)
    
    for (int n = 1; n <= terms; n++) {
        current_term = multiply(current_term, z);  // Умножаем на z для получения z^n
        current_term = divide_by_scalar(current_term, n);  // Делим на n для получения z^n/n!
        result = add(result, current_term);  // Добавляем к результату
    }
    
    return result;
}

// Функция вывода комплексного числа
void print_complex(Complex z) {
    if (z.imag >= 0) {
        printf("%.4f + %.4fi", z.real, z.imag);
    } else {
        printf("%.4f - %.4fi", z.real, -z.imag);
    }
}

int main() {
    Complex z;
    int terms;
    
    printf("Введите действительную часть комплексного числа: ");
    scanf("%lf", &z.real);
    
    printf("Введите мнимую часть комплексного числа: ");
    scanf("%lf", &z.imag);
    
    printf("Введите количество членов ряда Тейлора: ");
    scanf("%d", &terms);
    
    Complex exp_z = complex_exp(z, terms);
    
    printf("\nРезультат вычисления exp(");
    print_complex(z);
    printf(") с %d членами ряда:\n", terms);
    print_complex(exp_z);
    printf("\n");
    
    return 0;
}
