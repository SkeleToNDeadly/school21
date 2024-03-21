CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
door_struct: dmanager_module.o
	$(CC) $(CFLAGS) -o ../build/Quest_1 dmanager_module.o

dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) -c dmanager_module.c

list_test: list_test.o list.o
	$(CC) $(CFLAGS) -o ../build/Quest_2 list_test.o list.o

list_test.o: list_test.c list.h
	$(CC) $(CFLAGS) -c list_test.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) -o ../build/Quest_3 stack_test.o stack.o

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) -c stack_test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
clean:
	rm -rf *.o
	rm -rf ../build/Quest_1
	rm -rf ../build/Quest_2
	rm -rf ../build/Quest_3
