#include "univers.h"

univers::univers() {
	this->view = 1;
	int CoX = rand() % (1500 - 200) + 200;
	int CoY = rand() % (700 - 250) + 200;
	vector<int> lesCoX;
	vector<int> lesCoY;

	int nbGalaxiesQ1 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ1; i++) {
		int leRandQ1 = rand() % 3;
		lesCoX.push_back(CoX);
		lesCoY.push_back(CoY);
		if (leRandQ1 == 0) { this->Q1galaxies.push_back(new galaxieSpirale(CoX, CoY)); }
		else if (leRandQ1 == 1) { this->Q1galaxies.push_back(new galaxieEliptique(CoX, CoY)); }
		else if (leRandQ1 == 2) { this->Q1galaxies.push_back(new galaxieSpiraleBarree(CoX, CoY)); }
		
		CoX = rand() % (1500 - 200) + 200;
		CoY = rand() % (700 - 250) + 200;
		while (this->testCoordonnees(CoX, CoY, lesCoX, lesCoY)) {
			CoX = rand() % (1500 - 200) + 200;
			CoY = rand() % (700 - 250) + 200;
		}
	
	}

	CoX = rand() % (1500 - 200) + 200;
	CoY = rand() % (700 - 250) + 200;
	lesCoX.clear();
	lesCoY.clear();

	int nbGalaxiesQ2 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ2; i++) {
		int leRandQ2 = rand() % 3;
		lesCoX.push_back(CoX);
		lesCoY.push_back(CoY);
		if (leRandQ2 == 0) { this->Q2galaxies.push_back(new galaxieSpirale(CoX, CoY)); }
		else if (leRandQ2 == 1) { this->Q2galaxies.push_back(new galaxieEliptique(CoX, CoY)); }
		else if (leRandQ2 == 2) { this->Q2galaxies.push_back(new galaxieSpiraleBarree(CoX, CoY)); }
	
		CoX = rand() % (1500 - 200) + 200;
		CoY = rand() % (700 - 250) + 200;
		while (this->testCoordonnees(CoX, CoY, lesCoX, lesCoY)) {
			CoX = rand() % (1500 - 200) + 200;
			CoY = rand() % (700 - 250) + 200;
		}
	}

	CoX = rand() % (1500 - 200) + 200;
	CoY = rand() % (700 - 250) + 200;
	lesCoX.clear();
	lesCoY.clear();

	int nbGalaxiesQ3 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ3; i++) {
		int leRandQ3 = rand() % 3;
		lesCoX.push_back(CoX);
		lesCoY.push_back(CoY);
		if (leRandQ3 == 0) { this->Q3galaxies.push_back(new galaxieSpirale(CoX, CoY)); }
		else if (leRandQ3 == 1) { this->Q3galaxies.push_back(new galaxieEliptique(CoX, CoY)); }
		else if (leRandQ3 == 2) { this->Q3galaxies.push_back(new galaxieSpiraleBarree(CoX, CoY)); }
		
		CoX = rand() % (1500 - 200) + 200;
		CoY = rand() % (700 - 250) + 200;
		while (this->testCoordonnees(CoX, CoY, lesCoX, lesCoY)) {
			CoX = rand() % (1500 - 200) + 200;
			CoY = rand() % (700 - 250) + 200;
		}
	}

	CoX = rand() % (1500 - 200) + 200;
	CoY = rand() % (700 - 250) + 200;
	lesCoX.clear();
	lesCoY.clear();

	int nbGalaxiesQ4 = rand() % (5 - 1) + 1;
	for (int i = 0; i < nbGalaxiesQ4; i++) {
		lesCoX.push_back(CoX);
		lesCoY.push_back(CoY);
		int leRandQ4 = rand() % 3;
		if (leRandQ4 == 0) { this->Q4galaxies.push_back(new galaxieSpirale(CoX, CoY)); }
		else if (leRandQ4 == 1) { this->Q4galaxies.push_back(new galaxieEliptique(CoX, CoY)); }
		else if (leRandQ4 == 2) { this->Q4galaxies.push_back(new galaxieSpiraleBarree(CoX, CoY)); }
	
		CoX = rand() % (1500 - 200) + 200;
		CoY = rand() % (700 - 250) + 200;
		while (this->testCoordonnees(CoX, CoY, lesCoX, lesCoY)) {
			CoX = rand() % (1500 - 200) + 200;
			CoY = rand() % (700 - 250) + 200;
		}
	}
}

void univers::afficher(sf::RenderWindow* window, sf::Vector2i mousePos, int view) {
	int size = 0;

	if (view == 1) {
		size = this->Q1galaxies.size();
	}
	else if (view == 2) {
		size = this->Q2galaxies.size();
	}
	else if (view == 3) {
		size = this->Q3galaxies.size();

	}
	else if (view == 4) {
		size = this->Q4galaxies.size();
	}

	for (int i = 0; i < size ; i++) {
		this->getGalaxies(view)[i]->afficher(window);
	}

}


bool univers::testCoordonnees(int X, int Y, vector<int> lesX, vector<int> lesY) {
	for (int i = 0; i < lesX.size(); i++) {
		if ((X < lesX[i] + 300) && (X > lesX[i] - 300) && ((Y < lesY[i] + 300) && (Y > lesY[i] - 300))) {
			return true;
		}
	}

	return false;
}