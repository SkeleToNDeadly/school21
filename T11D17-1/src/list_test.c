#include "list.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int main() {
    // Тестирование функции add_door

    struct door door1 = {1, 0};  // Пример двери для теста
    struct node* list = init(&door1);

    // Добавляем новую дверь
    struct door door2 = {2, 1};  // Дверь для добавления
    add_door(list, &door2);

    // Проверяем, что дверь добавлена успешно
    struct node* addedDoor = find_door(2, list);
    if (addedDoor == NULL) {
        printf("FAIL");
        destroy(list);
        return FAIL;
    }

    // Тестирование функции remove_door

    // Удаляем добавленную дверь
    list = remove_door(addedDoor, list);

    // Проверяем, что дверь удалена успешно
    struct node* removedDoor = find_door(2, list);
    if (removedDoor != NULL) {
        printf("FAIL");
        destroy(list);
        return FAIL;
    }

    printf("SUCCESS");
    destroy(list);
    return SUCCESS;
}
