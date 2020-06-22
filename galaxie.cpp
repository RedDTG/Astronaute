#include "galaxie.h"
galaxie::galaxie(int posX, int posY) { 
	int nbSystemes = rand() % (10 - 4) + 4;

	for (int i = 0; i < nbSystemes; i++) {
		sf::Vector2i position;
		position.x = rand() % (1500 - 200) + 200;
		position.y = rand() % (700 - 250) + 200;
		int leRand = rand() % 2;
		if (leRand == 0) { this->addSysteme(new systemePlanetaire(position)); } //jsp pk c'est comme ca je verrais plus tard
		else if (leRand == 1) { this->addSysteme(new systemePlanetaire(position)); }
	}

	this->hitbox = new sf::RectangleShape(sf::Vector2f(250, 250));
	sf::FloatRect hitboxRect = this->hitbox->getLocalBounds();
	this->hitbox->setOrigin(hitboxRect.left + hitboxRect.width / 2.0f,
		hitboxRect.top + hitboxRect.height / 2.0f);

	//this->hitbox->setFillColor(sf::Color::Red);

	this->position.x = posX;
	this->position.y = posY;

	this->hitbox->setPosition(this->position.x, this->position.y);
}

galaxieSpirale::galaxieSpirale(int posX, int posY) : galaxie(posX, posY) {
	this->setType("Spirale");
	this->setSprite(new sf::Texture);
	int randSprite = rand() % 3;
	if (randSprite == 0 ) { this->getSprite()->loadFromFile("sprites/galaxies/spirales/spirale1.png"); }
	else if (randSprite == 1) { this->getSprite()->loadFromFile("sprites/galaxies/spirales/spirale2.png"); }
	else { this->getSprite()->loadFromFile("sprites/galaxies/spirales/spirale3.png"); }
	this->getHitbox()->setTexture(this->getSprite());
}

galaxieEliptique::galaxieEliptique(int posX, int posY) : galaxie(posX, posY) {
	this->setType("Eliptique");
	this->setSprite(new sf::Texture);
	int randSprite = rand() % 3;
	if (randSprite == 0) { this->getSprite()->loadFromFile("sprites/galaxies/eliptiques/eliptique1.png"); }
	else { this->getSprite()->loadFromFile("sprites/galaxies/eliptiques/eliptique2.png"); }
	this->getHitbox()->setTexture(this->getSprite());
}

galaxieSpiraleBarree::galaxieSpiraleBarree(int posX, int posY) : galaxie(posX, posY) {
	this->setType("Spirale Barr�e");
	this->setSprite(new sf::Texture);
	int randSprite = rand() % 3;
	if (randSprite == 0) { this->getSprite()->loadFromFile("sprites/galaxies/spirales_barrees/barree1.png"); }
	else { this->getSprite()->loadFromFile("sprites/galaxies/spirales_barrees/barree2.png"); }
	this->getHitbox()->setTexture(this->getSprite());
}

void galaxie::afficher(sf::RenderWindow* window) {
	window->draw(*this->hitbox);
}

void galaxie::afficherSystemes(sf::RenderWindow* window) {
	for (int i = 0; i < this->systemes.size(); i++) {
		this->systemes[i]->afficher(window);
	}
}