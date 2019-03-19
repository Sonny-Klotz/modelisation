#include "Graphe.h"
#include "Proprietes.h"

int main ( int argc , char *argv[] )
{
	struct timeval trecv;
	
	gettimeofday(&trecv, NULL);
	srandom(trecv.tv_usec);
	
	int degre[N];
	
	
	Graphe *g = NULL;
	g = init_Graphe();
	//init_degre(degre);
	gen_modele_un(g);
	//affiche_degre(degre);
	printf("\n Densite : %f \n",densite_moyenne(g));
	//test_modele_deux(g, degre);
	
	
	
	/*	On admet que le sommet 1 à pour voisin les sommets 3, 6 et 9
	 * 	Que le sommet 2 à pour voisin le sommet 4
	 *  Et que le sommet 6 à pour voisin le sommet 3 */
	
	afficher_graphe(g);
	
	/* test de l'ajout des arcs
	ajout_arc(g,1,3);
	ajout_arc(g,1,6);
	ajout_arc(g,1,9);
	ajout_arc(g,2,4);
	ajout_arc(g,6,3);
	*/
	
	//gen_modele_un(g);
	
	//afficher_graphe(g);
	
	
	suppression_graphe(g);
	
    return 0;
} 
