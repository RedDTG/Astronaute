#pragma once
#include <SFML/Graphics.hpp>

class interface
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape* background;
	sf::Texture* spriteBackground;

public:
	interface();

	sf::RenderWindow* getWindow() { return this->window; }

	void detectionEvents();
	void drawBackground();
};