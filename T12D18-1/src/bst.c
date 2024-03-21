#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *first = malloc(sizeof(t_btree));
    first->item = item;
    first->left = (void *)0;
    first->right = (void *)0;
    return first;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (cmpf(item, root->item)) {
        if (root->left)
            bstree_insert(root->left, item, cmpf);
        else
            root->left = bstree_create_node(item);
    } else {
        if (root->right)
            bstree_insert(root->right, item, cmpf);
        else
            root->right = bstree_create_node(item);
    }
}

void bstree_delete(t_btree *root) {
    if (root->left) bstree_delete(root->left);
    if (root->right) bstree_delete(root->right);
    free(root);
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left) bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    if (root->right) bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->item);
    if (root->left) bstree_apply_infix(root->left, applyf);
    if (root->right) bstree_apply_infix(root->right, applyf);
}
void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->left) bstree_apply_infix(root->left, applyf);
    if (root->right) bstree_apply_infix(root->right, applyf);
    applyf(root->item);
}