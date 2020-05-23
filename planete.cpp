#include "planete.h"

planete::planete() { }

planeteTellurique::planeteTellurique() : planete() {
	this->setType("Tellurique");
	this->setRessources(rand() % 101, rand() % 101, rand() % 21, rand() % 81, rand() % 21);
	this->setNom("Terrae");

	int randSousType = rand() % 5;
	if (randSousType == 0) { this->setSousType("Lave"); }
	else if (randSousType == 1) { this->setSousType("Glace"); }
	else if (randSousType == 2) { this->setSousType("Ocean"); }
	else if (randSousType == 3) { this->setSousType("Roche"); }
	else if (randSousType == 4) { this->setSousType("Metal"); }
}

planeteGazeuse::planeteGazeuse() : planete() {
	this->setType("Gazeuse");
	this->setRessources(rand() % 21, rand() % 21, rand() % 201, rand() % 6, rand() % 11);
	this->setNom("Jupiterrae");

	int randSousType = rand() % 4;
	if (randSousType == 0) { this->setSousType("Jupiter Froid"); }
	else if (randSousType == 1) { this->setSousType("Jupiter Tempere"); }
	else if (randSousType == 2) { this->setSousType("Jupiter Chaud"); }
	else if (randSousType == 3) { this->setSousType("Jupirer Tres Chaud"); }
}

void planete::afficherPlanete() {
	cout << "-----------------------" << endl;
	cout << " Nom : " + this->nom << endl;
	cout << " Type : " + this->type << endl;
	cout << " Sous-type : " + this->sousType << endl;
	cout << " Ressources : " << endl;
	cout << " Charbon : " + to_string(this->ressources[0]) << endl;
	cout << " Fer : " + to_string(this->ressources[1]) << endl;
	cout << " Gaz : " + to_string(this->ressources[2]) << endl;
	cout << " Petrole : " + to_string(this->ressources[3]) << endl;
	cout << " Vie : " + to_string(this->ressources[4]) << endl;
	cout << endl;
}