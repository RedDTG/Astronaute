#pragma once
#include <SFML/Graphics.hpp>
#include "univers.h"

class interface
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape* background;
	sf::Texture* spriteBackground;

	sf::Vector2i mousePos;
	sf::CircleShape* mouseHitbox;

	galaxie* galaxieView;
	systemePlanetaire* systemeView;
	planete* planeteView;

	int view;

public:
	interface();

	sf::RenderWindow* getWindow() { return this->window; }
	sf::Vector2i getMousePos() { return this->mousePos; }

	void setMousePos(sf::Vector2i pos) {
		this->mousePos = pos; 
		this->mouseHitbox->setPosition(this->mousePos.x, this->mousePos.y);
	}

	void setView(int view) { this->view = view; }
	int getView() { return this->view; }

	void affichageView(univers* TheUniverse);
	void detectionClic(univers* TheUniverse);
	void detectionEvents();
	void drawBackground();
};