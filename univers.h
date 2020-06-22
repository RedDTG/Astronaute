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

	void afficher(sf::RenderWindow* window, sf::Vector2i mousePos, int view);
	void placementGalaxies();
	bool testCoordonnees(int X, int Y, vector<int> lesX, vector<int> lesY);

	vector<galaxie*> getGalaxies(int view) { 
		if (view == 1) { return this->Q1galaxies; }
		else if (view == 2) { return this->Q2galaxies; }
		else if (view == 3) { return this->Q3galaxies; }
		else if (view == 4) { return this->Q4galaxies; }
	}

};

