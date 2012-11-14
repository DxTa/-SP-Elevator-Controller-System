CFLAGS = -c -Wall
CC = gcc
LIBS =  -lm

all: erun

erun: main.o data.o request.o elevator.o action.o error.o
	${CC} main.o data.o request.o elevator.o action.o error.o -o erun

main.o: main.c
	${CC} ${CFLAGS} main.c

data.o: data.c
	${CC} ${CFLAGS} data.c

request.o: request.c
	${CC} ${CFLAGS} request.c

elevator.o: elevator.c
	${CC} ${CFLAGS} elevator.c

action.o: action.c
	${CC} ${CFLAGS} action.c

error.o: error.c
	${CC} ${CFLAGS} error.c

clean:
	rm -f *.o *~
