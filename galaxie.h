#pragma once
#include "systemePlanetaire.h"

class galaxie
{
private:
	vector<systemePlanetaire*> systemes;
	string type;
	sf::Vector2i position;

	sf::Texture* sprite;
	sf::RectangleShape* hitbox;


public:
	galaxie(int posX, int posY);

	void detectionClic(sf::Vector2i mousePos);
	void addSysteme(systemePlanetaire* systeme) {
		this->systemes.push_back(systeme);
	}
	void setType(string type) { this->type = type; }
	void setSprite(sf::Texture* sprite) { this->sprite = sprite; }

	sf::Texture* getSprite() { return this->sprite; }
	sf::RectangleShape* getHitbox() { return this->hitbox; }

	void afficher(sf::RenderWindow* window);
};

class galaxieSpirale : public galaxie
{
private:

public:
	galaxieSpirale(int posX, int posY);
};

class galaxieEliptique : public galaxie
{
private:

public:
	galaxieEliptique(int posX, int posY);
};

class galaxieSpiraleBarree : public galaxie
{
private:

public:
	galaxieSpiraleBarree(int posX, int posY);
};
