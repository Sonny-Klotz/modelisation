#include "Graphe.h"

Graphe* init_Graphe() {
	
    Graphe *graphe = NULL;
    graphe = malloc(sizeof(*graphe));
    
    graphe->nbSommets = 0;
    
    graphe->listeAdj = NULL;
    graphe->listeAdj = malloc(N*sizeof(*graphe->listeAdj));
    
    graphe->degres = NULL;
    graphe->degres = malloc(N*sizeof(int));

    if (graphe == NULL || graphe->listeAdj == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < N; i++)
	{
		graphe->listeAdj[i].id = i;
		graphe->listeAdj[i].suivant = NULL;
		graphe->nbSommets++;
		graphe->degres[i] = 0;
	}
	

    return graphe;
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
	
	graphe->degres[id_Sommet_A]++;
	graphe->degres[id_Sommet_B]++;
	
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
	free(graphe->degres);
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


void init_degre(int *tab)
{
	for (int i = 0; i < N; i++)
	{
		tab[i] = rand_entier(N-1);
	}
	
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
		somme = 0;
		
		for (int j = k+1; j < N-1; j++)
		{
			somme += min(k,degre[j]);
		}
		if (somme_degre_courant > ((k * (k-1)) + somme)){
			flag = 0;
		}
	}
	
	return !flag;
}


void init_modele_deux(Graphe g, int *degre)
{
	do
	{
		init_degre(degre);
	} while (condition_modele_deux(degre));
	
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
			return 1;
		}
		actuel = actuel->suivant;
	}
		
	return 0;
}

void gen_modele_deux(Graphe *g, int *degre)
{
	int a = 0;
	int b = 0;
	
	init_modele_deux(g, degre);
	do
	{
		a = rand_entier(N-1);
		b = rand_entier(N-1);
		if(degre[a] > 0 && degre[b] > 0 && a != b && !test_voisin(g,a,b))
		{
			degre[a]--;
			degre[b]--;
			ajout_arc(g, a, b);
		}
	} while (arete_distribuable(degre) > 0);
}

void gen_modele_trois(Graphe *g) {
	
	// M0 noeuds de départs connectés
	int i,j;
	for (i = 0; i < M0; i++)
	{
		for (j = i + 1; j < M0; j++)
		{
			ajout_arc(g, i, j);
		}
	}
	
	int somme_degre = M0 * (M0 - 1);
	int nouvelle_arete;
	// Ajout des sommets restants connectés à M autres
	for (i = M0; i < g->nbSommets; i++)
	{
		j = 0;
		while ( j < M )
		{
			nouvelle_arete = rand01();
		}
	}
}
