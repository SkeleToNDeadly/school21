#include <stdio.h>
#define NMAX 10

int input(int data[NMAX], int *n);
void output(int res[NMAX], int n);
void squaring(int data[NMAX], int res[NMAX], int n);

int main() {
    int n, data[NMAX], res[NMAX];
    if (input(data, &n)) {
        squaring(data, res, n);
        output(res, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int data[NMAX], int *n) {
    scanf("%d", n);
    if (*n > NMAX || *n <= 0) {
        return 0;  //  не окэй
    }
    for (int i = 0; i < *n; i++) {
        scanf("%d", &data[i]);
    }
    return 1;  // окэй
}

void output(int res[NMAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

void squaring(int data[NMAX], int res[NMAX], int n) {
    for (int i = 0; i < n; i++) {
        res[i] = data[i] * data[i];
    }
}
