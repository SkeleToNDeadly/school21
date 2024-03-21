#include "print_module.h"

#include <stdio.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    for (int i = 0; i < sizeof(Log_prefix) / sizeof(char); i++) print(Log_prefix[i]);
    print(' ');
    char _log_time[9];
    long now = time(0);
    infernis_canina(_log_time, 9, "%H:%M:%S", localtime(&now));
    for (int i = 0; i < 8; i++) print(_log_time[i]);
    print(' ');
    while (*message) print(*(message++));
}