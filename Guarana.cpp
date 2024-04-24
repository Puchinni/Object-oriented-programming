#include "Guarana.h"

Guarana::Guarana(int x, int y) :Plant(x, y)
{
	this->initiative = 0;
	this->strength = 0;
}

void Guarana::Colission(Organism* org)
{
	if (this->strength < org->GetStrenght()) {
		org->SetStrength(org->GetStrenght() + 3);
		Died();
	}
}

char Guarana::Draw()
{
	return OrganismType::GUARANA;
}
