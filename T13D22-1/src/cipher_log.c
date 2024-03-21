#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"  // Включаем заголовочный файл логгера

#define MAX_PATH_LENGTH 100
#define BUFFER_SIZE 200

// Декларируем функции логгера
void log_cipher_init();
void log_cipher_action(const char* action);

int read_file(char* path, FILE* logfile);
int write_file(char* path, char* text, FILE* logfile);
int caesar_encrypt(char* path, int offset, FILE* logfile);
int des_encrypt(char* path, char key, FILE* logfile);

int main() {
    log_cipher_init();  // Инициализация логгера
    FILE* logfile = fopen("cipher.log", "a");

    char file_path[MAX_PATH_LENGTH];
    int mode = 0;
    int encoding_offset;
    char encoding_key;

    while (1) {
        printf("Enter mode: ");
        scanf("%d", &mode);
        while (getchar() != '\n')
            ;
        if (mode == 1) {
            log_cipher_action("Reading file");
            printf("Enter file path: ");
            scanf("%s", file_path);
            read_file(file_path, logfile);
        } else if (mode == 2) {
            log_cipher_action("Writing to file");
            printf("Enter file path: ");
            scanf("%s", file_path);
            char text[BUFFER_SIZE];
            printf("Enter a string: ");
            getchar();  // Consume the newline character left in the buffer
            fgets(text, sizeof(text), stdin);
            write_file(file_path, text, logfile);
            read_file(file_path, logfile);
        } else if (mode == 3) {
            log_cipher_action("Caesar encryption");
            printf("Enter file path: ");
            scanf("%s", file_path);
            printf("Enter encoding offset: ");
            scanf("%d", &encoding_offset);
            if (caesar_encrypt(file_path, encoding_offset, logfile)) break;
        } else if (mode == 4) {
            log_cipher_action("DES encryption");
            printf("Enter file path: ");
            scanf("%s", file_path);
            printf("Enter DES key: ");
            scanf(" %c", &encoding_key);
            if (des_encrypt(file_path, encoding_key, logfile)) {
                break;
            }
        } else if (mode == -1) {
            break;
        } else {
            printf("n/a\n");
            logcat(logfile, "Error: Unknown mode", ERROR);
        }
    }

    logcat(logfile, "Exit", INFO);
    log_close(logfile);
    return 0;
}

int read_file(char* path, FILE* logfile) {
    // Логирование чтения файла
    logcat(logfile, "Reading file", INFO);

    FILE* file;
    file = fopen(path, "r");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);  // Переходим в конец файла
        long size = ftell(file);   // Получаем текущую позицию (размер файла)
        if (size == 0) {
            printf("File is empty\n");
            logcat(logfile, "Error: File is empty", ERROR);
            fclose(file);
            return 0;
        }
        rewind(file);  // Возвращаемся в начало файла
        char buff[BUFFER_SIZE];
        while ((fgets(buff, sizeof(buff), file)) != NULL) printf("%s", buff);
        fclose(file);
        printf("\n");
        return 1;
    } else {
        printf("File not found\n");
        logcat(logfile, "Error: File not found", ERROR);
        return 0;
    }
}

int write_file(char* path, char* text, FILE* logfile) {
    // Логирование записи в файл
    logcat(logfile, "Writing to file", INFO);

    FILE* file;
    file = fopen(path, "a");
    if (file != NULL) {
        if (ftell(file) == 0) {
            printf("File is empty\n");
            logcat(logfile, "Error: File is empty", ERROR);
            fclose(file);
            return 0;
        }
        fprintf(file, "%s", text);
        fclose(file);
        return 1;
    } else {
        printf("File not found\n");
        logcat(logfile, "Error: File not found", ERROR);
        return 0;
    }
}

int caesar_encrypt(char* path, int offset, FILE* logfile) {
    // Логирование шифрования
    logcat(logfile, "Caesar encryption", INFO);

    FILE* file;
    char buff[BUFFER_SIZE];
    file = fopen(path, "r");
    if (file != NULL) {
        if (fseek(file, 0, SEEK_END) != 0) {
            printf("Error: Unable to seek to end of file\n");
            logcat(logfile, "Error: Unable to seek to end of file", ERROR);
            fclose(file);
            return 1;
        }
        long size = ftell(file);
        if (size == -1) {
            printf("Error: Unable to get file size\n");
            logcat(logfile, "Error: Unable to get file size", ERROR);
            fclose(file);
            return 1;
        }
        if (size == 0) {
            printf("File is empty\n");
            fclose(file);
            return 1;
        }
        rewind(file);
        while (fgets(buff, sizeof(buff), file) != NULL) {
            for (size_t i = 0; i < strlen(buff); i++) {
                if (buff[i] >= 'a' && buff[i] <= 'z') {
                    buff[i] = ((buff[i] - 'a' + offset) % 26) + 'a';
                } else if (buff[i] >= 'A' && buff[i] <= 'Z') {
                    buff[i] = ((buff[i] - 'A' + offset) % 26) + 'A';
                }
            }
            printf("%s", buff);
        }
        fclose(file);
        return 0;
    } else {
        printf("File not found\n");
        logcat(logfile, "Error: File not found", ERROR);
        return 1;
    }
}

int des_encrypt(char* path, char key, FILE* logfile) {
    // Логирование DES шифрования
    logcat(logfile, "DES encryption", INFO);

    FILE* file;
    char buff[BUFFER_SIZE];
    file = fopen(path, "r+");
    if (file != NULL) {
        if (fseek(file, 0, SEEK_END) != 0) {
            printf("Error: Unable to seek to end of file\n");
            logcat(logfile, "Error: Unable to seek to end of file", ERROR);
            fclose(file);
            return 1;
        }
        long size = ftell(file);
        if (size == -1) {
            printf("Error: Unable to get file size\n");
            logcat(logfile, "Error: Unable to get file size", ERROR);
            fclose(file);
            return 1;
        }
        if (size == 0) {
            printf("File is empty\n");
            fclose(file);
            return 1;
        }
        rewind(file);
        while (fgets(buff, sizeof(buff), file) != NULL) {
            for (size_t i = 0; i < strlen(buff); i++) {
                buff[i] = buff[i] ^ key;
            }
            printf("%s", buff);
        }
        fclose(file);
        return 0;
    } else {
        printf("File not found\n");
        logcat(logfile, "Error: File not found", ERROR);
        return 1;
    }
}

// Инициализация логгера
void log_cipher_init() {
    FILE* logfile = log_init("cipher.log");
    logcat(logfile, "Logging started", INFO);
    log_close(logfile);
}

// Запись действия в лог
void log_cipher_action(const char* action) {
    FILE* logfile = fopen("cipher.log", "a");
    logcat(logfile, action, INFO);
    fclose(logfile);
}
