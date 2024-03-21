#include "logger.h"

#include <stdlib.h>
// Инициализация логгера
FILE* log_init(const char* filename) {
    FILE* logfile = fopen(filename, "a");
    if (!logfile) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    return logfile;
}

// Запись сообщения в лог
void logcat(FILE* logfile, const char* message, LogLevel level) {
    const char* level_str;
    switch (level) {
        case DEBUG:
            level_str = "DEBUG";
            break;
        case INFO:
            level_str = "INFO";
            break;
        case WARNING:
            level_str = "WARNING";
            break;
        case ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
    }

    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(logfile, "[%s] %s: %s\n", level_str, asctime(timeinfo), message);
}

// Закрытие лога
void log_close(FILE* logfile) { fclose(logfile); }
