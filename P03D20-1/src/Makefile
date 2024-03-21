CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
BUILD=../build/

all: graph

graph: stack.o parsing.o calculating.o drawing.o graph.o
	$(CC) $(CFLAGS) stack.o graph.o parsing.o drawing.o calculating.o -o $(BUILD)graph

calculating.o: calculating.c calculating.h
	$(CC) $(CFLAGS)	calculating.c -c

drawing.o:
	$(CC) $(CFLAGS)	drawing.c -c

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c -c

parsing.o: parsing.c
	$(CC) $(CFLAGS) parsing.c -c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c -c

clean:
	rm -rf *.o $(BUILD)graph

rebuild: clean all
