NEW_PWD = ../../build/Quest_3
#NEW_PWD = ../../build/Quest_5
#NEW_PWD = ../../build/Quest_6

CF_CHECK = clang-format --style="{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}" -n
CF_APPLY = clang-format --style="{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}" -i
ROOT = ../..
GCCFLAGS = -Wall -Werror -Wextra -std=c11 -c
.PHONY: all clean rebuild format

format:
	$(CF_CHECK) $(ROOT)/src/data_module/*.c
	$(CF_CHECK) $(ROOT)/src/data_module/*.h
	$(CF_CHECK) $(ROOT)/src/data_libs/*.c
	$(CF_CHECK) $(ROOT)/src/data_libs/*.h
	$(CF_CHECK) $(ROOT)/src/main_executable_module/*.c
	$(CF_CHECK) $(ROOT)/src/yet_another_decision_module/*.c
	$(CF_CHECK) $(ROOT)/src/yet_another_decision_module/*.h
	$(CF_APPLY) $(ROOT)/src/data_module/*.c
	$(CF_APPLY) $(ROOT)/src/data_module/*.h
	$(CF_APPLY) $(ROOT)/src/data_libs/*.c
	$(CF_APPLY) $(ROOT)/src/data_libs/*.h
	$(CF_APPLY) $(ROOT)/src/main_executable_module/*.c
	$(CF_APPLY) $(ROOT)/src/yet_another_decision_module/*.c
	$(CF_APPLY) $(ROOT)/src/yet_another_decision_module/*.h

all: $(NEW_PWD)

$(NEW_PWD): main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	gcc -o $(NEW_PWD) main_executable_module.o data_io.o data_stat.o data_process.o decision.o
data_io.o: ../data_libs/data_io.c
	gcc $(GCCFLAGS) ../data_libs/data_io.c -o data_io.o
data_stat.o: ../data_libs/data_stat.c
	gcc $(GCCFLAGS) ../data_libs/data_stat.c -o data_stat.o
data_process.o: ../data_module/data_process.c
	gcc $(GCCFLAGS) ../data_module/data_process.c -o data_process.o
decision.o: ../yet_another_decision_module/decision.c
	gcc $(GCCFLAGS) ../yet_another_decision_module/decision.c -o decision.o
main_executable_module.o: main_executable_module.c
	gcc $(GCCFLAGS) main_executable_module.c -o main_executable_module.o
data_stat.a: data_stat.o
	ar rc libdata_stat.a data_stat.o
	ranlib libdata_stat.a
data_io_macro.so: ../data_libs/data_io_macro.h
	gcc $(GCCFLAGS) ../data_libs/data_io_macro.h -o data_io_macro.o
build_with_static: main_executable_module.o data_io.o data_stat.a data_process.o decision.o
	gcc  -o ../../build/Quest_5 main_executable_module.o data_io.o data_process.o decision.o -L. -ldata_stat
data_process.so: ../data_module/data_process.c data_stat.o
	gcc -fPIC $(GCCFLAGS) ../data_module/data_process.c
	gcc -shared -o libdata_process.so data_process.o data_stat.o
build_with_dynamic: main_executable_module.o data_io.o data_stat.o data_process.o decision.o data_process.so
	gcc main_executable_module.o data_io.o data_process.o decision.o  -L. -ldata_process -o ../../build/Quest_6

build_with_macro: data_io_macro.so main_executable_module.o data_stat.o data_process.o decision.o
	gcc main_executable_module.o data_stat.o data_process.o decision.o data_io_macro.o -o ../../build/Quest_4
clean:
	rm -rf *.o *.a *.so
	rm -rf  ../../build/Quest_3 
	rm -rf  ../../build/Quest_5
	rm -rf  ../../build/Quest_6
rebuild:
	make clean
	make all
