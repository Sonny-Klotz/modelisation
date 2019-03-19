#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>

#include "Liste.h"
#include "Random.h"

#define N 10
#define p 0.01

typedef struct Graphe Graphe;
struct Graphe
{
	int nbSommets;
    Element *listeAdj;
};

/* Allocation mémoire */
Graphe* init_Graphe();
void init_degre(int *tab);

/* Affichage */
void afficher_liste_sommets(Graphe *graphe);
void afficher_graphe(Graphe *graphe);
void affiche_degre(int *tab);

/* Ajout arete */
void ajout_sommet(Graphe *graphe, int id_Sommet_A, int id_Sommet_B);
void ajout_arc(Graphe *graphe, int id_Sommet_A, int id_Sommet_B);

/* Voisinage : est-ce que a et b sont voisins */
int test_voisin(Graphe *graphe, int a, int b);

/* Libération mémoire */
void suppression_noeud(Element * noeuds);
void suppression_graphe(Graphe *graphe);

/* Modele 1 */
void gen_modele_un(Graphe *g);

/* Modele 2 */
int min(int a, int b);
int condition_modele_deux(int* degre);
void gen_modele_deux(Graphe *g, int* degre);
int arete_distribuable(int *degre);
void test_modele_deux(Graphe *g, int *degre);

/* Modele 3 */



#endif
