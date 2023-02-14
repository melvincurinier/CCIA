#include "combat.h"
#include <time.h>
/*-------------- Partie initialisation ----------------*/

equipe init_equipe(pile p){
    equipe team;
    team.nb_vivant=3;
    for (int j=0; j<3;j++){
        team.liste_pokemon[j]=pop(p);
    }
    return team;
}

equipe init_equipe_alea(pile p){
    equipe team;
    team.nb_vivant=3;
    
    for (int j=0; j<3;j++){
        int num = 11-j;
        team.liste_pokemon[j]=pop_selection(p,num);
    }
    return team;
}

equipe choisir_equipe(pile p){
    equipe E;
    E.nb_vivant=3;
    int numero;
    for(int i=0; i<3;i++){
        afficher_pokedex(p);
        printf("Choississez un pokemon : ");
        scanf("%d",&numero);
        E.liste_pokemon[i]=pop_selection(p,numero);
    }
    return E;
}

terrain init_terrain(equipe J1, equipe J2){
    terrain t;
    t.meteo=rien;
    t.J1 = J1;
    t.J2 = J2;
    return t;
}

/*-------------- Partie affichage ----------------*/

void afficher_equipe(equipe E){
    for (int i=0;i<E.nb_vivant;i++){
        afficher_pokemon(E.liste_pokemon[i]);
    }
}

void afficher_terrain(terrain T){
    printf(" ----------- METEO ---------- \n");
    afficher_meteo(T.meteo);
    printf(" -----------SUR LE TERRAIN ---------- \n");
    afficher_pokemon(T.J1.liste_pokemon[0]);
    printf("           VS            \n");
    afficher_pokemon(T.J2.liste_pokemon[0]);
}

/*--------------Partie changement de pokemon-------------------*/

terrain switch_pokemon(terrain T, int joueur, pokemon poke){
    int i=0;
    pokemon p;
    if( joueur == 1){
        p = T.J1.liste_pokemon[i];
        while( i < T.J1.nb_vivant &&  p.nom != poke.nom ){
            i++;
            p=T.J1.liste_pokemon[i];
        }
        T.J1.liste_pokemon[i]=T.J1.liste_pokemon[0];
        T.J1.liste_pokemon[0]=poke;
    }
    else if( joueur == 2){
        p = T.J2.liste_pokemon[i];
        while( i < T.J2.nb_vivant &&  p.nom != poke.nom ){
            i++;
            p=T.J2.liste_pokemon[i];
        }
        T.J2.liste_pokemon[i]=T.J2.liste_pokemon[0];
        T.J2.liste_pokemon[0]=poke;
    }
    return T;
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

int calcul_pv_perdu(terrain T, pokemon poke1, pokemon poke2, attaques att){
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
        degats = degats *2;
    }
    multiplicateur = calcul_multiplicateur(att.type, poke2.type);

    if(T.meteo == soleil){
        if(att.type == feu){
            boost_meteo=1.5;
        }
        else if(att.type==eau){
            boost_meteo = 0.5;
        }
    }
    else if(T.meteo == pluie){
        if(att.type == feu){
            boost_meteo = 0.5;
        }
        else if( att.type == eau){
            boost_meteo = 1.5;
        }
    }

    degats = degats * multiplicateur * boost_meteo;


    return degats;
}

/*-------------- Partie attaque et gestion de changement de statut ----------------*/

pokemon applique_confusion(terrain T,pokemon poke,attaques att){
    int degats = calcul_pv_perdu(T,poke,poke,att);
    poke.stat.PV = poke.stat.PV - degats;
    return poke;
}

pokemon applique_paralisie(pokemon p){
    p.etat = paraliser;
    p.stat.vitesse = p.stat.vitesse - (p.stat.vitesse * 0.25) ;
    return p;
}

pokemon applique_degats_empoisonnement(pokemon p){
   // printf("le pokemon est empoisoner\n");
    p.stat.PV = p.stat.PV - (p.stat.PV_max * 0.125) ;
    return p;
}

pokemon applique_degats_brulure(pokemon p){
   // printf("le pokemon souffre de sa brulure\n");
    p.stat.attaque = p.stat.attaque - (p.stat.attaque * 0.5);
    p.stat.PV = p.stat.PV - (p.stat.PV * 0.0625); 
    return p;
}

pokemon degele(pokemon poke){
    srand(time(NULL));
    int x=rand()%100;
    if(x<=20){
       // printf("le pokemon n'est plus geler !");
        poke.etat=neutre;
    }
    return poke;
}

pokemon reveil(pokemon poke, int tour){
    srand(time(NULL));
    int x=rand()%4 + 1 ;
    if(x<=tour){
       // printf("le pokemon se reveil !\n");
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

pokemon applique_nerf(pokemon poke, attaques att){
     double x;
     for(int i=0;i<att.nb_s;i++){
        switch(att.s[i]){
            case 1:
                if(poke.stat.niv_att == -6){
                   // printf("la stat est deja au plus bas\n");
                }
                else{
                    poke.stat.niv_att = poke.stat.niv_att - att.boost;
                    x = fraction(poke.stat.niv_att);
                    poke.stat.attaque = poke.stat.attaque_initial * x;
                }
                break;
            case 2:
                if(poke.stat.niv_att_spe == -6){
                    //printf("la stat est deja au plus bas\n");
                }
                else{
                    poke.stat.niv_att_spe = poke.stat.niv_att_spe - att.boost;
                    x = fraction(poke.stat.niv_att_spe);
                    poke.stat.attaque_spe = poke.stat.attaque_spe_initial * x;
                }
                break;
            case 3:
                if(poke.stat.niv_def == -6){
                   // printf("la stat est deja au plus bas\n");
                }
                else{
                    poke.stat.niv_def = poke.stat.niv_def - att.boost;
                    x = fraction( poke.stat.niv_def);
                    poke.stat.defense = poke.stat.defense_initial * x;
                }
                break;
            case 4:
                if(poke.stat.niv_def_spe == -6){
                   // printf("la stat est deja au plus bas\n");
                }
                else{
                    poke.stat.niv_def_spe= poke.stat.niv_def_spe - att.boost;
                   x = fraction(poke.stat.niv_def_spe);
                   poke.stat.defense_spe = poke.stat.defense_spe_initial * x;
                }
                break;
            case 5:
                if(poke.stat.niv_vit == -6){
                    //printf("la stat est deja au plus bas\n");
                }
                else{
                    poke.stat.niv_vit = poke.stat.niv_vit - att.boost;
                    x = fraction( poke.stat.niv_vit);
                    poke.stat.vitesse = poke.stat.vitesse_initial * x;
                }
                break;
            default:
                break;
        }
     }
     return poke;
}

pokemon applique_boost(pokemon poke, attaques att){
    double x;
     for(int i=0;i<att.nb_s;i++){
        switch(att.s[i]){
            case 1:
                if(poke.stat.niv_att == 6){
                    //printf("la stat est deja au plus haut\n");
                }
                else{
                    poke.stat.niv_att = poke.stat.niv_att + att.boost;
                    x = fraction(poke.stat.niv_att);
                    poke.stat.attaque = poke.stat.attaque_initial * x;
                }
                break;
            case 2:
                if(poke.stat.niv_att_spe == 6){
                   // printf("la stat est deja au plus haut\n");
                }
                else{
                    poke.stat.niv_att_spe = poke.stat.niv_att_spe + att.boost;
                    x = fraction(poke.stat.niv_att_spe);
                    poke.stat.attaque_spe = poke.stat.attaque_spe_initial * x;
                }
                break;
            case 3:
                if(poke.stat.niv_def == 6){
                   // printf("la stat est deja au plus haut\n");
                }
                else{
                    poke.stat.niv_def = poke.stat.niv_def + att.boost;
                    x = fraction( poke.stat.niv_def);
                    poke.stat.defense = poke.stat.defense_initial * x;
                }
                break;
            case 4:
                if(poke.stat.niv_def_spe == 6){
                    //printf("la stat est deja au plus haut\n");
                }
                else{
                    poke.stat.niv_def_spe= poke.stat.niv_def_spe + att.boost;
                   x = fraction(poke.stat.niv_def_spe);
                   poke.stat.defense_spe = poke.stat.defense_spe_initial * x;
                }
                break;
            case 5:
                if(poke.stat.niv_vit == 6){
                   // printf("la stat est deja au plus haut\n");
                }
                else{
                    poke.stat.niv_vit = poke.stat.niv_vit + att.boost;
                    x = fraction( poke.stat.niv_vit);
                    poke.stat.vitesse = poke.stat.vitesse_initial * x;
                }
                break;
            default:
                break;
        }
     }
     return poke;
}

/*-------------- Partie attaque de changement de meteo et gestion du terrain ----------------*/

terrain gestion_tempete(terrain T,int joueur,int tour){
    if(tour==5){
        T.meteo=rien;
    }
    else{
        if(joueur == 1){
            if(T.J1.liste_pokemon[0].type!=roche && T.J1.liste_pokemon[0].type!=sol && T.J1.liste_pokemon[0].type!=acier){
                T.J1.liste_pokemon[0].stat.PV = T.J1.liste_pokemon[0].stat.PV - (T.J1.liste_pokemon[0].stat.PV_max * 0.0625); // -1/16 de ses pv
            }
        }
        else{
            if(T.J2.liste_pokemon[0].type!=roche && T.J2.liste_pokemon[0].type!=sol && T.J2.liste_pokemon[0].type!=acier){
                T.J2.liste_pokemon[0].stat.PV = T.J2.liste_pokemon[0].stat.PV - (T.J2.liste_pokemon[0].stat.PV_max * 0.0625); // -1/16 de ses pv
            }
        }
    }
    return T;
}

terrain gestion_grele(terrain T,int joueur,int tour){
    if(tour == 5){
        T.meteo=rien;
    }
    else{
        if(joueur == 1){
            if(T.J1.liste_pokemon[0].type != glace ){
                T.J1.liste_pokemon[0].stat.PV = T.J1.liste_pokemon[0].stat.PV - (T.J1.liste_pokemon[0].stat.PV_max * 0.0625); // -1/16 de ses pv
            }
        }
        else {
            if(T.J2.liste_pokemon[0].type != glace){
                T.J2.liste_pokemon[0].stat.PV = T.J2.liste_pokemon[0].stat.PV - (T.J2.liste_pokemon[0].stat.PV_max * 0.0625); // -1/16 de ses pv
            }
        }
    }
    return T;
}

terrain gestion_soleil(terrain T,int joueur,int tour){
    if(tour==5){
        T.meteo=rien;
    }
    return T;
}

terrain gestion_pluie(terrain T,int joueur,int tour){
    if(tour>=5){
        T.meteo=rien;
    }
    return T;
}

terrain gestion_meteo(terrain T,int joueur, int tour){
    switch (T.meteo){
        case tempete:
            T = gestion_tempete(T,joueur,tour);
            break;
        case pluie:
            T = gestion_pluie(T,joueur,tour);
            break;
        case grele:
            T= gestion_grele(T,joueur,tour);
            break;
        case soleil:
            T = gestion_soleil(T,joueur,tour);
            break;
        default:
            break;
        } 
    return T;
}


/*-------------- Partie gestion de l'attaque ----------------*/

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
           // printf("il se blesse dans sa confusion\n");
            return 2;
        }
        //l'attaque a reussi
        else{
            return 1;
        }
    }
    else if(poke.etat==paraliser){
        if(x < ((precision * 0.25)*100)){
           // printf("le pokemon est paralyser, il n'a pas pu attaquer\n");
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

terrain applique_attaque(terrain T, int joueur ,attaques att, int tour){
    int degats;
    // le J1 attaque le J2
    if(joueur == 1){
        /*--------------cas d'une attaque normal----------------*/
        if(att.application == 0){
            degats = calcul_pv_perdu(T,T.J1.liste_pokemon[0],T.J2.liste_pokemon[0],att);
            T.J2.liste_pokemon[0].stat.PV = T.J2.liste_pokemon[0].stat.PV - degats;
            if(T.J2.liste_pokemon[0].stat.PV < 0){
                T.J2.liste_pokemon[0].stat.PV =0;
            }
        }
        /*--------------cas d'une attaque de changement de statut ----------------*/
        else if(att.application == 1){
            if(T.J2.liste_pokemon[0].etat == neutre){
                switch (att.effet) {
                    case paraliser :
                        T.J2.liste_pokemon[0] = applique_paralisie(T.J2.liste_pokemon[0]);
                        break;
                    case empoisoner:
                        T.J2.liste_pokemon[0].etat=empoisoner;
                        T.J2.liste_pokemon[0].tour_etat=tour;
                        break;
                    case endormie:
                        T.J2.liste_pokemon[0].etat = endormie;
                        T.J2.liste_pokemon[0].tour_etat=tour;
                        break;
                    case brulure:
                        T.J2.liste_pokemon[0].etat = brulure;
                        T.J2.liste_pokemon[0].tour_etat=tour;
                        break;
                    case confusion:
                        T.J2.liste_pokemon[0].etat = confusion;
                        T.J2.liste_pokemon[0].tour_etat=tour;
                        break;
                    case geler:
                        T.J2.liste_pokemon[0].etat = geler;
                        T.J2.liste_pokemon[0].tour_etat=tour;
                        break;
                    default:
                        break;
                }
            }
            else{
                // printf("L'attaque a echoué\n");
            }
        }
        else if( att.application == 2){
            T.J1.liste_pokemon[0] = applique_boost(T.J1.liste_pokemon[0], att);
        }
        else if( att.application == 3){
            T.J2.liste_pokemon[0] = applique_nerf(T.J2.liste_pokemon[0], att);
        }
        else if(att.application == 4){
            switch (att.Meteo) {
                    case pluie :
                        if(T.meteo == pluie){
                           // printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=pluie;
                            T.tour_meteo=tour;
                        }
                        break;
                    case soleil:
                        if(T.meteo == soleil){
                            //printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=soleil;
                            T.tour_meteo=tour;
                        }
                        break;
                    case tempete:
                        if(T.meteo == tempete){
                           // printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=tempete;
                            T.tour_meteo=tour;
                        }
                        break;
                    case grele:
                        if(T.meteo == grele){
                           // printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=grele;
                            T.tour_meteo=tour;
                        }
                        break;
                    default:
                        break;
                    }
        }
    }
    else if(joueur == 2){
         /*--------------cas d'une attaque normal----------------*/
        if(att.application == 0){
            degats = calcul_pv_perdu(T,T.J2.liste_pokemon[0],T.J1.liste_pokemon[0],att);
            T.J1.liste_pokemon[0].stat.PV = T.J1.liste_pokemon[0].stat.PV - degats;
            if(T.J1.liste_pokemon[0].stat.PV < 0){
                T.J1.liste_pokemon[0].stat.PV = 0;
            }
        }
        /*--------------cas d'une attaque de changement de statut ----------------*/
        else if(att.application == 1){
            if(T.J1.liste_pokemon[0].etat == neutre){
                switch (att.effet) {
                    case paraliser :
                        T.J1.liste_pokemon[0] = applique_paralisie(T.J1.liste_pokemon[0]);
                        break;
                    case empoisoner:
                        T.J1.liste_pokemon[0].etat=empoisoner;
                        T.J1.liste_pokemon[0].tour_etat=tour;
                        break;
                    case endormie:
                        T.J1.liste_pokemon[0].etat = endormie;
                        T.J1.liste_pokemon[0].tour_etat=tour;
                        break;
                    case brulure:
                        T.J1.liste_pokemon[0].etat = brulure;
                        T.J1.liste_pokemon[0].tour_etat=tour;
                        break;
                    case confusion:
                        T.J1.liste_pokemon[0].etat = confusion;
                        T.J1.liste_pokemon[0].tour_etat=tour;
                        break;
                    case geler:
                        T.J1.liste_pokemon[0].etat = geler;
                        T.J1.liste_pokemon[0].tour_etat=tour;
                        break;
                    default:
                        break;
                }
            }
            else{
               // printf("L'attaque a echoué\n");
            }
        }
        else if( att.application == 2){
            T.J2.liste_pokemon[0] = applique_boost(T.J2.liste_pokemon[0], att);
        }
        else if( att.application == 3){
            T.J1.liste_pokemon[0] = applique_nerf(T.J1.liste_pokemon[0], att);
        }
        else if(att.application == 4){
            switch (att.Meteo) {
                    case pluie :
                        if(T.meteo == pluie){
                           // printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=pluie;
                            T.tour_meteo=tour;
                        }
                        break;
                    case soleil:
                        if(T.meteo == soleil){
                            //printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=soleil;
                            T.tour_meteo=tour;
                        }
                        break;
                    case tempete:
                        if(T.meteo == tempete){
                            //printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=tempete;
                            T.tour_meteo=tour;
                        }
                        break;
                    case grele:
                        if(T.meteo == grele){
                            //printf("L'attaque a echoué\n");
                        }
                        else{
                            T.meteo=grele;
                            T.tour_meteo=tour;
                        }
                        break;
                    default:
                        break;
            }
        }
    }
    return T;
}

/*-------------- Partie gestion des morts ----------------*/

int mort(pokemon poke){
    return (poke.stat.PV <= 0);
}

terrain enlever_pokemon_equipe(terrain T, int joueur , pokemon poke){

    int i=0;
    pokemon p;
    if (joueur == 1){
        p = T.J1.liste_pokemon[i];
        while( i < T.J1.nb_vivant &&  p.nom != poke.nom ){
            i++;
            p=T.J1.liste_pokemon[i];
        }
        //on place le dernier pokemon de la team a la place du pokemon mort
        T.J1.liste_pokemon[i]=T.J1.liste_pokemon[T.J1.nb_vivant-1];
        //on reduit la taille de la team
        T.J1.nb_vivant--;
    }
    else if (joueur == 2){
        p = T.J2.liste_pokemon[i];
        while( i < T.J2.nb_vivant &&  p.nom != poke.nom ){
            i++;
            p=T.J2.liste_pokemon[i];
        }
        //on place le dernier pokemon de la team a la place du pokemon mort
        T.J2.liste_pokemon[i]=T.J2.liste_pokemon[T.J2.nb_vivant-1];
        //on reduit la taille de la team
        T.J2.nb_vivant--;
    }
    return T;
}

