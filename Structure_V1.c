#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Element Element;
struct Element
{
    int id;
    Element *suivant;
};

typedef struct Graphe Graphe;
struct Graphe
{
	int nbSommets;
    Element *listeAdj;
};

Element* init_element(int id){
	
	Element *e = NULL;
	e =  calloc(1, sizeof(*e));
	
	if (e == NULL)
    {
        exit(EXIT_FAILURE);
    }
	
	e->id = id;
	
	return e;
}

Graphe *init_Graphe(){
    Graphe *graphe = NULL;
    graphe = malloc(sizeof(*graphe));
    graphe->listeAdj = NULL;
    graphe->listeAdj = malloc(N*sizeof(*graphe->listeAdj));

    if (graphe == NULL || graphe->listeAdj == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < N; i++)
	{
		graphe->listeAdj[i].id = i;
		graphe->listeAdj[i].suivant = NULL;
		graphe->nbSommets++;
	}
	

    return graphe;
}

/*
void afficher_liste_sommets(Graphe *graphe)
{
    if (graphe == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++)
	{
		printf("%d\n", graphe->listeAdj[i].id);
	}
}
*/
void afficher_graphe(Graphe *graphe)
{
	if (graphe == NULL)
    {
		printf("Il n'y a pas de graphe à afficher.\n");
        exit(EXIT_FAILURE);
    }
    
    Element *actuel = NULL;
    
    for (int i = 0; i < N; i++)
	{	
		actuel = &graphe->listeAdj[i];
		printf("%d -> ", actuel->id);
		
		while(actuel->suivant != NULL){
			actuel = actuel->suivant;
			printf("%d, ", actuel->id);
		}
		printf("\n");
	}
	
	printf("####################################\n");
}


void ajout_sommet(Graphe *graphe, int id_Sommet_A, int id_Sommet_B)
{	
	Element *nouveau = NULL;
	 nouveau = init_element(id_Sommet_B);
	
	if(nouveau == NULL)
		exit(EXIT_FAILURE);
	
	Element *actuel = NULL;
	
	actuel = &graphe->listeAdj[id_Sommet_A];
	
	if(actuel == NULL)
		exit(EXIT_FAILURE);
	
	while(actuel->suivant != NULL){
			actuel = actuel->suivant;
		}
	
	actuel->suivant = nouveau;
	
	return;
		
}



void ajout_arc(Graphe *graphe, int id_Sommet_A, int id_Sommet_B)
{
	//On met ici la liste des voisins à jours pour les deux sommets 
	
	ajout_sommet(graphe, id_Sommet_A, id_Sommet_B); 
	ajout_sommet(graphe, id_Sommet_B, id_Sommet_A);
}

void suppression_voisins(Element* actuel)
{
	printf("        Element qui va être supprimé : %d\n", actuel->id);
	if(actuel->suivant != NULL)
		suppression_voisins(actuel->suivant);
		
	free(actuel);
}

void suppression_noeud(Element * noeuds)
{
	for (int i = N-1; i > 0; i--)
	{
		free(&noeuds[i]);
	}
	
}

void suppression_graphe(Graphe *graphe){
	
	if (graphe == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < N; i++)
	{
		
		if(graphe->listeAdj[i].suivant != NULL)
		{
			printf("***Début de la suppression des voisins de %d***\n", graphe->listeAdj[i].id);
			suppression_voisins(graphe->listeAdj[i].suivant);
		}
	}

	free(graphe->listeAdj);
	printf("+*+*+*Suppression du graphe*+*+*+\n\n");
    free(graphe);
    
}

int main()
{
	Graphe *g = NULL;
	
	g = init_Graphe();
	
	/*	On admet que le sommet 1 à pour voisin les sommets 3, 6 et 9
	 * 	Que le sommet 2 à pour voisin le sommet 4
	 *  Et que le sommet 6 à pour voisin le sommet 3 */
	
	afficher_graphe(g);
	
	ajout_arc(g,1,3);
	ajout_arc(g,1,6);
	ajout_arc(g,1,9);
	ajout_arc(g,2,4);
	ajout_arc(g,6,3);
	
	
	afficher_graphe(g);
	
	
	suppression_graphe(g);
	
	
	
    return 0;
}
