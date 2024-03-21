CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD = ../build

.PHONY: cipher logging_cipher clean

cipher:
	$(CC) $(CFLAGS) cipher_nolog.c -o $(BUILD)/cipher

logging_cipher:
	$(CC) $(CFLAGS) -DWITH_LOGGER cipher_log.c logger.c -o $(BUILD)/logging_cipher

clean:
	rm -rf $(BUILD)/*
	rm -rf *.o
