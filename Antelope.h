#pragma once
#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(int x, int y);

	void Action(World* w) override;
	void Colission(Organism* w) override;

	char Draw() override;
};
