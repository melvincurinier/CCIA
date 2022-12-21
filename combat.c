#include "combat.h"

equipe init_equipe(pile p){
    equipe team;
    team.nb_vivant=3;
    for (int j=0; j<3;j++){
        team.liste_pokemon[j]=pop(p);
    }
    return team;
}

void afficher_equipe(equipe E){
    for (int i=0;i<E.nb_vivant;i++){
        afficher_pokemon(E.liste_pokemon[i]);
    }
}

terrain init_terrain(){
    terrain t;
    t.meteo=rien;
    return t;
}

void afficher_terrain(terrain T,equipe J1,equipe J2){
    // printf(" ----------- METEO ---------- \n");
    // afficher_meteo(T.meteo);
    printf(" -----------SUR LE TERRAIN ---------- \n");
    afficher_pokemon(J1.liste_pokemon[0]);
    printf("           VS            \n");
    afficher_pokemon(J2.liste_pokemon[0]);
}

double calcul_multiplicateur(Types offensive, Types defensive){
    double x;
    switch (offensive){
    case feu :
        switch (defensive){
        case acier :
        case glace :
        case insecte:
        case plante:
            x=2;
            break;
        case eau:
        case dragon:
        case feu:
        case roche:
            x=0.5;
            break;
        default:
            x=1;
            break;
        }
        break;
    case acier :
        switch (defensive){    
            case fee:
            case glace:
            case roche:
                x=2;
                break;
            case acier:
            case eau:
            case electrique:
            case feu:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case combat :
        switch (defensive){
            case acier:
            case glace:
            case normal:
            case roche:
            case tenebre:
                x=2;
                break;
            case fee:
            case insecte:
            case poison:
            case psy:
            case vol:
                x=0.5;
                break;
            case spectre:
                x=0;
            default:
                x=1;
                break;
        }
        break;
    case dragon:
        switch (defensive){
            case dragon:
                x=2;
                break;
            case acier:
                x=0.5;
                break;
            case fee:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case eau:
        switch (defensive){
            case feu:
            case roche:
            case sol:
                x=2;
                break;
            case dragon:
            case eau:
            case plante:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case electrique:
        switch (defensive){
            case eau:
            case vol:
                x=2;
                break;
            case dragon:
            case electrique:
            case plante:
                x=0.5;
                break;
            case sol:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case fee:
        switch (defensive){
            case combat:
            case dragon:
            case tenebre:
                x=2;
                break;
            case acier:
            case feu:
            case poison:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case glace:
        switch (defensive){
            case dragon:
            case sol:
            case plante:
            case vol:
                x=2;
                break;
            case acier:
            case eau:
            case feu:
            case glace:
                x=0.5;
                break;
            default :
                x=1;
                break;
        }
        break;
    case insecte:
        switch (defensive){
            case plante:
            case psy:
            case tenebre:
                x=2;
                break;
            case acier:
            case combat:
            case fee:
            case feu:
            case poison:
            case vol:
            case spectre:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case normal:
        switch (defensive){
            case acier:
            case roche:
                x=0.5;
                break;
            case spectre:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case plante:
        switch (defensive){
            case eau:
            case roche:
            case sol:
                x=2;
                break;
            case acier:
            case dragon:
            case feu:
            case insecte:
            case plante:
            case poison:
            case vol:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case poison:
        switch (defensive){
            case fee:
            case plante:
                x=2;
                break;
            case acier:
                x=0;
                break;
            case poison:
            case roche:
            case sol:
            case spectre:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case psy:
        switch (defensive){
            case combat:
            case poison:
                x=2;
                break;
            case acier:
            case psy:
                x=0.5;
                break;
            case tenebre:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case roche:
        switch (defensive){
            case feu:
            case glace:
            case insecte:
            case vol:
                x=2;
                break;
            case acier:
            case combat:
            case sol:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case sol:
        switch (defensive){
            case acier:
            case electrique:
            case feu:
            case poison:
            case roche:
                x=2;
                break;
            case insecte:
            case plante:
                x=0.5;
                break;
            case vol:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case spectre:
        switch (defensive){
            case psy:
            case spectre:
                x=2;
                break;
            case tenebre:
                x=0.5;
                break;
            case normal:
                x=0;
                break;
            default:
                x=1;
                break;
        }
        break;
    case tenebre:
        switch (defensive){
            case psy:
            case spectre:
                x=2;
                break;
            case combat:
            case fee:
            case tenebre:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    case vol:
        switch (defensive){
            case combat:
            case insecte:
            case plante:
                x=2;
                break;
            case acier:
            case electrique:
            case roche:
                x=0.5;
                break;
            default:
                x=1;
                break;
        }
        break;
    default:
        break;
    }
    return x;
}

int stab(attaques att, pokemon poke){
    return (att.type==poke.type);
}

int calcul_pv_perdu(pokemon poke1, pokemon poke2, attaques att){
    int degats;
    double multiplicateur;
    if(att.phy_or_spe == 0){
        degats = ( ( 22 * poke1.attaque->puissance * poke1.stat.attaque ) / (50 * poke2.stat.defense) ) + 2;
    }
    else if (att.phy_or_spe==1) {
        degats = ( ( 22 * poke1.attaque->puissance * poke1.stat.attaque_spe ) / (50 * poke2.stat.defense_spe) ) + 2;
    }
    if (stab(att,poke1)){
        degats = degats *2;
    }
    multiplicateur = calcul_multiplicateur(att.type, poke2.type);
    degats = degats * multiplicateur;
    return degats;
}

equipe enlever_pokemon_equipe(equipe E, pokemon poke){
    int i=0;
    pokemon p = E.liste_pokemon[i];
    while( i < E.nb_vivant &&  p.nom != poke.nom ){
        i++;
        p=E.liste_pokemon[i];
    }
    //on place le dernier pokemon de la team a la place du pokemon mort
    E.liste_pokemon[i]=E.liste_pokemon[E.nb_vivant-1];
    //on reduit la taille de la team
    E.nb_vivant--;
    return E;
}

int toucher(pokemon poke,attaques att){
    srand(time(NULL));
    int precision=att.precision/100;
    int x;
    x = rand()%100;
    if(poke.etat == endormie || poke.etat == geler ){
        return 0;
    }
    else if(poke.etat==confusion){
        //si l'attaque a rater(le pokemon se blesse dans sa confusuin)
        if(x < ((precision * 0.33)*100)){
            printf("il se blesse dans sa confusion\n");
            return 2;
        }
        //l'attaque a reussi
        else{
            return 1;
        }
    }
    else if(poke.etat==paraliser){
        if(x < ((precision * 0.25)*100)){
            printf("le pokemon est paralyser, il n'a pas pu attaquer\n");
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        // l'attaque reussi
        if(x<att.precision){
            return 1;
        }
        else{
            return 0;
        }
    }
}


pokemon applique_attaque(pokemon poke_attaquant, pokemon poke_defensive ,attaques att, int tour){
        int degats;
        /*--------------cas d'une attaque normal----------------*/
        if(att.application == 0){
            degats = calcul_pv_perdu(poke_attaquant,poke_defensive,att);
            poke_defensive.stat.PV = poke_defensive.stat.PV - degats;
        }
        /*--------------cas d'une attaque de changement de statut ----------------*/
        else if(att.application == 1){
            if(poke_defensive.etat == neutre){
                switch (att.effet) {
                    case paraliser :
                        poke_defensive = applique_paralisie(poke_defensive);
                        break;
                    case empoisoner:
                        poke_defensive.etat=empoisoner;
                        poke_defensive.tour_etat=tour;
                        break;
                    case endormie:
                        poke_defensive.etat = endormie;
                        poke_defensive.tour_etat=tour;
                        break;
                    case brulure:
                        poke_defensive.etat = brulure;
                        poke_defensive.tour_etat=tour;
                        break;
                    case confusion:
                        poke_defensive.etat = confusion;
                        poke_defensive.tour_etat=tour;
                        break;
                    case geler:
                        poke_defensive.etat = geler;
                        poke_defensive.tour_etat=tour;
                        break;
                    default:
                        break;
                }
            }
            else{
                printf("L'attaque a echoué\n");
            }
        }
    return poke_defensive;
}

pokemon applique_confusion(pokemon poke,attaques att){
    int degats = calcul_pv_perdu(poke,poke,att);
    poke.stat.PV = poke.stat.PV - degats;
    return poke;
}

int mort(pokemon poke){
    return (poke.stat.PV <= 0);
}

int attaque_priorite(pokemon poke1, pokemon poke2){
    return (poke1.stat.vitesse >= poke2.stat.vitesse );
}

equipe switch_pokemon(equipe E, pokemon poke){
    int i=0;
    pokemon p = E.liste_pokemon[i];
    while( i < E.nb_vivant &&  p.nom != poke.nom ){
        i++;
        p=E.liste_pokemon[i];
    }
    E.liste_pokemon[i]=E.liste_pokemon[0];
    E.liste_pokemon[0]=poke;
    return E;
}

pokemon applique_paralisie(pokemon p){
    p.etat = paraliser;
    p.stat.vitesse = p.stat.vitesse - (p.stat.vitesse * 0.25) ;
    return p;
}

pokemon applique_degats_empoisonnement(pokemon p){
    printf("le pokemon est empoisoner\n");
    p.stat.PV = p.stat.PV - (p.stat.PV_max * 0.125) ;
    return p;
}

pokemon applique_degats_brulure(pokemon p){
    printf("le pokemon souffre de sa brulure\n");
    p.stat.attaque = p.stat.attaque - (p.stat.attaque * 0.5);
    p.stat.PV = p.stat.PV - (p.stat.PV * 0.0625); 
    return p;
}

pokemon degele(pokemon poke){
    srand(time(NULL));
    int x=rand()%100;
    if(x<=20){
        printf("le pokemon n'est plus geler !");
        poke.etat=neutre;
    }
    return poke;
}

pokemon reveil(pokemon poke, int tour){
    srand(time(NULL));
    int x=rand()%4 + 1 ;
    if(x<=tour){
        printf("le pokemon se reveil !\n");
        poke.etat=neutre;
    }
    return poke;
}

pokemon enleve_confusion(pokemon poke, int tour){
    srand(time(NULL));
    int x=rand()%5 + 1 ;
    if(x<tour){
        poke.etat=neutre;
    }
    return poke;
}

pokemon gestion_statut(pokemon poke, int tour){
    switch (poke.etat){
        case brulure:
            poke=applique_degats_brulure(poke);
            break;
        case empoisoner:
            poke = applique_degats_empoisonnement(poke);
            break;
        case geler:
            poke = degele(poke);
            break;
        case confusion:
            poke= enleve_confusion(poke, tour);
            break;
        case endormie:
            poke = reveil(poke,tour);
            break;
        default:
            break;
        }
        return poke;      
}