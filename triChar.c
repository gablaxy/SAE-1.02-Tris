/* Gabin LAVAZAIS, 
   Lucien HERVE,
   INFO1 J2
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define N 150
#define MAX 10
typedef char tab[N][MAX];
typedef char lettres[26];

int nbAlea(){
    return rand()%26;
}

int tailleAlea(){
    int n;
    n=rand()%5;
    return n + 5;
}

void generateCharTab(tab t){
    lettres car={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0; i < N; i++){
        for (int j=0;j<tailleAlea();j++){
            t[i][j]=car[nbAlea()];
        }
    } 
}

void afficher(tab t){
    for (int i=0;i<N;i++){
        printf("%s\n",t[i]);
    }
}

void tri_selection_croissant(tab t, int taille){
    int minind;
    char temp[11];
    for(int i = 0; i < taille-1; i++){
        minind = i;
        for(int j = i+1; j < taille; j++)
            if(strcmp(t[j], t[minind])<0){
                minind = j;
            }
        if(minind!=i){
            strcpy(temp,t[i]);
            strcpy(t[i],t[minind]);
            strcpy(t[minind],temp);
        }
    }
}


void tri_selection_decroissant(tab t, int taille){
    int maxind;
    char temp[11];
    for(int i = 0; i <taille-1; i++){
        maxind = i;
        for(int j = i+1; j < taille; j++)
            if(strcmp(t[j],t[maxind])>0){
                maxind = j;
            }
        if(maxind!=i){
            strcpy(temp,t[i]);
            strcpy(t[i],t[maxind]);
            strcpy(t[maxind],temp);
        }
    }
}

void triCocktail(tab liste) {
	bool echange = true;
	char temp[11];
	while (echange==true) {
		echange = false;
		for (int indTab = 0; indTab < N-1; indTab++) {
			if (strcmp(liste[indTab],liste[indTab+1])>0) {
				strcpy(temp,liste[indTab]);
				strcpy(liste[indTab],liste[indTab+1]);
				strcpy(liste[indTab+1],temp);
				echange = true;
			}
		}
		for (int indTab = N-1; indTab > 1; indTab--) {
			if (strcmp(liste[indTab],liste[indTab-1])<0) {
				strcpy(temp,liste[indTab]);
				strcpy(liste[indTab],liste[indTab-1]);
				strcpy(liste[indTab-1],temp);
				echange = true;
			}
		}
	}
}

void triCocktailDecroissant(tab liste) {
	bool echange = true;
	char temp[11];
	while (echange==true) {
		echange = false;
		for (int indTab = 0; indTab < N-1; indTab++) {
			if (strcmp(liste[indTab],liste[indTab+1])<0) {
				strcpy(temp,liste[indTab]);
				strcpy(liste[indTab],liste[indTab+1]);
				strcpy(liste[indTab+1],temp);
				echange = true;
			}
		}
		for (int indTab = N-1; indTab > 1; indTab--) {
			if (strcmp(liste[indTab],liste[indTab-1])>0) {
				strcpy(temp,liste[indTab]);
				strcpy(liste[indTab],liste[indTab-1]);
				strcpy(liste[indTab-1],temp);
				echange = true;
			}
		}
	}
}

void fusionCroissant(tab tablo, int deb,int milieu, int fin){
    int tailleGauche=milieu-deb+1;
    int tailleDroite=fin-milieu;
    tab tabGauche;
    tab tabDroite;
    for (int i=0; i < tailleGauche; i++){
        strcpy(tabGauche[i], tablo[deb+i]);
    }
    for (int j=0; j < tailleDroite;j++){
        strcpy(tabDroite[j], tablo[milieu+1+j]);
    }
    int a=0;
    int b=0;
    int indice=deb;
    while ((a<tailleGauche)&&(b<tailleDroite)){
        if (strcmp(tabGauche[a], tabDroite[b])<=0){
            strcpy(tablo[indice], tabGauche[a]);
            a++;
        } else {
            strcpy(tablo[indice], tabDroite[b]);
            b++;
        }
        indice++;
    }
    while (a<tailleGauche){
        strcpy(tablo[indice], tabGauche[a]);
        a++;
        indice++;
    }
    while (b<tailleDroite){
        strcpy(tablo[indice], tabGauche[b]);
        b++;
        indice++;
    }
}

void triFusionCroissant(tab tablo, int deb, int fin){
    if (deb < fin) {
        int milieu=(deb+fin)/2;
        triFusionCroissant(tablo, deb, milieu);
        triFusionCroissant(tablo, milieu+1, fin);
        fusionCroissant(tablo, deb, milieu, fin);
    }
}

int main() {
    tab tablo = {0};
    generateCharTab(tablo);
    triFusionCroissant(tablo, 0, N);
    afficher(tablo);
}
