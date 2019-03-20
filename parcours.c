/*#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 50
#define p 0.3

// Renvoie un nombre aléatoire entre 0 et 1
double rand01()
{
	return random()/(double) RAND_MAX;
}

long int rand_entier(int n)
{
	return random()/(double) RAND_MAX*(n+1);
}


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
	int diametre;
    Element *listeAdj;
};

typedef struct Objet Objet;
struct Objet
{
    Element *sommet;
    Objet *suivant;
};

typedef struct File File;
struct File
{
    Objet *premier;
};

void enfiler(File *file, Element *nvSommet)
{
    Objet *nouveau = calloc(1,sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->sommet = nvSommet ;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide *
    {
        /* On se positionne à la fin de la file *
        Objet *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier *
    {
        file->premier = nouveau;
    }
}

Element* defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *sommetDefile = NULL;

    /* On vérifie s'il y a quelque chose à défiler *
    if (file->premier != NULL)
    {
        Objet *objetDefile = file->premier;

        sommetDefile = objetDefile->sommet;
        file->premier = objetDefile->suivant;
        free(objetDefile);
    }

    return sommetDefile;
}

File *init_file()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}



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
	
	graphe->diametre = 0;
	
    return graphe;
}

void init_degre(int *tab)
{
	for (int i = 0; i < N; i++)
	{
		tab[i] = rand_entier(N-1);
	}
	
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
*

void affiche_degre(int *tab)
{
	printf("\n*************** Affichage des degres ***************\n\n");
	for (int i = 0; i < N; i++)
	{
		printf(" le sommet *%d* est de degré : %d \n", i, tab[i]);
	}
	printf("\n****************************************************\n\n");
	
}

void affiche_distance(int *tab, int sommet)
{
	printf("\n*************** Affichage des distances depuis le sommet %d ***************\n\n", sommet);
	for (int i = 0; i < N; i++)
	{
		printf(" le sommet *%d* est à distance : %d \n", i, tab[i]);
	}
	printf("\n****************************************************\n\n");
	
}

void afficher_graphe(Graphe *graphe)
{
	if (graphe == NULL)
    {
		printf("Il n'y a pas de graphe à afficher.\n");
        exit(EXIT_FAILURE);
    }
    
    Element *actuel = NULL;
    
    printf("\n################### Affichage du graphe ###################\n\n");
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
	
	printf("\n###########################################################\n");
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
	//printf("        Element qui va être supprimé : %d\n", actuel->id);
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
			//printf("***Début de la suppression des voisins de %d***\n", graphe->listeAdj[i].id);
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

int file_vide(File *f){
	
	if(f->premier == NULL)
		return 1;
	else
		return 0;
}
void parcours_largeur(Graphe *g, File *f,Element *e, int* distance, int sommet_courant)
{
	
	Element *voisin = NULL;
	Element *sommet = NULL;
	voisin = e;
	int tab[N];
	
	
	for (int i = 0; i < N; i++)
	{
		tab[i] = 0;
	}
	
	enfiler(f,voisin);
	distance[voisin->id]++;
	tab[voisin->id] = 1;
	//printf("Je viens d'enfiler : %d\n\n", voisin->id);
	while(voisin->suivant != NULL)
	{
		enfiler(f, voisin->suivant);
		tab[voisin->suivant->id] = 1;
		distance[voisin->suivant->id]++;
		//printf("Je viens d'enfiler l'un des premier voisin qui est  : %d\n\n", voisin->suivant->id);
		voisin = voisin->suivant;
	}
	
	do
	{
		if(!file_vide(f)){
			sommet = defiler(f);
			//printf("Je vient de defiler : %d\n\n", sommet->id);
		}
		
		
		if(sommet != NULL){
			tab[sommet->id] = 1;
			voisin = g->listeAdj[sommet->id].suivant;
			while(voisin != NULL)
			{
				if (voisin->id != sommet_courant)
				{	
					if(tab[voisin->id] == 0)
					{
						enfiler(f, voisin);
						tab[voisin->id] = 1;
						distance[voisin->id] = distance[sommet->id]+1;
						//printf("Je viens d'enfiler : %d qui est un voisin de %d \n\n",voisin->id, sommet->id);
					}
				}
				
				voisin = voisin->suivant;
				//printf("Je continue de parcourir le graphe\n\n");
			}
		}
	} while (!file_vide(f));
	
	
}

int somme_distance(int* distance){
	
	int somme = 0;
	
	for (int i = 0; i < N; i++)
	{
		somme += distance[i];
	}
	
	
	return somme;
}

int max_distance(int* distance){

	int max;
	
	max = distance[0];
	
	for (int i = 0; i < N; i++)
	{
		if(max<distance[i])
			max = distance[i];
	}
	
		
	return max;
}

int min_max(int* distance){

	int min;
	
	min = distance[0];
	
	for (int i = 0; i < N; i++)
	{
		if(min>distance[i])
			min = distance[i];
	}
	
		
	return min;
}

int calcul_nb_chemin(int* distance)
{
	int nb_chemin = 0;
	
	for (int i = 0; i < N; i++)
	{
		if(distance[i] > 0){
			nb_chemin++;
			//printf("Nb chemin : %d\n", nb_chemin);
		}
	}
	
	return nb_chemin;
}

int main()
{
	struct timeval trecv;
	
	gettimeofday(&trecv, NULL);
	srandom(trecv.tv_usec);
	
	int degre[N];
	int nb_chemin_total = 0;
	int nb_chemin = 0;
	int nb_distance[N];
	int s_d = 0;
	Graphe *g = NULL;
	g = init_Graphe();
	 
	gen_modele_un(g);
	
	afficher_graphe(g);
	
	File *f = init_file();
	
	int distance[N];
	
	int distance_max[N];
	
	for (int l = 0; l < N; l++)
	{
		distance_max[l] = 0;
		nb_distance[l] = 0;
	}
	
	
	for (int i = 0; i < N; i++)
	{
		if(g->listeAdj[i].suivant != NULL)
		{
			for (int j = 0; j < N; j++)
			{
				distance[j] = 0;
			}
			//printf("******Je fais le parcours depuis %d\n",i);
			parcours_largeur(g, f, g->listeAdj[i].suivant, distance, i);
			nb_chemin = calcul_nb_chemin(distance);
			printf("Le nombre de chemin depuis %d est : %d\n", i, nb_chemin);
			nb_chemin_total += nb_chemin;
			nb_distance[i] = somme_distance(distance);
			printf("La distance max depuis %d est : %d || La somme des distance depuis %d est %d\n\n", i , distance_max[i] = max_distance(distance), i , nb_distance[i]);
		}
	}
	
	g->diametre = min_max(distance_max);
	
	s_d = somme_distance(nb_distance);
	
	printf("\n\n\n                %d                  \n\n\n",s_d);
	printf("\n\n\n                %d                  \n\n\n",nb_chemin_total);
	
	printf("\n\nLe diamêtre de G est : %d\n",g->diametre);
	printf("\n\nLe nombre total de chemin de G est : %d\n",nb_chemin_total);
	printf("\nSomme totale des distances du graphe G : %d\n", s_d);
	printf("\nLa longueure moyenne du graphe G est : %f\n", s_d/((nb_chemin_total)*1.0));
	suppression_graphe(g);
	
    return 0;
}*/
