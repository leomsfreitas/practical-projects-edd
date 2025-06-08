CC = gcc
CFLAGS = -Wall -Wextra -g

all: main_program

main_program: main.o nr_quicksort.o t_stack.o
	$(CC) $(CFLAGS) -o main_program main.o nr_quicksort.o t_stack.o

main.o: main.c nr_quicksort.h t_stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

nr_quicksort.o: nr_quicksort.c nr_quicksort.h t_stack.h
	$(CC) $(CFLAGS) -c -o nr_quicksort.o nr_quicksort.c

t_stack.o: t_stack.c t_stack.h
	$(CC) $(CFLAGS) -c -o t_stack.o t_stack.c

clean:
	rm -f main_program *.o
