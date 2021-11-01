# ✅ push_swap
Push_swap (42cursus) 2020-2021. Here the aim is to sort data stacks, using the lowest possible number of actions.

- Actual Status : finished.
- Result        : 125%
# Push_swap

**Ce projet vous demande de trier des données sur une pile, avec un set
d’instructions limité, en moins de coups possibles. Pour le réussir, vous devrez
manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.**
→ Pour réaliser une pile j'ai choisi d'implémenter des listes chaînées "simples" (=non doubles).
→ Nous allons garder les éléments déjà "triés" dans A et pousser les autres sur B puis nous  allons évaluer le nombre minimum d'actions nécessaires pour trier un élément et le déplacer au bon index pour B puis nous allons réitérer l'opération jusqu'à ce que la pile B soit bien vide et la pile A soit bien triée.
→ La méthode que nous allons implémenter est un savant melting pot des meilleurs algorithmes réalisés pour ce sujet.

## Méthode

1. Dans un premier temps j'ai crée une copie de ma stack A (une fois les actions implémentées et les celle-ci remplie).
2. Je réalise un bubble sort sur cette copie afin de pouvoir déterminer par la suite le target index de chaque élément sur la stack A.
3. Une fois le target index noté, je vais évaluer pour chaque élément s'il est trié dans un ordre croissant par rapport au suivant.
4. Chaque élément possède un champ "keep" qui sera noté à true ou à false en fonction de s'il est inferieur au suivant ou non.
5. Je vais ensuite chercher la plus longue suite keep=true;
6. Je push tout ce qui n'est pas dans cette suite sur B. 
7. Sur B, pour chaque element, je calcule combien il va falloir d'actions (sur B et sur A) pour le trier (independamment des autres).
8. Je trie donc l'element qui a besoin du moins d'action (en "optimisant" intelligemment les actions).
9. Je boucle ainsi jusqu'a ce que B soit vide.
10. Je retrie A si necessaire pour que la plus petite valeur soit en haut de la liste. 
11. C'est termine ! 

Vous pouvez observer ce fonctionnnement grace au visualiseur python qui a ete fait. 

## Cas des doublons

Nous ne devons pas trier les listes contenant des doublons. Une façon optimale de les éviter est de faire le tour de la liste chainée à chaque ajout d'un nouvel élément et de stopper le programme si des doublons sont trouvés. Rappelons que notre unique objectif et d'effectuer le moins "d'actions" de tris autorisées. Cela ne signifie pas qu'il est interdit de faire des calculs préalables.

# 🥇 Bonus

### Checker

Votre projet contient deux exécutables, mais vous n'avez pas besoin de faire deux Makefile. Vous pouvez regrouper les différents fichiers sources communs et distincts aux deux, puis creer différentes règles pour générer les deux exécutables. 

Pour la réalisation du bonus, votre get_next_line vous sera très utile.

## Tests

```c
$ ./push_swap 4 5 -2 10 1 | ./checker 4 5 -2 10 1
//Autre possibilité pour éviter d'avoir a retaper les arguments 
$ ARG="10 4 5 -2 1 6"; ./push_swap $ARG | ./checker $ARG
/* Pour compter rapidement le nombre d'actions que vous effectuez / imprimez */
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

```c
/* tester le programme avec le checker officiel */
ARG="10 4 32"; ./push_swap $ARG | ./checker_Mac $ARG
/* tester uniquement le comportement du checker officiel */
ARG="2 43 2";  ./checker_Mac $ARG
```

```c
/* Commande pour générer des suites de chiffres à des fins de test */ 
$ ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

/* Lancer le visualiseur python après la compilation - Marche sur les mac */
/* Attention pour utiliser le fichier pyviz.y il faut que vous l'ayez telecharge */
/* https://raw.githubusercontent.com/o-reo/push_swap_visualizer/master/pyviz.py */
$ python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`

/* Generateur randon + checker officiel */
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG

/* Generer des arguments et compter */
ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

//Commande pour "tout faire" 
make && python3 pyviz.py `ruby -e "puts (0..500).to_a.shuffle.join(' ')"`

/*Partie valgrind */
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; valgrind --leak-check=full ./push_swap $ARG
```

## Erreurs courantes

Attention pour push_swap il est préférables de ne pas garder votre atoi tel qu'il puisqu'aucune lettre ne doit être acceptée

```c
/* To test */
./push_swap a b
./push_swap 7a 8a 
./push_swap a7 a8
./push_swap 7 "" 7
./push_swap 7 "" 8
./push_swap 8 "" 7
./push_swap 8-297489922
./push_swap ""
./push_swap "      "
./push_swap "1 -----"
./checker "9 2 1"
```
## Tips 
Je vous recommande de suivre le Wiki de Vbrazhnik pour un algo optimisé :
https://github.com/VBrazhnik/Push_swap/wiki/Algorithm

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

This is my get_next_line project from the 42 cursus,
need help: malatini@student.42.fr
