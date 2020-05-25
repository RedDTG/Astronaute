#pragma once
#include "systemePlanetaire.h"

class galaxie
{
private:
	vector<systemePlanetaire*> systemes;
	string type;
public:
	galaxie();

	void addSysteme(systemePlanetaire* systeme) {
		this->systemes.push_back(systeme);
	}
};

class galaxieSpirale : public galaxie
{
private:

public:
	//galaxieSpirale();
};

class galaxieEliptique : public galaxie
{
private:

public:
	//galaxieEliptique();
};

class galaxieSpiraleBaree : public galaxie
{
private:

public:
	//galaxieSpiraleBaree();
};
