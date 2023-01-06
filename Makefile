CC = gcc
CCFLAGS = -Wall -g

all : main

list.o: list.c list.h pokemon.h
	${CC} ${CCFLAGS} -c list.c

pokedex.o: pokedex.c pokedex.h pokemon.h list.h
	${CC} ${CCFLAGS} -c pokedex.c

combat.o: combat.c pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c combat.c

arbre.o: arbre.c item.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c arbre.c

joueur.o: joueur.c arbre.h item.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c joueur.c

node.o: node.c joueur.h arbre.h item.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c node.c

ia.o: ia.c node.h joueur.h arbre.h item.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c ia.c

main.o: main.c ia.h node.h joueur.h arbre.h item.h combat.h pokedex.h list.h pokemon.h
	${CC} ${CCFLAGS} -c main.c 



main: main.o ia.o node.o joueur.o arbre.o combat.o pokedex.o list.o
	${CC} ${CCFLAGS} -o main main.o ia.o node.o joueur.o arbre.o combat.o pokedex.o list.o

clean:
	rm *.o