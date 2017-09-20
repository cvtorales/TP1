CC=gcc
CFLAGS=-Wall -ansi -pedantic -O3 -c -lm
LFLAGS=-Wall
DEBUG=-g

all: calculator

calculator: main.o functions.o 
	$(CC) $(LFLAGS) $(DEBUG) -o calculator main.o functions.o
main.o: main.c idioma.h functions.h
	$(CC) $(CFLAGS) $(DEBUG) -o main.o main.c

function.o: functions.c functions.h idioma.h
	$(CC) $(CFLAGS) $(DEBUG) -o functions.o functions.c


functions.h: common.h

clean:
	rm *.o
