#include <iostream>
#include <time.h>

#include "univers.h"
#include "interface.h"

int main()
{
	srand(time(NULL));
	
	interface* TheInterface = new interface;
	univers* TheUniverse = new univers;

	while (1) {
		TheInterface->detectionEvents();
		TheInterface->getWindow()->clear();
		TheInterface->drawBackground();
		TheUniverse->afficher(TheInterface->getWindow());
		TheInterface->getWindow()->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) {
			TheUniverse->setView(1);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2)) {
			TheUniverse->setView(2);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3)) {
			TheUniverse->setView(3);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3)) { }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4)) {
			TheUniverse->setView(4);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4)) { }
		}
	}
}

