#include "stack.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int main() {
    // Тестирование функции push и pop

    struct node* stack = init();
    int data;

    // Проверка попытки извлечения из пустого стека
    if (pop(&stack, &data) != 0) {
        printf("FAIL");
        return FAIL;
    }

    // Добавляем элементы в стек
    if (!push(&stack, 10)) {
        printf("FAIL");
        return FAIL;
    }
    if (!push(&stack, 20)) {
        printf("FAIL");
        return FAIL;
    }

    // Проверяем извлечение элементов из стека
    if (pop(&stack, &data) != 1 || data != 20) {
        printf("FAIL");
        return FAIL;
    }
    if (pop(&stack, &data) != 1 || data != 10) {
        printf("FAIL");
        return FAIL;
    }

    // Проверка попытки извлечения из пустого стека после извлечения всех элементов
    if (pop(&stack, &data) != 0) {
        printf("FAIL");
        return FAIL;
    }

    printf("SUCCESS");
    destroy(stack);
    return SUCCESS;
}
