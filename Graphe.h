#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>

#include "Liste.h"
#include "Random.h"

#define N 10
#define p 0.2
// Attention m0 << N
#define M0 2
#define M 2

typedef struct Graphe Graphe;
struct Graphe
{
	int nbSommets;
	int *degres;
    Element *listeAdj;
    
    int degreMax;
    int nbAretes;
    double degreMoy;
    double densiteG;
    double densiteMoy;
    int diametre;
    double distanceMoy;
};

/* Allocation mémoire */
Graphe* init_Graphe();

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
void init_degre(int *tab);
int min(int a, int b);
int condition_modele_deux(int* degre);
void init_modele_deux(int* degre);
int arete_distribuable(int *degre);
void gen_modele_deux(Graphe *g, int *degre);

/* Modele 3 */
void maj_degre_cumule(Graphe *g, double *cumul, int k);
void gen_modele_trois(Graphe *g);


#endif
