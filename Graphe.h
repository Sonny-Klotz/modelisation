#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>

#include "Liste.h"

#define N 10

typedef struct Graphe Graphe;
struct Graphe
{
	int nbSommets;
    Element *listeAdj;
};

/* Allocation mémoire */
Graphe* init_Graphe();

/* Affichage */
void afficher_liste_sommets(Graphe *graphe);
void afficher_graphe(Graphe *graphe);

/* Ajout arete */
void ajout_sommet(Graphe *graphe, int id_Sommet_A, int id_Sommet_B);
void ajout_arc(Graphe *graphe, int id_Sommet_A, int id_Sommet_B);

/* Libération mémoire */
void suppression_noeud(Element * noeuds);
void suppression_graphe(Graphe *graphe);

#endif
