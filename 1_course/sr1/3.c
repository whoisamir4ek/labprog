#include <stdio.h>

enum Season {
    WINTER,
    SPRING,
    SUMMER,
    AUTUMN
};

int main() {
    int month;
    enum Season season;
    const char *season_names[] = {"Зима", "Весна", "Лето", "Осень"};

    do {
        printf("Введите номер месяца (1-12): ");
        scanf("%d", &month);
        
        if (month < 1 || month > 12) {
            printf("Ошибка! Месяц должен быть от 1 до 12.\n");
        }
    } while (month < 1 || month > 12);

    switch (month) {
        case 12:
        case 1:
        case 2:
            season = WINTER;
            break;
        case 3:
        case 4:
        case 5:
            season = SPRING;
            break;
        case 6:
        case 7:
        case 8:
            season = SUMMER;
            break;
        case 9:
        case 10:
        case 11:
            season = AUTUMN;
            break;
    }

    printf("Сезон: %s\n", season_names[season]);

    return 0;
}