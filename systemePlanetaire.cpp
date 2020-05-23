#include "systemePlanetaire.h"

systemePlanetaire::systemePlanetaire() {
	int nbPlanetes = rand() % (10 - 4) + 4;
	
	for (int i = 0; i < nbPlanetes; i++) {
		int leRand = rand() % 2;
		if (leRand == 0) { this->planetes.push_back(new planeteTellurique()); }
		else if (leRand == 1) { this->planetes.push_back(new planeteGazeuse()); }
	}
}
