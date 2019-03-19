#ifndef PROPRIETES_H
#define PROPRIETES_H

#include "Graphe.h"

/* Nombre d'aretes : somme des degrés / 2 */
/* Degré du graphe */
/* Moyenne des degrés des sommets du graphe */
/* Densité du graphe */
void aretes_degreMax_degreMoy_densite(Graphe *g);

/* Diamètre du graphe */
/* Moyenne des longueurs des chemins du graphe */
void parcours_largeur(Graphe *g, int racine);
void diametre_distanceMoy(Graphe *g);

/* Moyenne des densités des sommets du graphe */
double densite_sommet(Graphe *g, int sommet);
double densite_moyenne(Graphe *g);

#endif
