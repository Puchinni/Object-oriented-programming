#include "Antelope.h"
#include <iostream>

Antelope::Antelope(int x, int y) :Animal(x, y)
{
	this->initiative = 4;
	this->strength = 4;
}

void Antelope::Action(World* w)
{
	Animal::Action(w);
	Animal::Action(w);

	
}

void Antelope::Colission(Organism* org)
{
	if (rand() % 10 > 5) {
		Animal::Action(world);
		Animal::Action(world);
		return;
	}
	if (this->strength < org->GetStrenght()) {
		Died();
	}
}

char Antelope::Draw()
{
	return OrganismType::ANTELOPA;
}