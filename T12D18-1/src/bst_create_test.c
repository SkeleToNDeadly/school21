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

void test_create() {
    t_btree* plaga_rectalis = bstree_create_node(10);
    printf("Created tree with first node %d\n", plaga_rectalis->item);
    check_and_print(plaga_rectalis->item == 10);
    free(plaga_rectalis);
    plaga_rectalis = bstree_create_node(-4);
    printf("Created tree with first node %d\n", plaga_rectalis->item);
    check_and_print(plaga_rectalis->item == -4);
    free(plaga_rectalis);
}

int main() {
    test_create();
    return 0;
}