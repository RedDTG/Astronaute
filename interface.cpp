#include "interface.h"

interface::interface() {
	this->view = 1;

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

void interface::affichageView(univers* TheUniverse) {
	if (this->view == 0) {
		//je mettrais l'ecran titre ici
	}

	else if (this->view >= 1 && this->view <=4) {
		TheUniverse->afficher(this->window, this->mousePos, this->view);
	}

	else if (this->view == 5) {
		this->galaxieView->afficherSystemes(this->window);
	}
}

void interface::detectionClic(univers* TheUniverse) {
	bool isClic = 0;

	if (this->view >= 1 && this->view <= 4) {
		for (int i = 0; i < TheUniverse->getGalaxies(this->view).size(); i++) {
			if (this->mousePos.x <= TheUniverse->getGalaxies(this->view)[i]->getPosition().x + 125
				&& mousePos.x >= TheUniverse->getGalaxies(this->view)[i]->getPosition().x - 125
				&& mousePos.y <= TheUniverse->getGalaxies(this->view)[i]->getPosition().y + 125
				&& mousePos.y >= TheUniverse->getGalaxies(this->view)[i]->getPosition().y - 125) {

				cout << TheUniverse->getGalaxies(this->view)[i]->getType() << endl;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					this->galaxieView = TheUniverse->getGalaxies(this->view)[i];
					isClic = 1;
				}
			}
		}
	}

	if (this->view == 5) {
		for (int i = 0; i < this->galaxieView->getSystemes().size(); i++) {
			if (this->mousePos.x <= this->galaxieView->getSystemes()[i]->getPosition().x + 70
				&& mousePos.x >= this->galaxieView->getSystemes()[i]->getPosition().x - 70
				&& mousePos.y <= this->galaxieView->getSystemes()[i]->getPosition().y + 70
				&& mousePos.y >= this->galaxieView->getSystemes()[i]->getPosition().y - 70) {

				cout << "Il y a " << this->galaxieView->getSystemes()[i]->getNombre() << " planetes dans ce systeme" << endl;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					this->systemeView = this->galaxieView->getSystemes()[i];
					isClic = 1;
				}
			}
		}
	}

	if (isClic == 1 && (this->view >= 1 && this->view <= 4)) {
		this->view = 5;
	}

}