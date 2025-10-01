#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MY_SIZE 20

int main() {
    setlocale(LC_ALL, "en_US.iso88591");

    char my_string[MY_SIZE];
    printf("Введите строку (до 10 символов): ");
    fgets(my_string, MY_SIZE, stdin);
    my_string[strcspn(my_string, "\n")] = '\0'; // Удаление символа новой строки

    // 1. Вычисление длины строки с использованием цикла
    int length = 0;
    for (; my_string[length] != '\0'; length++);
    printf("Длина строки (цикл): %d\n", length);

    // 2. Вычисление длины строки с использованием указателя
    char *ptr = my_string;
    int ptr_length = 0;
    while (*ptr++) ptr_length++;
    printf("Длина строки (указатель): %d\n", ptr_length);

    // 3. Вычисление длины строки с использованием strlen
    printf("Длина строки (strlen): %zu\n", strlen(my_string));

    // 4. Копирование строки
    char second_string[MY_SIZE];
    strcpy(second_string, my_string);
    printf("Скопированная строка: %s\n", second_string);

    // 5. Конкатенация строк
    char str1[MY_SIZE] = "Hello";
    char str2[] = "World";
    strcat(str1, str2);
    printf("Результат конкатенации: %s\n", str1);

    // 6. Сравнение строк
    char str3[] = "apple";
    char str4[] = "banana";
    int cmp_result = strcmp(str3, str4);
    printf("Результат сравнения: %d\n", cmp_result);

    // 7. Перевод регистра
    char mixed_case[] = "AbCdEf";
    printf("Исходная строка: %s\n", mixed_case);
    for (int i = 0; mixed_case[i]; i++) {
        mixed_case[i] = tolower(mixed_case[i]);
    }
    printf("В нижнем регистре: %s\n", mixed_case);
    for (int i = 0; mixed_case[i]; i++) {
        mixed_case[i] = toupper(mixed_case[i]);
    }
    printf("В верхнем регистре: %s\n", mixed_case);

    return 0;
}
```

**Результат работы программы:**
```
Введите строку (до 10 символов): test
Длина строки (цикл): 4
Длина строки (указатель): 4
Длина строки (strlen): 4
Скопированная строка: test
Результат конкатенации: HelloWorld
Результат сравнения: -1
Исходная строка: AbCdEf
В нижнем регистре: abcdef
В верхнем регистре: ABCDEF
```

---

#### Задача 2.2: Конвертация строк в числа

**Постановка задачи:**  
Конвертировать строки, представляющие числа, в значения типов `double` и `int`.

**Код программы:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char float_str[] = "3.14";
    char int_str[] = "42";

    double float_num = atof(float_str);
    int int_num = atoi(int_str);

    printf("Конвертированное double: %.2f\n", float_num);
    printf("Конвертированное int: %d\n", int_num);

    return 0;
}
