#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int check_and_print(int condition) {
    if (condition)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    return condition;
}

int compare(int a, int b) { return a < b; }

int reverse_compare(int a, int b) { return a > b; }

void test_insert() {
    t_btree* infernis_canina = bstree_create_node(10);
    bstree_insert(infernis_canina, 5, &compare);
    bstree_insert(infernis_canina, 15, &compare);
    printf("[%d] - %d - [%d]\n", infernis_canina->left->item, infernis_canina->item,
           infernis_canina->right->item);
    if ((infernis_canina->left->item == 5) && (infernis_canina->item == 10) &&
        (infernis_canina->right->item == 15))
        puts("SUCCESS");
    else
        puts("FAIL");
    bstree_delete(infernis_canina);
    infernis_canina = bstree_create_node(10);
    bstree_insert(infernis_canina, 5, &reverse_compare);
    bstree_insert(infernis_canina, 15, &reverse_compare);
    printf("[%d] - %d - [%d]\n", infernis_canina->left->item, infernis_canina->item,
           infernis_canina->right->item);
    if ((infernis_canina->left->item == 15) && (infernis_canina->item == 10) &&
        (infernis_canina->right->item == 5))
        puts("SUCCESS");
    else
        puts("FAIL");
    bstree_delete(infernis_canina);
}

int main() {
    test_insert();
    return 0;
}