#pragma once
#include "Plant.h"

class Guarana :public Plant
{
public:
	Guarana(int x, int y);
	void Colission(Organism* org) override;
	char Draw() override;
};
