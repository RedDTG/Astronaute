#include "systemePlanetaire.h"

systemePlanetaire::systemePlanetaire(int posX, int posY) {
	int nbPlanetes = rand() % (10 - 4) + 4;
	
	for (int i = 0; i < nbPlanetes; i++) {
		int leRand = rand() % 2;
		if (leRand == 0) { this->planetes.push_back(new planeteTellurique()); }
		else if (leRand == 1) { this->planetes.push_back(new planeteGazeuse()); }
	}

	this->hitbox = new sf::RectangleShape(sf::Vector2f(40, 40));
	sf::FloatRect hitboxRect = this->hitbox->getLocalBounds();
	this->hitbox->setOrigin(hitboxRect.left + hitboxRect.width / 2.0f,
		hitboxRect.top + hitboxRect.height / 2.0f);
	
	this->position.x = posX;
	this->position.y = posY;
	this->hitbox->setPosition(this->position.x, this->position.y);
	
	this->sprite = new sf::Texture;
	this->sprite->loadFromFile("sprites/planetes/sun.png");
	this->hitbox->setTexture(this->sprite); 

	for (int i = 0; i < nbPlanetes; i++) {
		this->cercles.push_back(new sf::CircleShape((i*8)+30));
		this->cercles[i]->setFillColor(sf::Color::Transparent);
		this->cercles[i]->setOutlineColor(sf::Color::White);
		this->cercles[i]->setOutlineThickness(-1);
		sf::FloatRect cercleRect = this->cercles[i]->getLocalBounds();
		this->cercles[i]->setOrigin(cercleRect.left + cercleRect.width / 2.0f,
			cercleRect.top + cercleRect.height / 2.0f);
		this->cercles[i]->setPosition(this->position.x, this->position.y);
	}

}
	

void systemePlanetaire::afficher(sf::RenderWindow* window) {
	window->draw(*this->hitbox); 
	for (int i = 0; i < this->cercles.size(); i++) {
		window->draw(*this->cercles[i]);
	}
}