#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//tab des degres des sommet du graphe
	int nb_sommets = 100;
	int tab[nb_sommets];
	int degre_graph = 6;
	int tab2[degre_graph+1];
	
	int i=0;
	int j=0;
	
	for(i=0;i<nb_sommets;i++){
		tab[i]=j%(degre_graph+1);
		j++;
	}
	
	gnu(tab,degre_graph,nb_sommets,argv[1]);
		
    return 0;
}

void gnu(int tab_degres[],int degre_graph,int nombre_sommets,char *nom_fichier[]){
	
	int i=0;
	int tab2[degre_graph+1];

	for(i=0;i<=degre_graph;i++)
	{
		tab2[i]=0;
	}
	
	for(i=0;i<nombre_sommets;i++){
		tab2[tab_degres[i]]+=1;
	}
	
	FILE *f = NULL;
	f = fopen(nom_fichier, "w");
	
	for(i=0;i<=degre_graph;i++){
		fprintf(f,"%d %d \n",i,tab2[i]);
	}
	
	fclose(f);
}
