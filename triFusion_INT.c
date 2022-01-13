#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 30
#define N 500000
typedef int tab[N];

void alea(tab);
void triFusion(int,int,tab,tab,int *,int *);

int main() {
    clock_t temps;
    tab tablo ;
    tab autre = {0,0,0,0,0,0,0,0,0,0};
    int  i;
    int debut,fin;
    debut = 0;
    fin = 0 ;
    alea(tablo);
    triFusion(0, N-1, tablo, autre,&debut,&fin);
    temps=clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n",(double) temps/CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n",debut);
    printf("Nombre de permutations : %d\n",fin);
    printf("===================================================\n");
}

void triFusion(int i, int j, tab tablo, tab tmp,int * debut,int * fin) {
    if(j <= i) { 
        return;
    }
    int m = (i + j) / 2;
    triFusion(i, m, tablo, tmp,&*debut,&*fin);
    triFusion(m + 1, j, tablo, tmp,&*debut,&*fin); 
    int stg = i;
    int std = m + 1;
    int count;
    for(count = i; count <= j; count++) {
        *debut=*debut+1;
        if(stg == m + 1) {
            tmp[count] = tablo[std];
            std++;
        }else if (std == j + 1) {
            tmp[count] = tablo[stg];
            stg++;
        }else if (tablo[stg] < tablo[std]) {
        *fin=*fin+1;
            tmp[count] = tablo[stg];
            stg++;
        }else {
            tmp[count] = tablo[std];
            std++;
        }
    }
    for(count = i; count <= j; count++) {
        tablo[count] = tmp[count];
    }
}

void alea(tab tablo){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        tablo[i]=rand() % RAND_MAX ;
    }
}