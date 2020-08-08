#pragma once
#include "planete.h"
class systemePlanetaire
{
private:
	vector<planete*> planetes;
	sf::Vector2i position;

	sf::Texture* sprite;
	sf::RectangleShape* hitbox;
	
	vector<sf::CircleShape*> cercles;
	
public:
	systemePlanetaire(int posX, int posY);

	sf::Vector2i getPosition() { return this->position; }
	int getNombre() { return this->planetes.size(); }

	void afficher(sf::RenderWindow* window); 

	void afficherPlanetes(sf::RenderWindow* window);

};

