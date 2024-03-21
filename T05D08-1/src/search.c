#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
int even(int *a, int *n);
double mean(int *a, int *n);
int sigm_follow(int *a, int *n);
void output(int result);

int main() {
    int data[NMAX];
    int n;

    // Input
    if (!input(data, &n)) {
        printf("n/a");
        return 1;
    }

    // Search for the desired value
    int result = even(data, &n);
    if (result == 0 || !sigm_follow(data, &n)) {
        result = 0;
    }

    // Output the result
    output(result);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;  // Invalid input
    }

    for (int i = 0; i < *n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;  // Invalid input
        }
    }

    return 1;  // Successful input
}

int even(int *a, int *n) {
    double avg = mean(a, n);

    for (int i = 0; i < *n; ++i) {
        if (a[i] % 2 == 0 && a[i] >= avg && a[i] != 0) {
            return a[i];
        }
    }

    return 0;  // No even number found
}

double mean(int *a, int *n) {
    double sum = 0;

    for (int i = 0; i < *n; ++i) {
        sum += a[i];
    }

    return sum / *n;
}

int sigm_follow(int *a, int *n) {
    double variance = 0;
    double m = mean(a, n);

    for (int i = 0; i < *n; ++i) {
        variance += pow(a[i] - m, 2);
    }

    double stddev = sqrt(variance / *n);

    for (int i = 0; i < *n; ++i) {
        if (a[i] > m + 3 * stddev) {
            return 0;  // Violation of three-sigma rule
        }
    }

    return 1;  // All values follow three-sigma rule
}

void output(int result) { printf("%d", result); }
