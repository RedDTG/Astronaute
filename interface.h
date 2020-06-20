#pragma once
#include <SFML/Graphics.hpp>

class interface
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape* background;
	sf::Texture* spriteBackground;

	sf::Vector2i mousePos;
	sf::CircleShape* mouseHitbox;

public:
	interface();

	sf::RenderWindow* getWindow() { return this->window; }
	sf::Vector2i getMousePos() { return this->mousePos; }

	void setMousePos(sf::Vector2i pos) {
		this->mousePos = pos; 
		this->mouseHitbox->setPosition(this->mousePos.x, this->mousePos.y);
	}

	void detectionEvents();
	void drawBackground();
};