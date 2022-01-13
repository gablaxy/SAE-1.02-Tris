#include <stdio.h>
#include <stdlib.h>
#define NBVAL 17776
typedef struct {
    int dep;            // n° du département (22, 29, 35 ou 56)
    char date[11];        // date sous la forme aaaa-mm-jj
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

void LireFichier(char nomFichier[20], t_donnees t_covid) {
    FILE * fic;
    int compteur = 0;
    fic = fopen(nomFichier, "rb");
    fread(&t_covid[compteur], sizeof(donnees), 1, fic);
    while (!feof(fic)) {
        compteur++;
        fread(&t_covid[compteur], sizeof(donnees), 1, fic);
    }
    printf("%d\n", compteur);
    fclose(fic);
}

int main() {
    t_donnees t_covid;
    LireFichier("DonneesCovid.data", t_covid);
    printf("%d %s %d %d %d", t_covid[0].dep, t_covid[0].date, t_covid[0].pos, t_covid[0].classe, t_covid[0].pop);
}