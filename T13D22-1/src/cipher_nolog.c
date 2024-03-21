#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATH_LENGTH 100
#define BUFFER_SIZE 200

int read_file(char* path);
int write_file(char* path, char* text);
int caesar_encrypt(char* path, int offset);
int des_encrypt(char* path, char key);

int main() {
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
            printf("Enter file path: ");
            scanf("%s", file_path);
            read_file(file_path);
        } else if (mode == 2) {
            printf("Enter file path: ");
            scanf("%s", file_path);
            char text[BUFFER_SIZE];
            printf("Enter a string: ");
            getchar();  // Consume the newline character left in the buffer
            fgets(text, sizeof(text), stdin);
            write_file(file_path, text);
            read_file(file_path);
        } else if (mode == 3) {
            printf("Enter file path: ");
            scanf("%s", file_path);
            printf("Enter encoding offset: ");
            scanf("%d", &encoding_offset);
            if (caesar_encrypt(file_path, encoding_offset)) break;
        } else if (mode == 4) {
            printf("Enter file path: ");
            scanf("%s", file_path);
            printf("Enter DES key: ");
            scanf(" %c", &encoding_key);
            if (des_encrypt(file_path, encoding_key)) {
                break;
            }
        } else if (mode == -1) {
            break;
        } else {
            printf("n/a\n");
        }
    }
    return 0;
}

int read_file(char* path) {
    FILE* file;
    file = fopen(path, "r");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);  // Переходим в конец файла
        long size = ftell(file);   // Получаем текущую позицию (размер файла)
        if (size == 0) {
            printf("n/a\n");
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
        printf("n/a\n");
        return 0;
    }
}

int write_file(char* path, char* text) {
    FILE* file;
    file = fopen(path, "a");
    if (file != NULL) {
        if (ftell(file) == 0) {
            printf("n/a\n");
            fclose(file);
            return 0;
        }
        fprintf(file, "%s", text);
        fclose(file);
        return 1;
    } else {
        printf("n/a\n");
        return 0;
    }
}

int caesar_encrypt(char* path, int offset) {
    // Логирование шифрования

    FILE* file;
    char buff[BUFFER_SIZE];
    file = fopen(path, "r+");
    if (file != NULL) {
        if (ftell(file) == 0) {
            printf("n/a\n");
            fclose(file);
            return 1;  // Просто завершаем выполнение функции
        }
        while (fgets(buff, sizeof(buff), file) != NULL) {
            for (size_t i = 0; i < strlen(buff); i++) {
                if (buff[i] >= 'a' && buff[i] <= 'z') {
                    buff[i] = ((buff[i] - 'a' + offset) % 26) + 'a';
                } else if (buff[i] >= 'A' && buff[i] <= 'Z') {
                    buff[i] = ((buff[i] - 'A' + offset) % 26) + 'A';
                }
            }
            fseek(file, -strlen(buff), SEEK_CUR);
            fputs(buff, file);
        }
        fclose(file);
        return 0;
    } else {
        printf("n/a\n");
        return 1;
    }
}

int des_encrypt(char* path, char key) {
    // Логирование DES шифрования

    FILE* file;
    char buff[BUFFER_SIZE];
    file = fopen(path, "r+");
    if (file != NULL) {
        if (ftell(file) == 0) {
            printf("n/a\n");
            fclose(file);
            return 1;  // Просто завершаем выполнение функции
        }
        while (fgets(buff, sizeof(buff), file) != NULL) {
            for (size_t i = 0; i < strlen(buff); i++) {
                buff[i] = buff[i] ^ key;
            }
            fseek(file, -strlen(buff), SEEK_CUR);
            fputs(buff, file);
        }
        fclose(file);
        return 0;
    } else {
        printf("n/a\n");
        return 1;
    }
}
