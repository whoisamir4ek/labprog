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
