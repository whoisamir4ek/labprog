#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Перечисление для указания типа данных в объединении
enum DataType { INT, FLOAT, STRING };

// Размеченное объединение
typedef struct {
    enum DataType type;  // Тэг - указывает тип данных
    union {
        int i;
        float f;
        char s[20];
    } data;  // Само объединение с разными типами данных
} TaggedUnion;

// Функция для печати элемента
void print_tagged_union(const TaggedUnion* tu) {
    switch (tu->type) {
        case INT:
            printf("Тип: INT, значение: %d\n", tu->data.i);
            break;
        case FLOAT:
            printf("Тип: FLOAT, значение: %.2f\n", tu->data.f);
            break;
        case STRING:
            printf("Тип: STRING, значение: %s\n", tu->data.s);
            break;
        default:
            printf("Неизвестный тип данных\n");
    }
}

int main() {
    // Создаем динамический массив из 3 элементов
    TaggedUnion* array = malloc(3 * sizeof(TaggedUnion));
    if (!array) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    // Заполняем массив разными типами данных
    array[0].type = INT;
    array[0].data.i = 42;

    array[1].type = FLOAT;
    array[1].data.f = 3.14159f;

    array[2].type = STRING;
    strncpy(array[2].data.s, "Hello, World!", sizeof(array[2].data.s));

    // Печатаем содержимое массива
    printf("Содержимое массива:\n");
    for (int i = 0; i < 3; i++) {
        print_tagged_union(&array[i]);
    }

    // Освобождаем память
    free(array);

    return 0;
}