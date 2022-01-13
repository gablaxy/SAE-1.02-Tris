#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 30
#define N 500

typedef int tab[N]; 

void alea(tab);
void triSelection(tab);
void echange(tab,int,int);
void afficher(tab);

int main(){
    tab unTab ;
    alea(unTab);
    triSelection(unTab);
    return EXIT_SUCCESS;
}

void echange(tab t, int i, int j) { 
    int tmp;
    tmp=t[i];
    t[i]=t[j];
    t[j]=tmp;
}

void triSelection(tab t){
    clock_t temps; 
    long int ct,cpt;
    ct = 0;
    cpt = 0 ;
    int i,j,min,indmin;
    for(i=0 ; i<N -1; i++){
        min=t[i];
        indmin=i;
        for(j=i+1;j<N;j++){
        ct++;
            if (t[j]<min){
                min=t[j];
                indmin=j;
                cpt++;
            }
        }
       echange(t,i,indmin);
    }
    temps=clock();
    printf("===================================================\n");
    printf("Temps d'éxecution : %f secondes \n",(double) temps/CLOCKS_PER_SEC);
    printf("Nombre de verifications : %d\n",ct);
    printf("Nombre de permutations : %d\n",cpt);
    printf("===================================================\n");
}

void alea(tab unTab){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        unTab[i]=rand() % RAND_MAX ;
    }
}


