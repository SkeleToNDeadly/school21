#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    if (document_count >= Documents_count) return (void*)0;
    va_list ap;
    int* result = malloc(sizeof(int) * document_count);
    va_start(ap, document_count);
    for (int i = 0; i < document_count; i++) result[i] = validate(va_arg(ap, char*));
    va_end(ap);
    return result;
}