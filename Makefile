CC = gcc
CCFLAGS = -Wall -g

all : main


list.o: list.c list.h pokemon.h
	${CC} ${CCFLAGS} -c list.c

pokedex.o: pokedex.c pokedex.h pokemon.h list.h
	${CC} ${CCFLAGS} -c pokedex.c

combat.o: combat.c pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c combat.c

joueur.o: joueur.c combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c joueur.c

ia.o: ia.c joueur.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c ia.c

main.o: main.c ia.h joueur.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c main.c 

main: main.o ia.o joueur.o combat.o pokedex.o list.o
	${CC} ${CCFLAGS} -o main main.o ia.o joueur.o combat.o pokedex.o list.o

clean:
	rm *.o