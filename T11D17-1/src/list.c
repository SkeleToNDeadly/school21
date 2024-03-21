#include "list.h"

#include <stdlib.h>

struct node* init(const struct door* door) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode) {
        newNode->data = *door;
        newNode->next = NULL;
    }
    return newNode;
}

struct node* add_door(struct node* elem, const struct door* door) {
    if (!elem) return NULL;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode) {
        newNode->data = *door;
        newNode->next = elem->next;
        elem->next = newNode;
    }
    return newNode;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->data.id == door_id) return current;
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (!root || !elem) return NULL;
    struct node* current = root;
    if (current == elem) {
        root = elem->next;
        free(elem);
        return root;
    }
    while (current->next && current->next != elem) {
        current = current->next;
    }
    if (current->next) {
        current->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}
