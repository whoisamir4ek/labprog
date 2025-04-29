#include <stdio.h>

// Определение перечислимого типа для дней недели
enum WeekDays {
    MONDAY,    // 0
    TUESDAY,   // 1
    WEDNESDAY, // 2
    THURSDAY,  // 3
    FRIDAY,    // 4
    SATURDAY,  // 5
    SUNDAY     // 6
};

int main() {
    // Печать всех значений перечисления как целых чисел
    printf("Дни недели как целые числа:\n");
    printf("Понедельник: %d\n", MONDAY);
    printf("Вторник:     %d\n", TUESDAY);
    printf("Среда:       %d\n", WEDNESDAY);
    printf("Четверг:     %d\n", THURSDAY);
    printf("Пятница:     %d\n", FRIDAY);
    printf("Суббота:     %d\n", SATURDAY);
    printf("Воскресенье: %d\n", SUNDAY);

    return 0;
}