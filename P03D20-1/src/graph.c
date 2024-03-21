#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculating.h"
#include "drawing.h"
#include "stack.h"

int main() {
    char **graph = calloc_matrix(HEIGHT, WIDTH + 1);
    struct st *operations = NULL;
    char in_str[80], out_str[80];
    fpurge(stdin);
    fgets(in_str, 80, stdin);
    parsing(operations, in_str, out_str);

    fpurge(stdin);
    HEAD head;
    init(&head);
    graph_initing(graph, HEIGHT, WIDTH);
    add_func_for_graph(graph, HEIGHT, WIDTH, out_str, &head);
    graph_drawing(graph, HEIGHT);
    free_matrix(graph, HEIGHT);
    return 0;
}
