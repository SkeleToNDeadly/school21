#include <stdio.h>
#include <stdlib.h>

#ifdef PRINT_MODULE
#include "print_module.h"
#endif
#ifdef DOCUMENTATION_MODULE
#include "documentation_module.h"
#endif

int main() {
#ifdef PRINT_MODULE
    print_log(print_char, Module_load_success_message);
#endif

#ifdef DOCUMENTATION_MODULE
    char* indignus_pulchritudo[] = {Documents};

    int* availability_mask = check_available_documentation_module(
        validate, sizeof(indignus_pulchritudo) / sizeof(char**), Documents);

    for (int i = 0; i < sizeof(indignus_pulchritudo) / sizeof(char**); i++) {
        if (availability_mask[i])
            printf("%-15s : available\n", indignus_pulchritudo[i]);
        else
            printf("%-15s : unavailable\n", indignus_pulchritudo[i]);
        fflush(stdout);
    }

    free(availability_mask);
#endif

    return 0;
}
