# Les tris (SAE1.01)
:man_student: Projet de BUT 1ère Année Informatique dans lequel nous experimentons autour des differents modèles de tris.

## Étape 2 : tridept()

Reçoit en entrée le tableau de structure, trie en utilisant struct.dept et donc trier les lignes par département.

## Étape 3 : pop22()

Reçoit en entrée le tableau de structure, le trie par département en utilisant tridept(), puis trouve la ligne où struct.dept == 22 et struct.classe == 0, on renvoie le struct.pop de la ligne.

## Étape 4 : tridate()

Reçoit en entrée le tableau de structure, formate les dates en changeant le format "2020-10-12" en un format "20201012", puis utilise le tri croissant pour les trier.

## Étape 5 : debutAnnee35()

Reçoit en entrée le tableau de structure, trier par département le tableau en utilisant tridept() ( ne garder que les 35 si possible ), utiliser une fonction comparaison pour comparer les struct.classe entre elles et les trier, chercher seulemenent les lignes où strcmp(struct.date,"2021-01-01") == 0, et les renvoyer. 
