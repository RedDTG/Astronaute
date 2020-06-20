#pragma once
#include <vector>
#include "piece.h"
#include "module.h"
using namespace std;

class fusee
{
private:
	int essence;
	int oxygene;
	int nbPieces;
	vector<piece> pieces;
	vector<module> modules;

public:
	void creationModule();
	void creationPiece();
	void dommageModule();
	void dommagePiece();

};

