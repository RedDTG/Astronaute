#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class planete
{
private:
	string nom;
	string type;
	string sousType;
	vector<int> ressources;
	// 0 : Charbon | 1 : Fer | 2 : Gaz naturel
	// 3 : Pétrole | 4 : Vie

	sf::RectangleShape* hitbox;
	sf::Texture* sprite;
	sf::Vector2i position;

	vector<string> couches;
	vector<int> tailleCouches;


public:
	planete(int posX, int posY);
	string getNom() { return this->nom; };
	string getType() { return this->type; };
	int getRessources(int type) { return this->ressources[type]; };

	void setNom(string nom) { this->nom = nom; };
	void setType(string type) { this->type = type; }
	void setRessources(int charbon, int fer, int gaz, int petrole, int vie) {
		this->ressources.push_back(charbon); 
		this->ressources.push_back(fer);
		this->ressources.push_back(gaz);
		this->ressources.push_back(petrole);
		this->ressources.push_back(vie);
	}
	void setSousType(string sousType) { this->sousType = sousType; }
	void setSprite(string path) { this->sprite->loadFromFile(path);
								  this->hitbox->setTexture(this->sprite); }

	void oldAfficher();
	void afficher(sf::RenderWindow* window);
};

class planeteGazeuse : public planete {
private:

public:
	planeteGazeuse(int planPosX, int planPosY);
};

class planeteTellurique : public planete {
private:

public:
	planeteTellurique(int planPosX, int planPosY);
};

