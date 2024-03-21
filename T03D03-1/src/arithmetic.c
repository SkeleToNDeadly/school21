
#include <stdio.h>

int main() {
    float a, b;
    printf("Введите два целых числа: ");
    scanf("%f %f", &a, &b);
    if ((a == (float)(int)a) && (b == (float)(int)b)) {
        int sum = a + b;
        int diff = a - b;
        int mul = a * b;
        if (b != 0) {
            int div = ((int)a) / ((int)b);
            printf("%d %d %d %d", sum, diff, mul, div);
        } else {
            printf("%d %d %d n/a", sum, diff, mul);
        }
    } else {
        printf("n/a");
    }

    return 0;
}
