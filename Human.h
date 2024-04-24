#pragma once
#include "Animal.h"
class Human :public Animal
{
private:
	int stepCount = 6;
	int baseStrength;

public :
	Human(int x, int y);
	void Action(World* w) override;
	void Colission(Organism* org) override;
	char Draw() override;
};

