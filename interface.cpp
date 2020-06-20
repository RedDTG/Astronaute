#include "interface.h"

interface::interface() {
	this->window = new sf::RenderWindow(sf::VideoMode(1700, 900), "Astronaute", sf::Style::Close);
	this->background = new sf::RectangleShape(sf::Vector2f(1700, 900));
	this->spriteBackground = new sf::Texture;
	this->spriteBackground->loadFromFile("sprites/backgrounds/univers.png");
	this->background->setTexture(this->spriteBackground);
	this->background->setPosition(0, 0);

	this->mouseHitbox = new sf::CircleShape(10);
	this->mouseHitbox->setPosition(this->mousePos.x, this->mousePos.y);
	sf::FloatRect mouseHitboxRect = this->mouseHitbox->getLocalBounds();
	this->mouseHitbox->setOrigin(mouseHitboxRect.left + mouseHitboxRect.width / 2.0f,
		mouseHitboxRect.top + mouseHitboxRect.height / 2.0f);
	this->mouseHitbox->setFillColor(sf::Color::Green);
}

void interface::detectionEvents() {
	sf::Event evnt;
	while (this->window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}

}

void interface::drawBackground() {
	this->window->draw(*this->background);
	//this->window->draw(*this->mouseHitbox);

}