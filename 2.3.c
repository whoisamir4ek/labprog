#include <stdio.h>

int main() {
    int m;

    printf("Введите число m: ");
    scanf("%d", &m);

    int P[100];

    P[0] = 1;
    P[1] = 1;
    P[2] = 1;

    printf("%d ", P[0]);
    if (m >= 1) printf("%d ", P[1]);
    if (m >= 1) printf("%d ", P[2]);

    for (int n = 3; ; n++) {
        P[n] = P[n - 2] + P[n - 3];

        if (P[n] > m) {
            break;
        }

        printf("%d ", P[n]);
    }

    printf("\n");

    return 0;
}