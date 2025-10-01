#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "A1b2 C3!";

    for (int i = 0; str[i] != '\0'; i++) {
        printf("Символ '%c':\n", str[i]);
        if (isalpha(str[i])) {
            printf("  Это буква.\n");
        }
        if (isdigit(str[i])) {
            printf("  Это цифра.\n");
        }
        if (isspace(str[i])) {
            printf("  Это пробельный символ.\n");
        }
        if (ispunct(str[i])) {
            printf("  Это символ пунктуации.\n");
        }
    }

    return 0;
}
