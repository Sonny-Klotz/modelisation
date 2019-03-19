#include "Graphe.h"

Graphe* init_Graphe() {
	
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


void init_degre(int *tab)
{
	for (int i = 0; i < N; i++)
	{
		tab[i] = rand_entier(N-1);
	}
	
}

void afficher_liste_sommets(Graphe *graphe) {
	
    if (graphe == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++)
	{
		printf("%d\n", graphe->listeAdj[i].id);
	}
}

void afficher_graphe(Graphe *graphe) {
	
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

void affiche_degre(int *tab)
{
	for (int i = 0; i < N; i++)
	{
		printf(" le sommet *%d* est de degré : %d \n", i, tab[i]);
	}
	
}

void ajout_sommet(Graphe *graphe, int id_Sommet_A, int id_Sommet_B) {
		
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

void ajout_arc(Graphe *graphe, int id_Sommet_A, int id_Sommet_B) {
	
	//On met ici la liste des voisins à jours pour les deux sommets 
	
	ajout_sommet(graphe, id_Sommet_A, id_Sommet_B); 
	ajout_sommet(graphe, id_Sommet_B, id_Sommet_A);
}


void suppression_noeud(Element * noeuds) {
	
	for (int i = N-1; i > 0; i--)
	{
		free(&noeuds[i]);
	}
	
}

void suppression_graphe(Graphe *graphe) {
	
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

void gen_modele_un(Graphe *g)
{
	for (int i = 0; i < N; i++)
	{
		for ( int j = i+1; j < N ; j++)
		{
			//printf("%d - %d\n",i,j);
			if(rand01() < p)
			{
				ajout_arc(g,i,j);
			}
		}
		
	}
	
}

int min(int a, int b){
	
	if(a<b)
		return a;
	else
		return b;
}

int condition_modele_deux(int* degre)
{
	
	int somme_degre_courant = 0; 
	int somme_degre_restant = 0;
	int somme_degre = 0;
	int somme;
	int flag = 1;
	
	for (int k = 0; k < N && flag; k++)
	{
		somme_degre_courant += degre[k];
		//somme_degre_restant = somme_degre - somme_degre_courant;
		somme = 0;
		
		for (int j = k+1; j < N-1; j++)
		{
			somme += min(k,degre[j]);
		}
		printf(" somme courantes des degres : %d \n", somme_degre_courant);
		//printf("degre courant : %d > somme :  %d\n",somme_degre_courant, ((k * (k-1)) + somme));
		printf("test modele %d <= %d \n",  somme_degre_courant, ((k * (k-1)) + somme));
		if (somme_degre_courant > ((k * (k-1)) + somme)){
			flag = 0;
			printf("gnagnagna\n");
		}
	}
	
	return !flag;
}

void gen_modele_deux(Graphe *g, int* degre)
{
	do
	{
		printf("***Initialisation des degres***\n");
		init_degre(degre);
	} while (condition_modele_deux(degre));
	
	printf("\n\n\n**** Les degre respecte le modèle **** \n\n\n");
	
}

int arete_distribuable(int *degre){
	
	int somme = 0;
	
	for (int i = 0; i < N; i++)
	{
		somme += degre[i];
	}
	
	return somme;
}

int test_voisin(Graphe *graphe, int a, int b)
{
	int est_voisin = 0;
	
	
	Element *actuel = NULL;
	
	actuel = &graphe->listeAdj[a];
	
	if(actuel == NULL)
		exit(EXIT_FAILURE);
		
	
	
	while(actuel->suivant != NULL){
			if(actuel->suivant->id == b){
				printf("\nPROBLEME A ET B SONT VOISIN \n\n");
				return 1;
			}
			actuel = actuel->suivant;
		}
		
	
	return 0;
}

void test_modele_deux(Graphe *g, int *degre)
{
	int a = 0;
	int b = 0;
	do
	{
		a = rand_entier(N-1);
		b = rand_entier(N-1);
		
		printf("deg a = %d , deg b = %d , demi arete restante = %d \n ",degre[a], degre[b], arete_distribuable(degre));
		
		if(degre[a] > 0 && degre[b] > 0 && a != b && test_voisin(g,a,b))
		{
			degre[a]--;
			degre[b]--;
			ajout_arc(g, a, b);
			ajout_arc(g, b, a);
		}
		
		affiche_degre(degre);
		
	} while (arete_distribuable(degre) > 0);
	
	if(arete_distribuable(degre) == 0)
		exit(EXIT_SUCCESS);
}
