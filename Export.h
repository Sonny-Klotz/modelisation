#ifndef EXPORT_H
#define EXPORT_H
#include "Graphe.h"
#include <stdio.h>

/* Distribution des degrés */
void gnu(int tab_degres[],int degre_graph,char *nom_fichier);

/* Affichage du graphe */
void dessine_graph(Graphe *g,char *nom_fichier);
#endif
