CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

default: all

print_module:
	gcc main_module_entry_point.c print_module.c -o ../build/Quest_1 -D PRINT_MODULE

documentation_module:
	gcc main_module_entry_point.c documentation_module.c -o ../build/Quest_2 -D DOCUMENTATION_MODULE

bst_create_test:
	gcc bst_create_test.c bst.c -o ../build/Quest_3

bst_insert_test:
	gcc bst_insert_test.c bst.c -o ../build/Quest_4

bst_traverse_test:
	gcc bst_traverse_test.c bst.c -o ../build/Quest_5

clean:
	rm ../build/Quest_1
	rm ../build/Quest_2
	rm ../build/Quest_3
	rm ../build/Quest_4
	rm ../build/Quest_5

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
