#pragma once
#include "Plant.h"
class Grass : public Plant
{
private:
public:
	Grass();
	Grass(int x, int y);
	

	void Action(World* w) override;
	void Colission(Organism* w) override;
	char Draw() override;
};

