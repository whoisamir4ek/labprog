#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100  // Максимальный размер стека

int stack[MAX_SIZE];  // Массив для реализации стека
int top = -1;         // Индекс вершины стека

// Добавление числа в стек
void push(int num) {
    // Проверка на переполнение стека
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);  // Аварийное завершение программы
    }
    stack[++top] = num;  // Увеличиваем top и добавляем элемент
}

// Извлечение числа из стека
int pop() {
    // Проверка на пустоту стека
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);  // Аварийное завершение программы
    }
    return stack[top--];  // Возвращаем элемент и уменьшаем top
}

// Проверка, является ли символ оператором
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Выполнение арифметической операции
int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;  // Сложение
        case '-': return a - b;  // Вычитание
        case '*': return a * b;  // Умножение
        case '/': 
            if (b == 0) {  // Проверка деления на ноль
                printf("Division by zero\n");
                exit(1);
            }
            return a / b;  // Целочисленное деление
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Основная функция вычисления постфиксного выражения
int evaluate_postfix(char *expr) {
    // Разбиваем строку на токены по пробелам
    char *token = strtok(expr, " ");
    
    while (token != NULL) {
        // Если токен - число
        if (isdigit(token[0])) {
            push(atoi(token));  // Преобразуем строку в число и добавляем в стек
        } 
        // Если токен - оператор
        else if (is_operator(token[0])) {
            int b = pop();  // Второй операнд
            int a = pop();  // Первый операнд
            push(calculate(a, b, token[0]));  // Вычисляем и кладем результат в стек
        } 
        // Некорректный токен
        else {
            printf("Invalid token: %s\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");  // Следующий токен
    }
    
    // В стеке должен остаться только результат
    if (top != 0) {
        printf("Invalid expression\n");
        exit(1);
    }
    
    return pop();  // Возвращаем результат
}

int main() {
    char expr[MAX_SIZE];
    printf("Введите выражение в постфиксной нотации: ");
    fgets(expr, MAX_SIZE, stdin);  // Чтение выражения
    expr[strcspn(expr, "\n")] = '\0';  // Удаление символа новой строки

    int result = evaluate_postfix(expr);
    printf("Результат: %d\n", result);

    return 0;
}
