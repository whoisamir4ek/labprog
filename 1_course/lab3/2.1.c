#include <stdio.h>
#include <string.h>

// Объединение для хранения разных типов данных
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;          // Объявляем объединение
    union Data *ptr = &data;  // Указатель на объединение

    // Работа с целым числом через указатель
    ptr->i = 10;
    printf("data.i = %d\n", ptr->i);

    // Работа с вещественным числом через указатель
    ptr->f = 3.14;
    printf("data.f = %.2f\n", ptr->f);

    // Работа со строкой через указатель
    strcpy(ptr->str, "Hello, Union!");
    printf("data.str = %s\n", ptr->str);

    // Демонстрация перекрытия памяти
    printf("\nДемонстрация перекрытия памяти:\n");
    printf("После записи строки:\n");
    printf("data.i = %d (мусор)\n", ptr->i);
    printf("data.f = %f (мусор)\n", ptr->f);
    printf("data.str = %s\n\n", ptr->str);

    // Восстановим целое число
    ptr->i = 12345;
    printf("После записи целого числа:\n");
    printf("data.i = %d\n", ptr->i);
    printf("data.f = %f (мусор)\n", ptr->f);
    printf("data.str = %s (мусор)\n", ptr->str);

    return 0;
}