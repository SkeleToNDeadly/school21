#ifndef STACK_H
#define STACK_H

// Структура узла стека
struct node {
    int data;
    struct node* next;
};

// Инициализация стека
struct node* init();

// Добавление элемента в стек
int push(struct node** top, int data);

// Удаление элемента из стека
int pop(struct node** top, int* data);

// Освобождение памяти, занимаемой стеком
void destroy(struct node* top);

#endif
 
