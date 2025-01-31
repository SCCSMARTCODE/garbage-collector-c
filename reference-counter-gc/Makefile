CC=gcc
CFLAGS=-Werror -Wextra -Wall

all: gc_program

gc_program: main.o gc.o
	$(CC) $(CFLAGS) -o gc_program main.o gc.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

gc.o: gc.c
	$(CC) $(CFLAGS) -c gc.c

clean:
	rm -f *.o gc_program
