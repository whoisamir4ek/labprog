#include <stdio.h>
#include <stdlib.h>

// Элемент списка
struct Node {
    int value;          // Значение
    struct Node* prev;  // Предыдущий элемент
    struct Node* next;  // Следующий элемент
};

// Создать новый элемент
struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->value = val;
    n->prev = n->next = NULL;
    return n;
}

// Добавить в конец списка
void add(struct Node** head, struct Node** tail, int val) {
    struct Node* n = create(val);
    
    if (*head == NULL) {
        *head = *tail = n;
    } else {
        (*tail)->next = n;
        n->prev = *tail;
        *tail = n;
    }
}

// Печать списка вперед
void print_forward(struct Node* head) {
    printf("Вперед: ");
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// Печать списка назад
void print_backward(struct Node* tail) {
    printf("Назад: ");
    while (tail) {
        printf("%d ", tail->value);
        tail = tail->prev;
    }
    printf("\n");
}

// Очистить память
void clear(struct Node* head) {
    while (head) {
        struct Node* t = head;
        head = head->next;
        free(t);
    }
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    
    add(&head, &tail, 10);
    add(&head, &tail, 20);
    add(&head, &tail, 30);
    
    print_forward(head);
    print_backward(tail);
    
    clear(head);
    return 0;
}