#ifndef GRAPH_H_
#define GRAPH_H_

#define _USE_MATH_DEFINES
#define WIDTH 80
#define HEIGHT 25
#define POINT '.'
#define STAR '*'

char **calloc_matrix(int height, int width);
void graph_initing(char **graph, int height, int width);
void graph_drawing(char **graph, int height);
void free_matrix(char **graph, int height);

#endif  // GRAPH_H_
