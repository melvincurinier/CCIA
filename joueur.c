#include "joueur.h"

int partie_fini (equipe *J1, equipe *J2){
    return ( J1->nb_vivant == 0 || J2->nb_vivant == 0 );
}

int choix_action_joueur(){
    printf("Attaquer : 0 / Switcher : 1 \n");
    int c;
    scanf("%d",&c);
    while(c!= 1 && c!=0){
        printf("Attaquer : 0 / Switcher : 1 \n");
        scanf("%d",&c);
    }
    return c;
}

attaques choix_att_joueur(pokemon *poke){
    int i;
    int choix;
    printf(" taper le chiffre correspondant a l'attaque que vous souhaitez réaliser : \n");
    for (i=0; i<poke->nb_attaque; i++){
        printf("%d : ",i);
        afficher_attaque(poke->attaque[i]);
    }
    scanf("%d",&choix);
    while (choix < 0 || choix > 3){
        printf(" taper le chiffre correspondant a l'attaque que vous souhaitez réaliser : \n");
        scanf("%d",&choix);
    }
    return poke->attaque[choix];
}

pokemon * choix_switch_joueur(equipe *J1){
    int i;
    int choix;
    printf(" taper le chiffre correspondant au pokemon que vous souhaitez envoyer au combat : \n");
    for (i=0; i<J1->nb_vivant; i++){
        printf("%d : ",i);
        printf("%s\n", J1->liste_pokemon[i]->nom);
    }
    scanf("%d",&choix);
    while (choix < 0 || choix > J1->nb_vivant - 1){
        printf(" taper le chiffre correspondant au pokemon que vous souhaitez envoyer au combat : \n");     
        scanf("%d",&choix);
    }
    return J1->liste_pokemon[choix];
}

