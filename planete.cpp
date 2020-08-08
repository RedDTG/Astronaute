#include "planete.h"

planete::planete(int posX, int posY) {
	this->sprite = new sf::Texture;
	this->hitbox = new sf::RectangleShape(sf::Vector2f(100, 100));
	sf::FloatRect hitboxRect = this->hitbox->getLocalBounds();
	this->hitbox->setOrigin(hitboxRect.left + hitboxRect.width / 2.0f,
		hitboxRect.top + hitboxRect.height / 2.0f);

	this->position.x = posX;
	this->position.y = posY;
	this->hitbox->setPosition(this->position.x, this->position.y);

	this->sprite = new sf::Texture;
}

planeteTellurique::planeteTellurique(int posX, int posY) : planete(posX, posY) {
	this->setType("Tellurique");
	this->setRessources(rand() % 101, rand() % 101, rand() % 21, rand() % 81, rand() % 21);
	this->setNom("Terrae");

	int randSousType = rand() % 5;
	if (randSousType == 0) { 
		this->setSousType("Lave"); 
		this->setSprite("sprites/planetes/telluriques/lave.png");
	}
	else if (randSousType == 1) {
		this->setSousType("Glace");
		this->setSprite("sprites/planetes/telluriques/glace.png");
	}
	else if (randSousType == 2) { 
		this->setSousType("Ocean");
		this->setSprite("sprites/planetes/telluriques/ocean.png");
	}
	else if (randSousType == 3) {
		this->setSousType("Roche");
		this->setSprite("sprites/planetes/telluriques/roche.png");
	}
	else if (randSousType == 4) {
		this->setSousType("Terre");
		this->setSprite("sprites/planetes/telluriques/terre.png");
	}

}

planeteGazeuse::planeteGazeuse(int posX, int posY) : planete(posX, posY) {
	this->setType("Gazeuse");
	this->setRessources(rand() % 21, rand() % 21, rand() % 201, rand() % 6, rand() % 11);
	this->setNom("Jupiterrae");

	int randSousType = rand() % 4;
	if (randSousType == 0) {
		this->setSousType("Jupiter Froid");
		this->setSprite("sprites/planetes/gazeuses/froid.png");
	}
	else if (randSousType == 1) {
		this->setSousType("Jupiter Tempere");
		this->setSprite("sprites/planetes/gazeuses/tempere.png");
	}
	else if (randSousType == 2) {
		this->setSousType("Jupiter Chaud");
		this->setSprite("sprites/planetes/gazeuses/chaud.png");
	}
	else if (randSousType == 3) {
		this->setSousType("Jupirer Tres Chaud");
		this->setSprite("sprites/planetes/gazeuses/chaud.png");
	}
}

void planete::afficher(sf::RenderWindow* window) {
	window->draw(*this->hitbox);
}

void planete::oldAfficher() {
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
