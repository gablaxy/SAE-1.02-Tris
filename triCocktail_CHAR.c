#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MOTS 30
#define MOTS_LEN 11 
#define AFFICHE 30 

typedef char tabAlea[MOTS][MOTS_LEN];

tabAlea tab;

void aleatoire(char tab[MOTS][MOTS_LEN]) {
    int valeur;
    srand(time(NULL));
    for (int j = 0; j < MOTS; j++) {
        valeur = (rand() %6 +5);
        for (int i = 0; i < valeur; i++) {
            tab[j][i]= (rand()%26 +'a') ;
        }
    }
}

void triCocktail(tabAlea tablo) {
    clock_t temps; 
    long int ct,cpt;
    ct = 0; 
    cpt = 0 ;
    bool echange;
    char tmp[10];
    echange = true ;
    while(echange == true){
        echange = false ;
        for(int i = 0 ; i < MOTS - 1 ; i++) {
            ct++;
            if (strcmp(tablo[i+1], tablo[i]) < 0 ) {
                strcpy(tmp,tablo[i]);
                strcpy(tablo[i],tablo[i+1]);
                strcpy(tablo[i+1],tmp);
                echange= true ;
                cpt++;
            }
        }
    }
    temps=clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n",(double) temps/CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n",ct);
    printf("Nombre de permutations : %d\n",cpt);
    printf("===================================================\n");
}

int main(){
    aleatoire(tab);
    triCocktail(tab);
}



