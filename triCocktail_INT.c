#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 30
#define N 50

typedef int tab[N];

void alea(tab);
void triCocktail(tab); 


int main() {
    tab tablo ;
    alea(tablo);
    triCocktail(tablo);
}

void triCocktail(tab tablo){
    clock_t temps;
    long int debut,fin;
    debut = 0;
    fin = 0 ;
    
    bool echange;
    int tmp;
    echange = true ;
    while(echange == true){
        echange = false ;
        for(int i = 0 ; i < N - 1 ; i++){
            debut++;
            if (tablo[i] > tablo[i+1]){
                tmp=tablo[i];
                tablo[i]=tablo[i+1];
                tablo[i+1]=tmp;
                echange= true ;
                fin++;
            }
        }
    }
    temps=clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n",(double) temps/CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n",debut);
    printf("Nombre de permutations : %d\n",fin);
    printf("===================================================\n");
}

void alea(tab tablo){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        tablo[i]=rand() % RAND_MAX ;
    }
}

