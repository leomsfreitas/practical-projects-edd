CC = gcc
CFLAGS = -Wall -Wextra -g

all: main_program

main_program: main.o ordered_list.o
	$(CC) $(CFLAGS) -o main_program main.o ordered_list.o

main.o: main.c ordered_list.h
	$(CC) $(CFLAGS) -c main.c

ordered_list.o: ordered_list.c ordered_list.h
	$(CC) $(CFLAGS) -c ordered_list.c

clean:
	rm -f *.o main_program