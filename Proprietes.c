#include "Proprietes.h"

void aretes_degreMax_degreMoy_densite (Graphe *g) {
	
	int i, somme;
	
	somme = 0;
	for (i = 0; i < g->nbSommets; i++)
	{
		somme += g->degres[i];
		if( g->degres[i] > max )
			max = g->degres[i];
	}
	g->nbAretes = somme / 2;
	g->degreMax = max;
	g->degreMoy = somme / g->nbSommets;
	g->densite = (2 * g->nbAretes) / (g->nbSommets * (g->nbSommets - 1));
}

void densite_moyenne(Graphe *g) {
	
	int i;
	for (i = 0; i < g->nbSommets; i++)
	{
		g->listeAdj[i]
	}
}