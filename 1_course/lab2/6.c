#include <stdio.h>

int main() {
    int a = 1234567890;
    unsigned char * bptr = (unsigned char *)&a;
    printf("Побайтовый вывод переменной a (%d):\n", a);
    for (int i = 0; i < sizeof(a); i++) {
        printf("%p Байт %d: %d\n", bptr + i, i, *(bptr + i));
    }
}