#include "systemePlanetaire.h"

systemePlanetaire::systemePlanetaire(int posX, int posY) {
	int nbPlanetes = rand() % (10 - 4) + 4;
	
	for (int i = 0; i < nbPlanetes; i++) {
		int leRand = rand() % 2;
		if (leRand == 0) { this->planetes.push_back(new planeteTellurique()); }
		else if (leRand == 1) { this->planetes.push_back(new planeteGazeuse()); }
	}

	this->hitbox = new sf::RectangleShape(sf::Vector2f(100, 100));
	sf::FloatRect hitboxRect = this->hitbox->getLocalBounds();
	this->hitbox->setOrigin(hitboxRect.left + hitboxRect.width / 2.0f,
		hitboxRect.top + hitboxRect.height / 2.0f);
	
	this->position.x = posX;
	this->position.y = posY;
	this->hitbox->setPosition(this->position.x, this->position.y);
	
	this->sprite = new sf::Texture;
	this->sprite->loadFromFile("sprites/planetes/sun.png");
	this->hitbox->setTexture(this->sprite); 
}

void systemePlanetaire::afficher(sf::RenderWindow* window) {
	window->draw(*this->hitbox); 
}