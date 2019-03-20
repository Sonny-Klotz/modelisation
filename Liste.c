#include "Liste.h"


Element* init_element(int id) {
	
	Element *e = NULL;
	e =  calloc(1, sizeof(*e));
	
	if (e == NULL)
    {
        exit(EXIT_FAILURE);
    }
	
	e->id = id;
	
	return e;
}

void suppression_voisins(Element* actuel) {
	
	//printf("        Element qui va être supprimé : %d\n", actuel->id);
	if(actuel->suivant != NULL)
		suppression_voisins(actuel->suivant);
		
	free(actuel);
}
