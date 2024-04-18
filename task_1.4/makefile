CC = gcc

all: clean program 

program: sum max_value
	$(CC) -c main.c -o main.o -g
	$(CC) main.o -o program
	-rm -f main.o

sum:
	$(CC) -c sum.c -o sum.o
	$(CC) sum.o -o sum
	-rm -f sum.o

max_value:
	$(CC) -c max_value.c -o max_value.o
	$(CC) max_value.o -o max_value
	-rm -f max_value.o

clean:
	-rm -rf *.o program a.out sum max_value