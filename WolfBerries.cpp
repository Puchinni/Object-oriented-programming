#include "WolfBerries.h"
#include <iostream>

WolfBerries::WolfBerries(int x, int y) :Plant(x, y)
{
	this->strength = 99;
}

void WolfBerries::Colission(Organism* org)
{
	org->Died();
}

char WolfBerries::Draw()
{
	return OrganismType::WOLF_BERRIES;
}
