#include "galaxie.h"
galaxie::galaxie(int posX, int posY) { 
	int nbSystemes = rand() % (10 - 4) + 4;
	vector<int> lesCoX;
	vector<int> lesCoY;
	int systPosX;
	int systPosY;

	systPosX = rand() % (1500 - 200) + 200;
	systPosY = rand() % (700 - 250) + 200;

	for (int i = 0; i < nbSystemes; i++) {

		lesCoX.push_back(systPosX);
		lesCoY.push_back(systPosY);

		this->addSysteme(new systemePlanetaire(systPosX, systPosY));

		systPosX = rand() % (1500 - 200) + 200;
		systPosY = rand() % (700 - 250) + 200;
		while (this->testCoordonnees(systPosX, systPosY, lesCoX, lesCoY)) {
			systPosX = rand() % (1500 - 200) + 200;
			systPosY = rand() % (700 - 250) + 200;
		}

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
	this->setType("Spirale Barrée");
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

bool galaxie::testCoordonnees(int X, int Y, vector<int> lesX, vector<int> lesY) {
	for (int i = 0; i < lesX.size(); i++) {
		if ((X < lesX[i] + 150) && (X > lesX[i] - 150) && ((Y < lesY[i] + 150) && (Y > lesY[i] - 150))) {
			return true;
		}
	}

	return false;
}