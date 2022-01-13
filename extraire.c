#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBVAL 17776

typedef struct {
    int dep;            // n° du département (22, 29, 35 ou 56)
    
    char date[11];      // date sous la forme aaaa-mm-jj
                        // exemple : 2020-05-23
    
    int pos;            // nombre de cas enregistrés ce jour-là
                        // dans cette classe d’âge et dans ce
                        // département
    
    int classe;         // tranche d’âge. La valeur 9 représente la
                        // tranche d’âge [0 - 9 ans], la valeur 19
                        // représente la tranche d’âge [10 – 19 ans],
                        // etc. jusqu’à la valeur 90 qui représente les
                        // 90 ans ou plus.
                        // Attention, la tranche d’âge 0 est un
                        // récapitulatif qui représente toutes les
                        // classes d’âge
    
    int pop;            // nombre d’habitants de cette tranche d’âge
                        // dans ce département
} donnees;

typedef donnees t_donnees[NBVAL];


// procédure permettant d'aller chercher les données d'un fichier et les mettres dans un tableau de structures
// paramètres : le nom du fichier d'où on extrait les données et le tableau où on va mettre ces dernières
void LireFichier(char nomFichier[20], t_donnees t_covid) {
    FILE * fic;
    int compteur = 0;
    fic = fopen(nomFichier, "rb");
    fread(&t_covid[compteur], sizeof(donnees), 1, fic);
    while (!feof(fic)) {
        compteur++;
        fread(&t_covid[compteur], sizeof(donnees), 1, fic);
    }
    fclose(fic);
}

// procédure pour trier le tableau par le département
// paramètres : le tableau, son indice de début et de fin
void triDepartement(t_donnees tab,int debut,int fin){
    int i, j, pivot;
    donnees temp;

    if(debut<fin){
        pivot=debut;
        i=debut;
        j=fin;

        while(i<j){
            while(tab[i].dep <= tab[pivot].dep && i<fin)
                i++;

            while(tab[j].dep > tab[pivot].dep)
                j--;

            if(i < j){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }

        temp = tab[pivot];
        tab[pivot] = tab[j];
        tab[j] = temp;

        triDepartement(tab,debut,j-1);
        triDepartement(tab,j+1,fin);
    }
}

// fonction renvoyant la population des Côtes d'Armor
// paramètres : le tableau
int population22(t_donnees tab){
    int departement = 0;
    int classe = -1;

    for(int i=0; i < NBVAL; i++){
        departement = tab[i].dep;
        classe = tab[i].classe;
        if(classe == 0 && departement == 22){
            return tab[i].pop;
        }
        i++;
    }
    return EXIT_FAILURE;
}

// procédure pour trier le tableau par la date
// paramètres : le tableau, son indice de début et de fin
void triDate(t_donnees tab,int debut,int fin){
    int i, j, pivot;
    donnees temp;

    if(debut<fin){
        pivot=debut;
        i=debut;
        j=fin;

        while(i<j){
            while((strcmp(tab[i].date, tab[pivot].date) <= 0) && i<fin)
                i++;

            while(strcmp(tab[j].date, tab[pivot].date) > 0)
                j--;

            if(i < j){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }

        temp = tab[pivot];
        tab[pivot] = tab[j];
        tab[j] = temp;

        triDate(tab,debut,j-1);
        triDate(tab,j+1,fin);
    }
}

// procédure pour trier le tableau par la tranche d'âge
// paramètres : le tableau, son indice de début et de fin
void triClasse(t_donnees tab,int debut,int fin){
    int i, j, pivot;
    donnees temp;

    if(debut<fin){
        pivot=debut;
        i=debut;
        j=fin;

        while(i<j){
            while(tab[i].classe <= tab[pivot].classe && i<fin)
                i++;

            while(tab[j].classe > tab[pivot].classe)
                j--;

            if(i < j){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }

        temp = tab[pivot];
        tab[pivot] = tab[j];
        tab[j] = temp;

        triClasse(tab,debut,j-1);
        triClasse(tab,j+1,fin);
    }
}


// procédure remplissant un tableau de structure des données concernant le nombre de cas en Ille-et-Vilaine le 1er janvier 2021
// paramètres : le tableau de base
void DebutAnne35(t_donnees tab){
    t_donnees t_cas1erjanvier;
    int y = 0;
    printf("Nombre de cas en Ille-et-Vilaine par classe d'age, le 1er janvier 2021\n");
    printf("\n");
    for(int i=0; i<NBVAL; i++){
        if(tab[i].dep == 35 && (strcmp(tab[i].date,"2021-01-01") == 0 )){
            t_cas1erjanvier[y] = tab[i];
            y++;
        }
    }
    triClasse(t_cas1erjanvier,0,10);

    printf("[  0 -  9 ] : %d\n", t_cas1erjanvier[1].pos);
    printf("[ 10 - 19 ] : %d\n", t_cas1erjanvier[2].pos);
    printf("[ 20 - 29 ] : %d\n", t_cas1erjanvier[3].pos);
    printf("[ 30 - 39 ] : %d\n", t_cas1erjanvier[4].pos);
    printf("[ 40 - 49 ] : %d\n", t_cas1erjanvier[5].pos);
    printf("[ 50 - 59 ] : %d\n", t_cas1erjanvier[6].pos);
    printf("[ 60 - 69 ] : %d\n", t_cas1erjanvier[7].pos);
    printf("[ 70 - 79 ] : %d\n", t_cas1erjanvier[8].pos);
    printf("[ 80 - 89 ] : %d\n", t_cas1erjanvier[9].pos);
    printf("[ 90 - 99 ] : %d\n", t_cas1erjanvier[10].pos);
    printf("\n");
    printf("TOTAL : %d\n", t_cas1erjanvier[0].pos);
}

int main(){
    t_donnees t_covid;
    LireFichier("DonneesCovid.data", t_covid);

    triDepartement(t_covid, 0, NBVAL);
    /*
    for(int i = 0; i < NBVAL; i++){
        printf("%d %s %d %d %d \n", t_covid[i].dep, t_covid[i].date, t_covid[i].pos, t_covid[i].classe, t_covid[i].pop);
    }
    */

    printf("Population du 22 : %d\n", population22(t_covid));

    triDate(t_covid, 0, NBVAL);

    printf("\n");

    DebutAnne35(t_covid);
}
