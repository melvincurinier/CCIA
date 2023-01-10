#include "combat.h"

/*-------------- Partie initialisation ----------------*/
equipe *init_equipe(pile p){
    equipe *team=malloc(sizeof(equipe));
    team->nb_vivant=3;
    for (int j=0; j<3;j++){
        team->liste_pokemon[j]=pop(p);
    }
    return team;
}

terrain *init_terrain(equipe *J1, equipe *J2){
    terrain *t=malloc(sizeof(terrain));
    t->meteo=rien;
    t->pokeJ1 = J1->liste_pokemon[0];
    t->pokeJ2 = J2->liste_pokemon[0];
    return t;
}

/*-------------- Partie affichage ----------------*/
void afficher_equipe(equipe *E){
    for (int i=0;i<E->nb_vivant;i++){
        afficher_pokemon(E->liste_pokemon[i]);
    }
}

void afficher_terrain(terrain *T){
    printf(" ----------- METEO ---------- \n");
    afficher_meteo(T->meteo);
    printf(" -----------SUR LE TERRAIN ---------- \n");
    afficher_pokemon(T->pokeJ1);
    printf("           VS            \n");
    afficher_pokemon(T->pokeJ2);
}

/*--------------Partie changement de pokemon-------------------*/
void switch_pokemon(terrain *T, pokemon *poke, int joueur){
    if(joueur==1){
        T->pokeJ1=poke;
    }
    else{
        T->pokeJ2=poke;
    }
}

/*-------------- Partie attaque a degats brute ----------------*/
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

int calcul_pv_perdu(terrain *T, pokemon poke1, pokemon poke2, attaques att){
    int degats;
    double multiplicateur;
    double boost_meteo=1;
    if(att.phy_or_spe == 0){
        degats = ( ( 22 * poke1.attaque->puissance * poke1.stat.attaque ) / (50 * poke2.stat.defense) ) + 2;
    }
    else if (att.phy_or_spe==1) {
        degats = ( ( 22 * poke1.attaque->puissance * poke1.stat.attaque_spe ) / (50 * poke2.stat.defense_spe) ) + 2;
    }
    if (stab(att,poke1)){
        degats = degats * 2;
    }
    /*------------test des effets de la meteo-----------*/
    if(T->meteo==soleil){
        if(att.type==feu){
            boost_meteo=1.5;
        }
        else if(att.type==eau){
            boost_meteo=0.5;
        }
    }
    else if(T->meteo==pluie){
        if(att.type==eau){
            boost_meteo=1.5;
        }
        else if(att.type==feu){
            boost_meteo=0.5;
        }
    }
    multiplicateur = calcul_multiplicateur(att.type, poke2.type);
    degats = degats * multiplicateur * boost_meteo;

    return degats;
}

/*-------------- Partie attaque et gestion de changement de statut ----------------*/
void applique_confusion(terrain *T, pokemon * poke,attaques att){
    int degats = calcul_pv_perdu(T,*poke,*poke,att);
    poke->stat.PV = poke->stat.PV - degats;
}

void applique_paralisie(pokemon * poke ){
    poke->etat = paraliser;
    poke->stat.vitesse = poke->stat.vitesse - (poke->stat.vitesse * 0.25) ;
}

void applique_degats_empoisonnement(pokemon * poke){
    printf("le pokemon est empoisoner\n");
    poke->stat.PV = poke->stat.PV - (poke->stat.PV_max * 0.125) ;
}

void applique_degats_brulure(pokemon * poke){
    printf("le pokemon souffre de sa brulure\n");
    poke->stat.attaque = poke->stat.attaque - (poke->stat.attaque * 0.5);
    poke->stat.PV = poke->stat.PV - (poke->stat.PV * 0.0625); 
}

void degele(pokemon * poke){
    srand(time(NULL));
    int x=rand()%100;
    if(x<=20){
        printf("le pokemon n'est plus geler !");
        poke->etat=neutre;
    }
}

void reveil(pokemon * poke, int tour){
    srand(time(NULL));
    int x=rand()%4 + 1 ;
    if(x<=tour){
        printf("le pokemon se reveil !\n");
        poke->etat=neutre;
    }
}

void enleve_confusion(pokemon * poke, int tour){
    srand(time(NULL));
    int x=rand()%5 + 1 ;
    if(x<tour){
        poke->etat=neutre;
    }
}

void gestion_statut(pokemon * poke, int tour){
    switch (poke->etat){
        case brulure:
            applique_degats_brulure(poke);
            break;
        case empoisoner:
            applique_degats_empoisonnement(poke);
            break;
        case geler:
            degele(poke);
            break;
        case confusion:
            enleve_confusion(poke, tour);
            break;
        case endormie:
            reveil(poke,tour);
            break;
        default:
            break;
        }     
}

/*-------------- Partie attaque à changement de stat ----------------*/
double fraction(int f){
    double x;
    if(f==0){
        x = 1;
    }
    else if(f == -1){
        x= 0.66;
    }
    else if(f==-2){
        x= 0.5;
    }
    else if(f==-3){
        x= 0.4;
    }
    else if(f==-4){
        x= 0.33;
    }
    else if(f==-5){
        x= 0.285;
    }
    else if(f==-6){
        x= 0.25;
    }
    else if(f == 1){
        x= 1.5;
    }
    else if(f==2){
        x= 2;
    }
    else if(f==3){
        x= 2.5;
    }
    else if(f==4){
        x= 3;
    }
    else if(f==5){
        x= 3.5;
    }
    else if(f==6){
        x = 4;
    }
    return x;
}

void applique_nerf(pokemon * poke, attaques att){
    double x;
     for(int i=0;i<att.nb_s;i++){
        switch(att.s[i]){
            case 1:
                if(poke->stat.niv_att == -6){
                    printf("la stat est deja au plus bas\n");
                }
                else{
                    poke->stat.niv_att = poke->stat.niv_att - att.boost;
                    x = fraction(poke->stat.niv_att);
                    poke->stat.attaque = poke->stat.attaque_initial * x;
                }
                break;
            case 2:
                if(poke->stat.niv_att_spe == -6){
                    printf("la stat est deja au plus bas\n");
                }
                else{
                    poke->stat.niv_att_spe = poke->stat.niv_att_spe - att.boost;
                    x = fraction(poke->stat.niv_att_spe);
                    poke->stat.attaque_spe = poke->stat.attaque_spe_initial * x;
                }
                break;
            case 3:
                if(poke->stat.niv_def == -6){
                    printf("la stat est deja au plus bas\n");
                }
                else{
                    poke->stat.niv_def = poke->stat.niv_def - att.boost;
                    x = fraction( poke->stat.niv_def);
                    poke->stat.defense = poke->stat.defense_initial * x;
                }
                break;
            case 4:
                if(poke->stat.niv_def_spe == -6){
                    printf("la stat est deja au plus bas\n");
                }
                else{
                    poke->stat.niv_def_spe= poke->stat.niv_def_spe - att.boost;
                   x = fraction(poke->stat.niv_def_spe);
                   poke->stat.defense_spe = poke->stat.defense_spe_initial * x;
                }
                break;
            case 5:
                if(poke->stat.niv_vit == -6){
                    printf("la stat est deja au plus bas\n");
                }
                else{
                    poke->stat.niv_vit = poke->stat.niv_vit - att.boost;
                    x = fraction( poke->stat.niv_vit);
                    poke->stat.vitesse = poke->stat.vitesse_initial * x;
                }
                break;
            default:
                break;
        }
     }
} 

void applique_boost(pokemon *poke, attaques att){
    double x;
     for(int i=0;i<att.nb_s;i++){
        switch(att.s[i]){
            case 1:
                if(poke->stat.niv_att == 6){
                    printf("la stat est deja au plus haut\n");
                }
                else{
                    poke->stat.niv_att = poke->stat.niv_att + att.boost;
                    x = fraction( poke->stat.niv_att);
                    poke->stat.attaque = poke->stat.attaque_initial * x;
                }
                break;
            case 2:
                if(poke->stat.niv_att_spe == 6){
                    printf("la stat est deja au plus haut\n");
                }
                else{
                    poke->stat.niv_att_spe = poke->stat.niv_att_spe + att.boost;
                    x = fraction( poke->stat.niv_att_spe);
                    poke->stat.attaque_spe = poke->stat.attaque_spe_initial * x;
                }
                break;
            case 3:
                if(poke->stat.niv_def == 6){
                    printf("la stat est deja au plus haut\n");
                }
                else{
                    poke->stat.niv_def = poke->stat.niv_def + att.boost;
                    x = fraction( poke->stat.niv_def);
                    poke->stat.defense =(int) (poke->stat.defense_initial * x);
                }
                break;
            case 4:
                
                if(poke->stat.niv_def_spe == 6){
                    printf("la stat est deja au plus haut\n");
                }
                else{
                    poke->stat.niv_def_spe= poke->stat.niv_def_spe + att.boost;
                    x = fraction( poke->stat.niv_def_spe);
                    poke->stat.defense_spe = poke->stat.defense_spe_initial * x;
                }
                break;
            case 5:
                
                if(poke->stat.niv_vit ==6){
                    printf("la stat est deja au plus haut\n");
                }
                else{
                    poke->stat.niv_vit = poke->stat.niv_vit + att.boost;
                    x = fraction( poke->stat.niv_vit);
                    poke->stat.vitesse = poke->stat.vitesse_initial * x;
                }
                break;
            default:
                break;
        }
     }    
}

/*-------------- Partie attaque de changement de meteo et gestion du terrain ----------------*/

void gestion_tempete(terrain *T,int tour){
    if(tour==5){
        T->meteo=rien;
    }
    else{
        if(T->pokeJ1->type!=roche && T->pokeJ1->type!=sol && T->pokeJ1->type!=acier){
            T->pokeJ1->stat.PV = T->pokeJ1->stat.PV * 0.9375; // -1/16 de ses pv
        }
        if(T->pokeJ2->type!=roche && T->pokeJ2->type!=sol && T->pokeJ2->type!=acier){
            T->pokeJ2->stat.PV = T->pokeJ2->stat.PV * 0.9375; // -1/16 de ses pv
        }
    }
}

void gestion_grele(terrain *T,int tour){
    if(tour==5){
        T->meteo=rien;
    }
    else{
        if(T->pokeJ1->type!=glace){
            T->pokeJ1->stat.PV = T->pokeJ1->stat.PV * 0.9375; // -1/16 de ses pv
        }
        if(T->pokeJ2->type!=glace){
            T->pokeJ2->stat.PV = T->pokeJ2->stat.PV * 0.9375; // -1/16 de ses pv
        }
    } 
}

void gestion_pluie(terrain *T,int tour){
    if(tour==5){
        T->meteo=rien;
    }
}

void gestion_soleil(terrain *T,int tour){
    if(tour==5){
        T->meteo=rien;
    }
}

void gestion_meteo(terrain *T, int tour){
    switch (T->meteo){
        case tempete:
            gestion_tempete(T,tour);
            break;
        case pluie:
            gestion_pluie(T,tour);
            break;
        case grele:
            gestion_grele(T,tour);
            break;
        case soleil:
            gestion_soleil(T,tour);
        default:
            break;
        }   
}

/*-------------- Partie gestion de l'attaque ----------------*/
int attaque_priorite(pokemon *poke1, pokemon *poke2){
    return (poke1->stat.vitesse >= poke2->stat.vitesse );
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

void applique_attaque(terrain *T,pokemon * poke_attaquant, pokemon * poke_defensive, attaques att, int tour){
        int degats;
        int touche = toucher(*poke_attaquant,att);
        if(touche == 0){
            printf("le pokemon a raté son attaque\n");
        }
        else if(touche == 1){
            /*--------------cas d'une attaque normal----------------*/
            if(att.application == 0){
                degats = calcul_pv_perdu(T,*poke_attaquant,*poke_defensive,att);
                poke_defensive->stat.PV = poke_defensive->stat.PV - degats;
            }
            /*--------------cas d'une attaque de changement de statut ----------------*/
            else if(att.application == 1){
                if(poke_defensive->etat == neutre){
                    switch (att.effet) {
                        case paraliser :
                            applique_paralisie(poke_defensive);
                            break;
                        case empoisoner:
                            poke_defensive->etat=empoisoner;
                            break;
                        case endormie:
                            poke_defensive->etat = endormie;
                            poke_defensive->tour_etat=tour;
                            break;
                        case brulure:
                            poke_defensive->etat = brulure;
                            break;
                        case confusion:
                            poke_defensive->etat = confusion;
                            poke_defensive->tour_etat=tour;
                            break;
                        case geler:
                            poke_defensive->etat = geler;
                            break;
                        default:
                            break;
                    }
                }
                else{
                    printf("L'attaque a echoué\n");
                }
            }
            /*--------------cas d'une attaque qui boost une ou plusieurs stats---------*/
            else if(att.application == 2){
                applique_boost(poke_attaquant,att);
            }
            /*--------------cas d'une attaque qui nerf une ou plusieurs stats---------*/
            else if(att.application == 3){
                applique_nerf(poke_defensive,att);
            }
            /*--------------cas d'une attaque qui change la meteo---------*/
            else if(att.application == 4){
                switch (att.Meteo) {
                        case pluie :
                            T->meteo=pluie;
                            T->tour_meteo=tour;
                            break;
                        case soleil:
                            T->meteo=soleil;
                            T->tour_meteo=tour;
                            break;
                        case tempete:
                            T->meteo=tempete;
                            T->tour_meteo=tour;
                            break;
                        case grele:
                            T->meteo=grele;
                            T->tour_meteo=tour;
                            break;
                        default:
                            break;
                    }
            }
            
        }
        else if(touche == 2){
            applique_confusion(T,poke_attaquant,att);
        }
}

/*-------------- Partie gestion des morts ----------------*/
int mort(pokemon *poke){
    return (poke->stat.PV <= 0);
}

void enlever_pokemon_equipe(equipe * E, pokemon *poke){
    int i=0;
    pokemon *p = E->liste_pokemon[i];
    while( i < E->nb_vivant &&  p->nom != poke->nom ){
        i++;
        p=E->liste_pokemon[i];
    }
    //on place le dernier pokemon de la team a la place du pokemon mort
    E->liste_pokemon[i]=E->liste_pokemon[E->nb_vivant-1];
    //on reduit la taille de la team
    E->nb_vivant--;
}














