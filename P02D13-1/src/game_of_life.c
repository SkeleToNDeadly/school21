#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 80
#define HEIGHT 25

int** alloc_matrix(int n, int m);
void draw_field(int** matrix, int n, int m);
int update_field(int** matrix, int** buffer, int n, int m);
int check(int** matrix, int i, int j);
void get_indeces(int* i, int* j);
void insert_into_field(int** matrix, int in_i, int in_j, int insertion[3][3], int n, int m);
int input(int** matrix, int n, int m);

int main() {
    int flag = 1;
    int** field = NULL;
    int** buffer = NULL;
    field = alloc_matrix(HEIGHT, WIDTH);
    buffer = alloc_matrix(HEIGHT, WIDTH);
    if (input(field, HEIGHT, WIDTH) != HEIGHT * WIDTH) flag = 0;
    initscr();
    FILE* stream = freopen("/dev/tty", "rw", stdin);
    if (!stream) flag = 0;
    nodelay(stdscr, TRUE);
    int speed = 1;
    while (flag) {
        char delay = getch();
        if ((char)delay >= '1' && (char)delay <= '9') {
            speed = delay - '0';
        }
        draw_field(field, HEIGHT, WIDTH);
        printw("%d\n", delay);
        if (!update_field(field, buffer, HEIGHT, WIDTH)) flag = 0;
        int** tmp = field;
        field = buffer;
        buffer = tmp;
        usleep(100000 / speed);
    }

    if (field) free(field);
    if (buffer) free(buffer);
    endwin();
}

int** alloc_matrix(int n, int m) {
    int** result = (int**)malloc(n * sizeof(int*) + n * m * sizeof(int));
    if (result)
        for (int i = 0; i < n; i++) result[i] = (int*)(result + n) + i * m;
    return result;
}

void draw_field(int** matrix, int n, int m) {
    clear();
    for (int i = 0; i <= WIDTH + 1; i++) {
        printw("=");
    }
    printw("\n");
    for (int i = 0; i < n; i++) {
        printw("|");
        for (int j = 0; j < m; j++) {
            if (matrix[i][j])
                printw("#");
            else
                printw(" ");
        }
        printw("|");
        printw("\n");
    }

    for (int i = 0; i <= WIDTH + 1; i++) {
        printw("=");
    }
    printw("\n");
}

int update_field(int** matrix, int** buffer, int n, int m) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            buffer[i][j] = check(matrix, i, j);
            if (buffer[i][j]) result = 1;
        }
    }

    return result;
}
int check(int** matrix, int i, int j) {
    int count = 0;
    int result = 0;
    int tmpi;
    int tmpj;
    for (int ii = -1; ii <= 1; ii++) {
        for (int jj = -1; jj <= 1; jj++) {
            tmpi = i + ii;
            tmpj = j + jj;
            get_indeces(&tmpi, &tmpj);
            count += matrix[tmpi][tmpj];
        }
    }
    count -= matrix[i][j];
    if (matrix[i][j]) {
        if (count >= 2 && count <= 3) result = 1;
    } else if (count == 3) {
        result = 1;
    }
    return result;
}
void get_indeces(int* i, int* j) {
    if (*i < 0)
        *i = HEIGHT - 1;
    else if (*i >= HEIGHT)
        *i = 0;
    if (*j < 0)
        *j = WIDTH - 1;
    else if (*j >= WIDTH)
        *j = 0;
}

int input(int** matrix, int n, int m) {
    int result = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &tmp)) {
                matrix[i][j] = tmp;
                result++;
            }
        }
    }
    return result;
}
