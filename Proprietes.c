#include "Proprietes.h"

void aretes_degreMax_degreMoy_densite (Graphe *g) {
	
	int i, max;
	
	double somme = 0;
	max = g->degres[0];
	for (i = 0; i < g->nbSommets; i++)
	{
		somme += g->degres[i];
		if( g->degres[i] > max )
			max = g->degres[i];
	}
	g->nbAretes = somme / 2;
	g->degreMax = max;
	g->degreMoy = somme / (double) g->nbSommets;
	g->densiteG = ((double) (2 * g->nbAretes)) / ((double) (g->nbSommets * (g->nbSommets - 1)));
}


double densite_sommet(Graphe *g, int sommet){
	int res = 0;
	double nb_voisin = 0.0;
	double nb_arete_ss_ens = 0.0;
	
	Element *actuel = NULL;
	actuel = &g->listeAdj[sommet];
	
	//Si pas de voisin alors densite = 0
	if(actuel->suivant==NULL){
		return 0.0;
	}
	if(actuel->suivant->suivant==NULL){
		return 0.0;
	}
	
	//Calcul du nombre de voisin
	while(actuel->suivant!=NULL ){
		nb_voisin+=1.0;
		actuel=actuel->suivant;
	}
	
	int vois[(int)nb_voisin];
	actuel = &g->listeAdj[sommet];
	
	int i=0;
	int j=0;
	
	//Tableau contennant la liste des voisins
	while(actuel->suivant!=NULL){
		vois[i]=actuel->suivant->id;
		actuel=actuel->suivant;
		i++;
	}
	
	//Pour chaque element du tableau s'il existe un arc entre deux voisins alors on ajout +1 au nombre d'arrets du sous ensemble
	//On fait ceci pour chaque paires de voisins possible parmis les voisins du noeud "sommet"
	for(i=0;i<(int)nb_voisin-1;i++){
		actuel = &g->listeAdj[vois[i]];
		for(j=i+1;j<(int)nb_voisin;j++)
		{
			if(test_voisin(g,vois[i],vois[j])){
				nb_arete_ss_ens += 1.0;
			}
		}
	}
	return (2.0*nb_arete_ss_ens)/(nb_voisin*(nb_voisin-1.0));
}

void densite_moyenne(Graphe *g){
	int i = 0;
	double somme_densite = 0;
	for(i = 0; i < g->nbSommets; i++){
			somme_densite += densite_sommet(g, i);
	}
	
	g->densiteMoy = somme_densite/g->nbSommets;
}
