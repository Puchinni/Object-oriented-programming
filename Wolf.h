#pragma once
#include "Animal.h"
class Wolf : public Animal
{
private:
	int step_y[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };
	int step_x[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
public:
	Wolf();
	Wolf(int x, int y);
	//void Action(World*) override;
	void Colission(Organism* org) override;
	char Draw() override;
};
