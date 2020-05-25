#include "univers.h"

univers::univers() {
	this->view = 1;

	int nbGalaxiesQ1 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ1; i++) {
		int leRandQ1 = rand() % 3;
		if (leRandQ1 == 0) { this->Q1galaxies.push_back(new galaxieSpirale(rand()% (1500 - 200) + 200, rand() % (700 - 250) + 200)); }
		else if (leRandQ1 == 1) { this->Q1galaxies.push_back(new galaxieEliptique(rand() % (1500 - 200) + 200, rand() % (700 - 200) + 200)); }
		else if (leRandQ1 == 2) { this->Q1galaxies.push_back(new galaxieSpiraleBarree(rand() % (1500 - 200) + 250, rand() % (700 - 200) + 200)); }
	}
	int nbGalaxiesQ2 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ2; i++) {
		int leRandQ2 = rand() % 3;
		if (leRandQ2 == 0) { this->Q2galaxies.push_back(new galaxieSpirale(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ2 == 1) { this->Q2galaxies.push_back(new galaxieEliptique(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ2 == 2) { this->Q2galaxies.push_back(new galaxieSpiraleBarree(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
	}
	int nbGalaxiesQ3 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ3; i++) {
		int leRandQ3 = rand() % 3;
		if (leRandQ3 == 0) { this->Q3galaxies.push_back(new galaxieSpirale(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ3 == 1) { this->Q3galaxies.push_back(new galaxieEliptique(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ3 == 2) { this->Q3galaxies.push_back(new galaxieSpiraleBarree(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
	}
	int nbGalaxiesQ4 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ4; i++) {
		int leRandQ4 = rand() % 3;
		if (leRandQ4 == 0) { this->Q4galaxies.push_back(new galaxieSpirale(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ4 == 1) { this->Q4galaxies.push_back(new galaxieEliptique(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
		else if (leRandQ4 == 2) { this->Q4galaxies.push_back(new galaxieSpiraleBarree(rand() % (1400 - 100) + 100, rand() % (700 - 100) + 100)); }
	}
}

void univers::afficher(sf::RenderWindow* window) {

	if (this->view == 1) {
		for (int i = 0; i < this->Q1galaxies.size(); i++) {
			this->getGalaxies()[i]->afficher(window);
		}
	}
	else if (this->view == 2) {
		for (int i = 0; i < this->Q2galaxies.size(); i++) {
			this->getGalaxies()[i]->afficher(window);
		}
	}
	else if (this->view == 3) {
		for (int i = 0; i < this->Q3galaxies.size(); i++) {
			this->getGalaxies()[i]->afficher(window);
		}
	}
	else {
		for (int i = 0; i < this->Q4galaxies.size(); i++) {
			this->getGalaxies()[i]->afficher(window);
		}
	}

}