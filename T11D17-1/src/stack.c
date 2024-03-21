#include "stack.h"

#include <stdlib.h>

struct node* init() {
    return NULL;
}

int push(struct node** top, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) return 0;  // Ошибка при выделении памяти
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    return 1;  // Успешное добавление
}

int pop(struct node** top, int* data) {
    if (*top == NULL) return 0;  // Стек пуст
    struct node* temp = *top;
    *data = temp->data;
    *top = (*top)->next;
    free(temp);
    return 1;  // Успешное удаление
}

void destroy(struct node* top) {
    while (top != NULL) {
        struct node* temp = top;
        top = top->next;
        free(temp);
    }
}
