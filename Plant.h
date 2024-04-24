#pragma once
#include "Organism.h"
class Plant :public Organism
{
protected:
	int GetRandomX(World* w);
	int GetRandomY(World* w);
	double probability = 7;
	int _plantX = -1, _plantY = -1;
public :
	Plant();
	Plant(int x, int y);
	void virtual Action(World* w) override;
};

