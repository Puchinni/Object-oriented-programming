#pragma once
#include "Plant.h"
class Kosulya :public Plant
{
public:
	Kosulya(int x, int y);

	void Action(World* w) override;
	void Colission(Organism* w) override;
	char Draw()override;
};

