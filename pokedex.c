#include "pokedex.h"

void afficher_type(Types i){
        switch (i) {
            case 0:
                printf("feu");
                break;
            case 1:
                printf("eau");
                break;
            case 2:
                printf("plante");
                break;
            case 3:
                printf("electrique");
                break;
            case 4:
                printf("psy");
                break;
            case 5:
                printf("poison");
                break;
            case 6:
                printf("vol");
                break;
            case 7:
                printf("spectre");
                break;
            case 8:
                printf("tenebre");
                break;
            case 9:
                printf("sol");
                break;
            case 10:
                printf("dragon");
                break;
            case 11:
                printf("fée");
                break;
            case 12:
                printf("insecte");
                break;
            case 13:
                printf("combat");
                break;
            case 14:
                printf("normal");
                break;
            case 15:
                printf("roche");
                break;
            case 16:
                printf("acier");
                break;
            case 17:
                printf("glace");
                break;
            default :
                break;
        }
}

void affiche_statut(statut s){
    switch (s) {
        case 0:
            printf("neutre\n");
            break;
        case 1:
            printf("paraliser\n");
            break;
        case 2:
            printf("empoisoner\n");
            break;
        case 3:
            printf("endormie\n");
            break;
        case 4:
            printf("bruler\n");
            break;
        case 5:
            printf("confusion\n");
            break;
        case 6:
            printf("geler\n");
            break;
        default:
            break;
    }
}

void afficher_stat(int i){
    switch (i) {
        case 0:
            printf("PV ");
            break;
        case 1:
            printf("attaque ");
            break;
        case 2:
            printf("attaque spe ");
            break;
        case 3:
            printf("defense ");
            break;
        case 4:
            printf("defense spe ");
            break;
        case 5:
            printf("vitesse ");
            break;
    }
}

void afficher_attaque(attaques a){
    //     switch (a.nom) {
    //     case 0:
    //         printf("flammeche ");
    //         break;
    //     case 1:
    //         printf("pistolet a eau ");
    //         break;
    //     case 2:
    //         printf("tranche herbe ");
    //         break;
    //     case 3:
    //         printf("cage eclair ");
    //         break;
    //     case 4:
    //         printf("berceuse");
    //         break;
    //     case 5:
    //         printf("feu_follet ");
    //         break;
    //     case 6: 
    //         printf("onde_folie ");
    //         break;
    //     case 7:
    //         printf("gele");
    //         break;
    //     case 8:
    //         printf("toxic");
    //         break;
    //     case 9:
    //         printf("Danse Lames");
    //         break;
    //     case 10:
    //         printf("repli");
    //         break;
    //     case 11:
    //         printf("mimi queue");
    //         break;
    //     case 12:
    //         printf("rugissement");
    //         break;
    //     case 13:
    //         printf("danse pluie");
    //         break;
    //     case 14:
    //         printf("zénith");
    //         break;
    //     case 15:
    //         printf("tempeteneige");
    //         break;
    //     case 16:
    //         printf("tempete de sable");
    //         break;
    //     default :
    //         break;
    // }
    switch (a.nom) {
        case 0:
            printf("surf ");
            break;
        case 1:
            printf("exuvation ");
            break;
        case 2:
            printf("aurasphere ");
            break;
        case 3:
            printf("laser glace ");
            break;
        case 4:
            printf("exploforce");
            break;
        case 5:
            printf("lance_flamme ");
            break;
        case 6: 
            printf("vent_violent ");
            break;
        case 7:
            printf("toxic");
            break;
        case 8:
            printf("croissance");
            break;
        case 9:
            printf("giga sangsue");
            break;
        case 10:
            printf("puissance cachée");
            break;
        case 11:
            printf("bomb beurk");
            break;
        case 12:
            printf("direct toxic");
            break;
        case 13:
            printf("psyko");
            break;
        case 14:
            printf("vampirisme");
            break;
        case 15:
            printf("ombre portee");
            break;
        case 16:
            printf("danse draco");
            break;
        case 17:
            printf("seisme");
            break;
         case 18:
            printf("draco griffe");
            break;
         case 19:
            printf("poing feu");
            break;
         case 20:
            printf("cavalerie lourde");
            break;
         case 21:
            printf(" queue de fer");
            break;
         case 22:
            printf("lame de roc");
            break;
         case 23:
            printf("machination");
            break;
         case 24:
            printf("ball ombree");
            break;
         case 25:
            printf("tonnerre");
            break;
         case 26:
            printf("lame d'air");
            break;
         case 27:
            printf("aile acier");
            break;
         case 28:
            printf("plaquage");
            break;
         case 29:
            printf("sabotage");
            break;
         case 30:
            printf("pisto poing");
            break;
         case 31:
            printf("croc_feu");
            break;
         case 32:
            printf("eruction");
            break;
         case 33:
            printf("close combat");
            break;
         case 34:
            printf("ultralaser");
            break;
         case 35:
            printf("machouille");
            break;
        default :
            break;
    }
    // printf("( "); afficher_type(a.type); printf(" )\n");
    // printf("puissance : %d / precision : %d\n",a.puissance, a.precision);
    // if(a.application==0){
    //     if(a.phy_or_spe==0){
    //     printf("physique\n");
    // }
    // else{
    //     printf("special\n");
    // }
    // }
    // else if(a.application==1){
    //     affiche_statut(a.effet);
    // }
    // else if(a.application==2){
    //     printf("boost : +%d sur : ", a.boost);
    //     for(int i=0; i<a.nb_s;i++){
    //         afficher_stat(a.s[i]);
    //     }
    //     printf("\n");
    // }
    // else if(a.application==3){
    //     printf("nerf : -%d sur ", a.boost);
    //     for(int i=0; i<a.nb_s;i++){
    //         afficher_stat(a.s[i]);
    //     }
    //     printf("\n");
    // }
    // else if(a.application==4){
    //     afficher_meteo(a.Meteo);
    // }

}

void afficher_etat(statut s){
    
    switch (s) {
        case 0:
            printf("neutre\n");
            break;
        case 1:
            printf("paraliser\n");
            break;
        case 2:
            printf("empoisoner\n");
            break;
        case 3:
            printf("endormie\n");
            break;
        case 4:
            printf("bruler\n");
            break;
        case 5:
            printf("confus\n");
            break;
        case 6:
            printf("geler\n");
            break;
        default :
            break;
    }
}

void afficher_meteo(statut2 s){
     switch (s) {
        case 0:
            printf("rien \n");
            break;
        case 1:
            printf("pluie\n");
            break;
        case 2:
            printf("tempete\n");
            break;
        case 3:
            printf("grele\n");
            break;
        case 4:
            printf("soleil\n");
            break;
        default :
            break;
    }
}

pokemon creer_pokemon(char *nomP, Types t,attaques att[], int nb, stats S){
    pokemon poke;
    int i;
    poke.nom=nomP;
    poke.type=t;
    poke.nb_attaque=nb;
    for (i=0;i<nb;i++){
        poke.attaque[i]=att[i];
    }
    poke.stat=S;
    poke.etat = neutre ;
    return poke;
}

//renvoie un tableau de pokemon avec nom,attaque,types..
void creer_pokedex(pile p){
//         stats S={146,146,104,104,0,95,95,0,112,112,0,102,102,0,117,117,0};
//    attaques A[4]={{flammeche,feu,0,100,40,1},{feu_follet,feu,1,100,0,-1,brulure},{danse_lames,acier,2,100,0,-1,neutre,2,2,{1,2}},{toxic,poison,1,100,0,-1,empoisoner}};
//    push(creer_pokemon("salameche",feu,A,4,S),p);
//    stats S2={151,151,100,100,0,117,117,0,102,102,0,116,116,0,95,95,0};
//    attaques A2[4]={{pistolet_a_eau,eau,0,100,40,1},{gele,glace,1,100,0,-1,geler},{tempeteneige,glace,4,100,0,-1,neutre,-1,-1,{-1},grele}};
//    push(creer_pokemon("carapuce",eau, A2,3,S2),p);
//    stats S3={152,152,101,101,0,101,101,0,117,117,0,117,117,0,97,97,0};
//    attaques A3[4]={{tranche_herbe,plante,0,100,40,1},{danse_pluie,eau,4,100,0,-1,neutre,-1,-1,{-1},pluie},{flammeche,feu,0,100,40,1},{pistolet_a_eau,eau,0,100,40,1}};
//    push(creer_pokemon("bulbizare",plante,A3,4,S3),p);

//    stats S4={162,162,120,120,0,116,116,0,97,97,0,107,107,0,83,83,0};
//    attaques A4[4]={{tranche_herbe,plante,0,100,40,1},{onde_folie,normal,1,100,0,-1,confusion}};
//    push(creer_pokemon("tortipouss",plante,A4,2,S4),p);
//    stats S5={160,160,103,103,0,105,105,0,113,113,0,108,108,0,92,92,0};
//    attaques A5[4]={{pistolet_a_eau,eau,0,100,40,1},{berceuse,normal,1,100,0,-1,endormie},{tempete_de_sable,roche,4,100,0,-1,neutre,-1,-1,{-1},tempete}};
//    push(creer_pokemon("tiplouf",eau, A5,3,S5),p);
//    stats S6={151,151,110,110,0,96,96,0,110,110,0,96,96,0,113,113,0};
//    attaques A6[4]={{flammeche,feu,0,100,40,1},{cage_eclair,electrique,1,100,0,-1,paraliser},{zenith,feu,4,100,0,-1,neutre,-1,-1,{-1},soleil}};
//    push(creer_pokemon("ouisticram",feu,A6,3,S6),p);
    stats S1={186,186,135,135,0,152,152,0,137,137,0,157,157,0,130,130,0};
    attaques A[4]= {{surf,eau,0,100,90,1},{laser_glace,glace,0,100,90,1},{aurasphere,combat,0,100,80,1},{exuviation,normal,2,100,0,-1,-1,2,3,{1,2,5}}};
    push(creer_pokemon("Tortoise",eau,A,4,S1),p);
    stats S2={185,185,136,136,0,130,130,0,161,161,0,137,137,0,152,152,0};
    attaques A2[4]={{lance_flamme,feu,0,100,90,1},{toxic,poison,1,90,0,-1,empoisoner},{vent_violent,vol,0,70,110,1},{exploforce,combat,0,70,120,1}};
    push(creer_pokemon("Charizard",feu,A2,4,S2),p);
    stats S3={187,187,134,134,0,135,135,0,152,152,0,152,152,0,132,132,0};
    attaques A3[4] = {{croissance,plante,2,100,0,-1,-1,1,2,{1,2}},{giga_sangsue,plante,0,100,75,1},{puissance_cachee,feu,0,100,60,1},{bomb_beurk,poison,0,100,90,1}};
    push(creer_pokemon("Venusaur",plante,A3,4,S3),p);
    stats S4={177,177,142,142,0,122,122,0,112,112,0,122,122,0,92,92,0};
    attaques A4[4] = {{direct_toxic,poison,0,100,80,0},{psyko,psy,0,100,90,1},{vampirisme,insecte,0,100,80,0},{ombre_portee,spectre,0,100,40,1}} ;
    push(creer_pokemon("Ariados",insecte,A4,4,S4),p);
    stats S5={198,198,186,186,0,147,147,0,152,152,0,152,152,0,132,132,0};
    attaques A5[4] = {{danse_draco,dragon,2,100,0,1,-1,1,2,{1,5}},{seisme,sol,0,100,100,0},{draco_griffe,dragon,0,100,80,0},{poing_feu,feu,0,100,75,0}} ;
    push(creer_pokemon("Dragonite",dragon,A5,4,S5),p);
    stats S6={142,142,97,97,0,212,212,0,82,82,0,97,97,0,122,122,0};
    attaques A6[4] = {{seisme,sol,0,100,100,0},{cavalerie_lourde,sol,0,95,95,0},{queue_fer,acier,0,75,100,0},{lame_de_roc,roche,0,85,100,0}};
    push(creer_pokemon("Onix",roche,A6,4,S6),p);
    stats S7={167,167,142,142,0,107,107,0,142,142,0,132,132,0,152,152,0}; 
    attaques A7[4] = {{tonnerre,electrique,0,100,90,1},{surf,eau,0,100,90,1},{exploforce,combat,0,70,120,1},{machination,spectre,2,100,0,-1,-1,2,1,{2}}};
    push(creer_pokemon("Raichu",electrique,A7,4,S7),p);
    stats S8={162,162,102,102,0,97,97,0,187,187,0,147,147,0,172,172,0};
    attaques A8[4] ={{exploforce,combat,0,70,120,1},{ball_ombre,spectre,0,100,80,1},{psyko,psy,0,100,90,1},{machination,spectre,2,100,0,-1,-1,2,1,{2}}} ;
    push(creer_pokemon("Alakazam",psy,A8,4,S8),p);
    stats S9={190,190,132,132,0,127,127,0,122,122,0,122,122,0,143,143,0};
    attaques A9[4] = {{vent_violent,vol,0,70,110,1},{Lame_dair,vol,0,95,75,1},{aile_acier,acier,0,90,70,0},{ultralaser,normal,0,90,120,1}} ;
    push(creer_pokemon("Pidgeot",vol,A9,4,S9),p);
    stats S10={267,267,162,162,0,117,117,0,117,117,0,162,162,0,82,82,0};
    attaques A10[4] = {{laser_glace,glace,0,100,95,1},{ultralaser,normal,0,90,120,1},{plaquage,normal,0,100,85,0},{seisme,sol,0,100,100,0}} ;
    push(creer_pokemon("Snorlax",normal,A10,4,S10),p);
    stats S11={197,197,182,182,0,132,132,0,117,117,0,137,137,0,107,107,0};
    attaques A11[4] = {{close_combat,combat,0,90,120,0},{pisto_poing,acier,0,100,50,0},{sabotage,tenebre,0,100,65,0},{lame_de_roc,roche,0,85,100,0}};
    push(creer_pokemon("Machamp",combat,A11,4,S11),p);
    stats S12={167,167,147,147,0,121,121,0,117,117,0,131,131,0,132,132,0};
    attaques A12[4] = {{eruction,poison,0,80,120,0},{direct_toxic,poison,0,100,80,0},{croc_feu,feu,0,95,65,0},{machouille,tenebre,0,100,80,0}} ;
    push(creer_pokemon("Harbok",poison,A12,4,S12),p);
}

void afficher_pokemon(pokemon poke){
    printf("------------------------------------\n");
    printf("%s\n",poke.nom);
    printf("          ATTAQUE              \n");
    for (int i=0; i<poke.nb_attaque; i++){
        printf(" - ");
        afficher_attaque(poke.attaque[i]);
    }
    // printf("          TYPE              \n");
    // afficher_type(poke.type);
    printf("\n");
    printf("          STATS             \n");
    printf("PV_max : %d  ",poke.stat.PV_max); 
    printf("PV : %d\n",poke.stat.PV); 
    // printf("att : %d\n",poke.stat.attaque); 
    // printf("att_spe : %d\n",poke.stat.attaque_spe); 
    // printf("def : %d\n",poke.stat.defense); 
    // printf("def_spe : %d\n",poke.stat.defense_spe); 
    // printf("vitesse : %d\n",poke.stat.vitesse); 
    // printf("          ETAT           \n");
    // afficher_etat(poke.etat);
     printf("------------------------------------\n");
}

void afficher_pokedex(pile p){
    int i;
    cellule *cel=p->top;
    for (i=0;i<p->size;i++){
        printf("%d - ",i);
        afficher_pokemon(cel->poke);
        cel=cel->suiv;
    }
}

// int main(){
//     pile p=create_empty_stack();
//     creer_pokedex(p);
//     afficher_pokedex(p);
//     return 0;
    
// }