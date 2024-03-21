#include <math.h>
#include <stdio.h>

double calculate_function(double x) {
    return 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
}

int main() {
    double x;

    // Ввод значения x
    printf("Введите значение x: ");
    if (scanf("%lf", &x) == 1) {
        double result = calculate_function(x);
        printf("%.1f\n", result);

    } else {
        printf("n/a");
        return -1;
    }
    return 0;
}
