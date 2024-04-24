#pragma once
#include "Animal.h"
class Sheep : public Animal
{
private:
	int step_y[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };
	int step_x[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	void Born(Organism* org);
public:
	Sheep();
	Sheep(int x, int y);
	//void Action(World* w)override;
	void Colission(Organism* org) override;
	char Draw() override;
};
