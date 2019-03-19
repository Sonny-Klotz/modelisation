#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int id;
    Element *suivant;
};

Element* init_element(int id);

void suppression_voisins(Element* actuel);

#endif
