#include <iostream>
#include <SFML/Graphics.hpp>
#include "planete.h"


int main()
{
	srand(time(NULL));
	vector<planete*> galaxie;

	for (int i = 0; i < 20; i++) {
		int leRand = rand() % 2 + 1;
		if (leRand == 1) { galaxie.push_back(new planeteTellurique()); }
		else if (leRand == 2) { galaxie.push_back(new planeteGazeuse()); }
	}

	for (int i = 0; i < galaxie.size() - 1; i++) {
		galaxie[i]->afficherPlanete();
	}

}

