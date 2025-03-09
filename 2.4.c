#include <stdio.h>

int main() {
    int num;

    while (1) {
        printf("Введите трёхзначное число: ");
        scanf("%d", &num);

        int sum = 0;
        int temp = num;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum <= 10) {
            break;
        }
    }

    return 0;
}