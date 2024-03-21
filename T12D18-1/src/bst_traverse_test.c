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

void apply(int a) { printf("%d ", a); }

void test_traverse() {
    t_btree* indignus_pulchritudo = bstree_create_node(10);
    bstree_insert(indignus_pulchritudo, 5, &compare);
    bstree_insert(indignus_pulchritudo, 2, &compare);
    bstree_insert(indignus_pulchritudo, 15, &compare);
    bstree_insert(indignus_pulchritudo, 20, &compare);
    printf("infix:   ");
    bstree_apply_infix(indignus_pulchritudo, &apply);
    putchar('\n');
    printf("prefix:  ");
    bstree_apply_prefix(indignus_pulchritudo, &apply);
    putchar('\n');
    printf("postfix: ");
    bstree_apply_postfix(indignus_pulchritudo, &apply);
    putchar('\n');
    bstree_delete(indignus_pulchritudo);
}

int main() {
    test_traverse();
    return 0;
}