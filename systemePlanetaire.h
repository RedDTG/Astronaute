#pragma once
#include "planete.h"
class systemePlanetaire
{
private:
	vector<planete*> planetes;
	sf::Vector2i position;

	sf::Texture* sprite;
	sf::RectangleShape* hitbox;
	
public:
	systemePlanetaire(int posX, int posY);

	void afficher(sf::RenderWindow* window); 
};

