#pragma once
#include "galaxie.h"

class univers
{
private:
	vector<galaxie*> Q1galaxies;
	vector<galaxie*> Q2galaxies;
	vector<galaxie*> Q3galaxies;
	vector<galaxie*> Q4galaxies;

	int view;

public:
	univers();

	void afficher(sf::RenderWindow* window, sf::Vector2i mousePos);
	void setView(int view) { this->view = view; }
	void placementGalaxies();
	bool testCoordonnees(int X, int Y, vector<int> lesX, vector<int> lesY);

	vector<galaxie*> getGalaxies() { 
		if (this->view == 1) { return this->Q1galaxies; }
		else if (this->view == 2) { return this->Q2galaxies; }
		else if (this->view == 3) { return this->Q3galaxies; }
		else { return this->Q4galaxies; }
	}

};

