#include <stdio.h>
#include <stdint.h>

// Структура для хранения даты с битовыми полями
typedef struct {
    unsigned int day : 5;    // 5 бит (до 31)
    unsigned int month : 4;  // 4 бита (до 15, нам нужно до 12)
    unsigned int year : 12;  // 12 бит (до 4095, достаточно для годов 0-4095)
} CompactDate;

// Функция для вывода даты
void print_date(const CompactDate* date) {
    printf("Дата: %02u.%02u.%04u\n", date->day, date->month, date->year);
}

// Функция для проверки корректности даты
int is_date_valid(const CompactDate* date) {
    if (date->month == 0 || date->month > 12) return 0;
    if (date->day == 0) return 0;
    
    // Проверка количества дней в месяце
    int days_in_month;
    switch (date->month) {
        case 2:
            // Простой способ проверки високосного года
            days_in_month = ((date->year % 4 == 0 && date->year % 100 != 0) || date->year % 400 == 0) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            days_in_month = 30;
            break;
        default:
            days_in_month = 31;
    }
    
    return date->day <= days_in_month;
}

int main() {
    CompactDate birthday = {15, 6, 1990};  // 15.06.1990
    
    printf("Размер структуры: %zu байт\n", sizeof(CompactDate));
    print_date(&birthday);
    
    if (is_date_valid(&birthday)) {
        printf("Дата корректна\n");
    } else {
        printf("Дата некорректна\n");
    }
    
    // Пример с некорректной датой
    CompactDate invalid = {31, 2, 2023};
    print_date(&invalid);
    if (!is_date_valid(&invalid)) {
        printf("Эта дата некорректна (в феврале не может быть 31 дня)\n");
    }
    
    return 0;
}