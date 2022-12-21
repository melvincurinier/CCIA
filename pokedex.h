#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* ------- fonction d'affichage des types enumérées pour facilter la lisibilité ------- */
void afficher_type(Types i);

void affiche_statut(statut s);

void afficher_stat(int i);

void afficher_attaque(attaques a);

void afficher_etat(statut s);

void afficher_meteo(statut2 s);


//creer un type pokemon a partir des donnes qu'on lui passe en parametre
pokemon creer_pokemon(char *nomP, Types t,attaques att[],int nb, stats S);

//ici qu'on initialisera tout les pokemon en creant les tableau de stat, d'attaque ... 
void creer_pokedex(pile p);

//affiche toutes les caractéristique d'un pokemon (utile pour tester)
void afficher_pokemon(pokemon poke);

//affiche tout les pokemon que l'on a créer
void afficher_pokedex(pile p);




