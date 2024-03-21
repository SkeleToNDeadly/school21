#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

// Уровни логирования
typedef enum { DEBUG, INFO, WARNING, ERROR } LogLevel;

// Инициализация логгера
FILE* log_init(const char* filename);

// Запись сообщения в лог
void logcat(FILE* logfile, const char* message, LogLevel level);

// Закрытие лога
void log_close(FILE* logfile);

#endif /* LOGGER_H */
