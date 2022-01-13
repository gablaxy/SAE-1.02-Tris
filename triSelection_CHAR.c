#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOTS 30
#define MOTS_LEN 11
#define AFFICHE 30

typedef char tabAlea[MOTS][MOTS_LEN];

tabAlea tab;

void aleatoire(char tab[MOTS][MOTS_LEN]) {
    int valeur;
    srand(time(NULL));
    for (int j = 0; j < MOTS; j++) {
        valeur = (rand() % 6 + 5);
        for (int i = 0; i < valeur; i++) {
            tab[j][i] = (rand() % 26 + 'a');
        }
    }
}

void triSelection(tabAlea tab) {
    clock_t temps;
    long int ct, cpt;
    ct = 0;
    cpt = 0;
    int pos_sup;
    char temp[MOTS_LEN];
    for (int i = 0; i < MOTS; i++) {
        pos_sup = i;
        for (int j = i + 1; j < MOTS; j++) {
            ct++;
            if (strcmp(tab[j], tab[pos_sup]) < 0) {
                pos_sup = j;
                cpt++;
            }
        }
        strcpy(temp, tab[i]);
        strcpy(tab[i], tab[pos_sup]);
        strcpy(tab[pos_sup], temp);
    }
    temps = clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n", (double)temps / CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n", ct);
    printf("Nombre de permutations : %d\n", cpt);
    printf("===================================================\n");
}

int main() {
    aleatoire(tab);
    triSelection(tab);
}