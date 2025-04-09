#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define NUM_BOOKS 3

typedef struct {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int year;
} Book;

void printBook(const Book *book) {
    printf("Название: %s\n", book->title);
    printf("Автор: %s\n", book->author);
    printf("Год издания: %d\n\n", book->year);
}

int main() {
    Book books[NUM_BOOKS];

    for (int i = 0; i < NUM_BOOKS; i++) {
        printf("Введите данные о книге #%d:\n", i + 1);

        printf("Название: ");
        fgets(books[i].title, MAX_LENGTH, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Автор: ");
        fgets(books[i].author, MAX_LENGTH, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        do {
            printf("Год издания: ");
            while (scanf("%d", &books[i].year) != 1) {
                printf("Ошибка! Введите целое число: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            
            if (books[i].year <= 0) {
                printf("Год должен быть положительным числом! Попробуйте еще раз.\n");
            }
        } while (books[i].year <= 0);
    }

    printf("\nКаталог книг:\n");
    for (int i = 0; i < NUM_BOOKS; i++) {
        printBook(&books[i]);
    }

    return 0;
}