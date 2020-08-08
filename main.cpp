#include <iostream>
#include <time.h>
#include <cstdlib>
#include "univers.h"
#include "interface.h"

int main()
{
	srand(time(NULL));
	interface* TheInterface = new interface;
	univers* TheUniverse = new univers;

	while (1) {
		TheInterface->setMousePos(sf::Mouse::getPosition(*TheInterface->getWindow()));
		TheInterface->detectionEvents();
		TheInterface->getWindow()->clear();
		TheInterface->drawBackground();
		TheInterface->affichageView(TheUniverse);
		TheInterface->detectionClic(TheUniverse);
		TheInterface->getWindow()->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) {
			TheInterface->setView(1);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2)) {
			TheInterface->setView(2);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3)) {
			TheInterface->setView(3);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4)) {
			TheInterface->setView(4);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4)) { }
		}
	}
}

