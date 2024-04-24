#pragma once
#include "Plant.h"

class WolfBerries :public Plant
{
public:
	WolfBerries(int x, int y);
	void Colission(Organism* org) override;
	char Draw()override;
};