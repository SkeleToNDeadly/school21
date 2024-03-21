#include <stdio.h>

int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else if (a == b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int a, b;
    printf("Введите два целых числа: ");
    if (scanf("%d %d", &a, &b) == 2 && (a == (double)(int)a) && (b == (double)(int)b)) {
        int max = findMax(a, b);
        printf("Наибольшее число: %d", max);
    } else {
        printf("n/a");
    }

    return 0;
}
