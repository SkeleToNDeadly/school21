#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/stat_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    scanf("%d", &n);

    data = calloc(n, sizeof(double));
    input(data, n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    return 0;
}
