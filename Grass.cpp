#include "Grass.h"
#include <ctime>

Grass::Grass()
{
}

Grass::Grass(int x, int y) : Plant(x, y) {}

void Grass::Colission(Organism* w)
{
	if (this->strength < w->GetStrenght()) {
		Died();
	}
}

void Grass::Action(World* w)
{
	Plant::Action(w);
	if (_plantX != -1 && _plantY != -1 && w->isEmptyCell(_plantX, _plantY)) {
		w->organisms.push_back((Organism*)new Grass(_plantX, _plantY));
		w->SetOrganismOnBoard(_plantX, _plantY, w->organisms[w->organisms.size()-1]);
	}

	_plantX = -1;
	_plantY = -1;
}

char Grass::Draw()
{
	return OrganismType::GRASS;
}
