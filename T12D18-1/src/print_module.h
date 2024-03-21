#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

/*
    input:  printchar-callback, log message
    output: void
    result: "Log_prefix HH:MM:SS message"
*/

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    char *tm_zone;
};

long unsigned int
infernis_canina(char *restrict s, long unsigned int max, const char *restrict format, const struct tm *restrict _tm) __asm(
    "_"
    "strftime");

long time(long *);
struct tm *localtime(const long *_time);

void print_log(char (*print)(char), char *message);

char print_char(char ch);

#endif  // PRINT_MODULE_H
