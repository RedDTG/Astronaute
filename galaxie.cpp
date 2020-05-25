#include "galaxie.h"
galaxie::galaxie() { 
	int nbSystemes = rand() % (10 - 4) + 4;

	for (int i = 0; i < nbSystemes; i++) {
		int leRand = rand() % 2;
		if (leRand == 0) { this->addSysteme(new systemePlanetaire()); }
		else if (leRand == 1) { this->addSysteme(new systemePlanetaire()); }
	}
}

