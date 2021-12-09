#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8
typedef int tableau[N];

void affichetab(int t[]){
    for(int i=0; i<N-1; i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}

void tri_selection_croissant(tableau t){
    int minind,temp;
    for(int i = 0; i < N-1; i++){
        minind = i;
        for(int j = i+1; j < N; j++)
            if(t[j] < t[minind]){
                minind = j;
            }
        if(minind!=i){
            temp = t[i];
            t[i] = t[minind];
            t[minind] = temp;
        }
    }
}

void tri_selection_decroissant(tableau t){
    int maxind,temp;
    for(int i = 0; i <N-1; i++){
        maxind = i;
        for(int j = i+1; j < N; j++)
            if(t[j] > t[maxind]){
                maxind = j;
            }
        if(maxind!=i){
            temp = t[i];
            t[i] = t[maxind];
            t[maxind] = temp;
        }
    }
}

void triCocktail(int liste[N]) {
	bool echange = true;
	int temp;
	while (echange==true) {
		echange = false;
		for (int indTab = 0; indTab < N-1; indTab++) {
			if (liste[indTab] > liste[indTab+1]) {
				temp = liste[indTab];
				liste[indTab] = liste[indTab+1];
				liste[indTab+1] = temp;
				echange = true;
			}
		}
		for (int indTab = N-1; indTab > 1; indTab--) {
			if (liste[indTab] < liste[indTab-1]) {
				temp = liste[indTab];
				liste[indTab] = liste[indTab-1];
				liste[indTab-1] = temp;
				echange = true;
			}
		}
	}
}

void triCocktailDecr(int liste[N]) {
	bool echange = true;
	int temp;
	while (echange==true) {
		echange = false;
		for (int indTab = 0; indTab < N-1; indTab++) {
			if (liste[indTab] < liste[indTab+1]) {
				temp = liste[indTab];
				liste[indTab] = liste[indTab+1];
				liste[indTab+1] = temp;
				echange = true;
			}
		}
		for (int indTab = N-1; indTab > 1; indTab--) {
			if (liste[indTab] > liste[indTab-1]) {
				temp = liste[indTab];
				liste[indTab] = liste[indTab-1];
				liste[indTab-1] = temp;
				echange = true;
			}
		}
	}
}

// tri fusion croissant
void fusion_croissant(int arr[N], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void tri_fusion_croissant(int tablo[N], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        tri_fusion_croissant(tablo, l, m);
        tri_fusion_croissant(tablo, m + 1, r);
        fusion_croissant(tablo, l, m, r);
    }
}


// tri fusion décroissant
void fusion_decroissant(int t[],int debut, int milieu, int fin){
    int taille1 = milieu - debut + 1;
    int taille2 = fin - milieu;

    int gauche[taille1], droite[taille2];

    for (int i = 0; i < taille1; i++)
            gauche[i] = t[debut + i];
    for (int j = 0; j < taille2; j++)
            droite[j] = t[milieu + 1 + j];

    int indG, indD, indice;
    indG = 0;
    indD = 0;
    indice = debut;

    while(indG < taille1 && indD < taille2){
        if(gauche[indG] > droite[indD]){
            t[indice] = gauche[indG];
            indG++;
        }else{
            t[indice] = droite[indD];
            indD++;
        }
        indice++;
    }

    while (indG < taille1)
        {
            t[indice] = gauche[indG];
            indG++;
            indice++;
        }
     
        while (indD < taille2)
        {
            t[indice] = droite[indD];
            indD++;
            indice++;
        }
}

void tri_fusion_decroissant(int t[], int debut, int fin){
    if(debut < fin){
        int milieu = (debut + fin) / 2; // trouve le milieu
        tri_fusion_decroissant(t, debut, milieu);
        tri_fusion_decroissant(t, milieu + 1, fin);

        fusion_decroissant(t, debut, milieu, fin);
    }
}




int main(){
    int t1[8]={10,16,-9,4,8,6,18,-6}; 

    tri_fusion_decroissant(t1,0,N-1);
    affichetab(t1);
    return EXIT_SUCCESS;
}