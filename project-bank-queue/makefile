CC = gcc
CFLAGS = -Wall -Wextra -g

all: main_program

main_program: main.o bank_queue.o t_queue.o
	$(CC) $(CFLAGS) -o main_program main.o bank_queue.o t_queue.o

main.o: main.c bank_queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

bank_queue.o: bank_queue.c bank_queue.h t_queue.h
	$(CC) $(CFLAGS) -c -o bank_queue.o bank_queue.c

t_queue.o: t_queue.c t_queue.h
	$(CC) $(CFLAGS) -c -o t_queue.o t_queue.c

clean:
	rm -f main_program *.o
