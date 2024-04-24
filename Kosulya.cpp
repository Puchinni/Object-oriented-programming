#include "Kosulya.h"

Kosulya::Kosulya(int x, int y) :Plant(x, y){}

void Kosulya::Action(World* w)
{
	for (int i = 0; i < 3; i++)
	{
		Plant::Action(w);
		if (_plantX != -1 && _plantY != -1 && w->isEmptyCell(_plantX, _plantY)) {
			w->organisms.push_back((Organism*)new Kosulya(_plantX, _plantY));
		}

		_plantX = -1;
		_plantY = -1;
	}
}
void Kosulya::Colission(Organism* org) {
	if (this->strength < org->GetStrenght()) {
		Died();
	}
}

char Kosulya::Draw() { return OrganismType::KOSYLYA; }