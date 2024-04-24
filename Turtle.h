#pragma once
#include "Animal.h"
class Turtle : public Animal
{
private:
	void Born(Organism* org);
	int step_y[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };
	int step_x[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
public:
	Turtle(int x, int y);

	void Action(World* w) override;
	void Colission(Organism* org) override;
	char Draw() override;
};