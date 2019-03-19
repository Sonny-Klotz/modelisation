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


double densite_sommet(Graphe *g, int sommet){
	int res = 0;
	double nb_voisin = 0.0;
	double nb_arete_ss_ens = 0.0;
	
	Element *actuel = NULL;
	actuel = &g->listeAdj[sommet];
	
	while(actuel->suivant!=NULL){
		nb_voisin+=1.0;
		actuel=actuel->suivant;
	}
	
	int vois[nb_voisin];
	actuel = &g->listeAdj[sommet];
	
	int i=0;
	int j=0;
	
	while(actuel->suivant!=NULL){
		vois[i]=actuel->suivant->id;
		actuel=actuel->suivant;
		i++;
	}
	
	for(i=0;i<nb_voisin-1;i++){
		actuel = &g->listeAdj[i];
		for(j=i+1;j<nb_voisin;j++)
		{
			if(test_voisin(g, i, j){
				nb_arete_ss_ens += 1.0;
			}
		}
	}
	
	return (2.0*nb_arete_ss_ens)/(nb_voisin*(nb_voisin*1.0));
}

double densite_moyenne(Graphe *g){
	int i = 0;
	double somme_densite = 0;
	for(i=0;i<g->nbSommets;i++){
			somme_densite += densite_sommet(g,i);
	}
	
	return somme_densite/g->nbSommets;
}
