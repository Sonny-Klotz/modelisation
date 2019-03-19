#include "Export.h"

/* Sort un fichier .txt contennant la distribution des degrés d'un graphe
 */
void gnu(int tab_degres[],int degre_graph,char *nom_fichier) {
	
	int i = 0;
	int distribution_degres[degre_graph + 1];

	for( i = 0 ; i <= degre_graph ; i++ ) {
		distribution_degres[i]=0;
	}
	
	for( i = 0 ; i < N ; i++ ) {
		distribution_degres[tab_degres[i]] += 1;
	}
	
	FILE *f = NULL;
	f = fopen(nom_fichier, "w");
	
	for( i = 0 ; i <= degre_graph ; i++ ) {
		fprintf ( f , "%d %d \n" , i , distribution_degres[i] );
	}
	
	fclose(f);
}

/* Cette fonction permet, à partir d'un graphe g, de creer un fichier 
 * nom_fichier.dot comprenant la liste des arcs de g.
 * Les doublons ne sont pas pris en compte.
 * Si un sommet n'a pas de voisin alors ceci est notifié dans le fichier.
 */
void dessine_graph(Graphe *g,char *nom_fichier){
	
	FILE *f = NULL;
	f = fopen(nom_fichier, "w");
	
	fprintf ( f , "graph G1 {\n");
	
	Element *actuel = NULL;
	
	int i=0;
	int id_actuel=0;
	
	for(i=0;i<N;i++){
		actuel = &g->listeAdj[i];
		id_actuel = actuel->id;
		
		//Si le sommet n'a pas de voisin
		if(actuel->suivant==NULL){
			fprintf(f,"%d\n",id_actuel);
		}
		//Si le sommet à au moins 1 voisin
		while(actuel->suivant!=NULL){
			if(id_actuel<actuel->suivant->id){
				fprintf(f,"%d -- %d\n",id_actuel,actuel->suivant->id);
			}
			actuel=actuel->suivant;
		}
	}
	fprintf ( f , "}\n");
	
	fclose(f);
}

