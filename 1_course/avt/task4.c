#include <stdio.h>
#include <stdlib.h>

// Структура для хранения дроби
typedef struct {
    int numerator;    // Числитель
    int denominator;  // Знаменатель
} Fraction;

// Функция вычисления наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    a = abs(a);  // Берем модуль чисел
    b = abs(b);
    // Алгоритм Евклида
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция сокращения дроби
void reduce(Fraction *f) {
    // Находим НОД числителя и знаменателя
    int common_divisor = gcd(f->numerator, f->denominator);
    
    // Сокращаем дробь
    f->numerator /= common_divisor;
    f->denominator /= common_divisor;
    
    // Убедимся, что знаменатель положительный
    if (f->denominator < 0) {
        f->numerator *= -1;
        f->denominator *= -1;
    }
}

// Сложение дробей
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    // Общий знаменатель: произведение знаменателей
    // Числитель: a*d + b*c
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    reduce(&result);  // Сокращаем результат
    return result;
}

// Вычитание дробей
Fraction subtract(Fraction f1, Fraction f2) {
    Fraction result;
    // Аналогично сложению, но с минусом
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    reduce(&result);
    return result;
}

// Умножение дробей
Fraction multiply(Fraction f1, Fraction f2) {
    Fraction result;
    // Умножаем числители и знаменатели
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    reduce(&result);
    return result;
}

// Деление дробей
Fraction divide(Fraction f1, Fraction f2) {
    // Проверка деления на ноль
    if (f2.numerator == 0) {
        printf("Division by zero\n");
        exit(1);
    }
    Fraction result;
    // Деление - это умножение на обратную дробь
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    reduce(&result);
    return result;
}

// Вывод дроби
void print_fraction(Fraction f) {
    printf("%d/%d\n", f.numerator, f.denominator);
}

int main() {
    int a, b, c, d;
    char op;
    
    printf("Введите выражение в формате A/B op C/D: ");
    // Чтение входных данных
    if (scanf("%d/%d %c %d/%d", &a, &b, &op, &c, &d) != 5) {
        printf("Invalid input format\n");
        return 1;
    }
    
    // Проверка знаменателей на ноль
    if (b == 0 || d == 0) {
        printf("Denominator cannot be zero\n");
        return 1;
    }
    
    // Создаем дроби
    Fraction f1 = {a, b};
    Fraction f2 = {c, d};
    Fraction result;
    
    // Выполняем операцию в зависимости от введенного оператора
    switch (op) {
        case '+':
            result = add(f1, f2);
            break;
        case '-':
            result = subtract(f1, f2);
            break;
        case '*':
            result = multiply(f1, f2);
            break;
        case '/':
            result = divide(f1, f2);
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }
    
    // Выводим результат
    printf("Результат: ");
    print_fraction(result);
    
    return 0;
}
