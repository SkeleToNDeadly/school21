#ifndef LIST_H
#define LIST_H
#include "door_struct.h" // Подключаем определение структуры door из предыдущего задания

// Структура узла односвязного списка
struct node {
    struct door data;
    struct node* next;
};

// Инициализация списка на базе переданной структуры двери
struct node* init(const struct door* door);

// Вставка нового элемента в список после переданного узла
struct node* add_door(struct node* elem, const struct door* door);

// Поиск двери в списке по её id
struct node* find_door(int door_id, struct node* root);

// Удаление элемента из списка
struct node* remove_door(struct node* elem, struct node* root);

// Освобождение памяти, занимаемой списком
void destroy(struct node* root);

#endif 
 
