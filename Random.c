#include "Random.h"

// Renvoie un nombre aléatoire entre 0 et 1
double rand01()
{
	return random()/(double) RAND_MAX;
}

long int rand_entier(int n)
{
	return random()/(double) RAND_MAX*(n+1);
}
