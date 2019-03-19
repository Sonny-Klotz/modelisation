#include "Export.h"

void gnu(int tab_degres[],int degre_graph,int nombre_sommets,char *nom_fichier) {
	
	int i = 0;
	int tab2[degre_graph + 1];

	for( i = 0 ; i <= degre_graph ; i++ ) {
		tab2[i]=0;
	}
	
	for( i = 0 ; i < nombre_sommets ; i++ ) {
		tab2[tab_degres[i]] += 1;
	}
	
	FILE *f = NULL;
	f = fopen(nom_fichier, "w");
	
	for( i = 0 ; i <= degre_graph ; i++ ) {
		fprintf ( f , "%d %d \n" , i , tab2[i] );
	}
	
	fclose(f);
}
