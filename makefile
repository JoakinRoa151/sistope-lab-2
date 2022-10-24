FLAGS = -Wall -lm

main: main.c hijo.o padre.o
	gcc $(FLAGS) -o main main.c hijo.o padre.o

hijo.o: hijo.c
	gcc -c $(FLAGS) hijo.c

padre.o: padre.c
	gcc -c $(FLAGS) padre.c

clear:
	rm -f *.o main
