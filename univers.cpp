#include "univers.h"

univers::univers() {
	int nbGalaxies = rand() % (20 - 5) + 5;

	for (int i = 0; i < nbGalaxies; i++) {
		int leRand = rand() % 3;
		if (leRand == 0) { this->galaxies.push_back(new galaxieSpirale()); }
		else if (leRand == 1) { this->galaxies.push_back(new galaxieEliptique()); }
		else if (leRand == 2) { this->galaxies.push_back(new galaxieSpiraleBaree()); }
	}
}