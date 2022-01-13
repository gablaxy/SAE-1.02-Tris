#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOTS 150000
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


void triFusion(int i, int j, tabAlea tablo, tabAlea tmp,int * debut,int * fin) {
    if (j <= i) { 
        return;
    }
    int m = (i + j) / 2;
    triFusion(i, m, tablo, tmp,&*debut,&*fin);
    triFusion(m + 1, j, tablo, tmp,&*debut,&*fin);
    int stg = i;
    int std = m + 1;
    int count;
    for (count = i; count <= j; count++) {
        *debut=*debut+1;
        if(stg == m + 1) {
            strcpy(tmp[count],tablo[std]);
            std++;
        } else if (std == j + 1) {
            strcpy(tmp[count],tablo[stg]);
            stg++;
        } else if (strcmp(tablo[stg],tablo[std]) < 0 ) {
            strcpy(tmp[count],tablo[stg]);
            stg++;
            *fin=*fin+1;
        } else {
            strcpy(tmp[count],tablo[std]);
            std++;
        }
    }
    for (count = i; count <= j; count++) {
        strcpy(tablo[count],tmp[count]);
    }
}

int main(){
    clock_t temps;
    int debut,fin;
    debut = 0;
    fin = 0 ;
    tabAlea autre = {"aa","aa","aa","aa","aa","aa","aa","aa","aa","aa"};
    aleatoire(tab);
    triFusion(0, MOTS-1, tab, autre,&debut,&fin);
    temps=clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n",(double) temps/CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n",debut);
    printf("Nombre de permutations : %d\n",fin);
    printf("===================================================\n");
    return 0;
}
