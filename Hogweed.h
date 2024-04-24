#pragma once
#include "Animal.h"
class Hogweed : Animal
{

private:
	int step_y[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };
	int step_x[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	void Born(Organism* org);
public:
	Hogweed(int x, int y);

	void Action(World* w) override;
	void Colission(Organism* w) override;
	char Draw() override;
};