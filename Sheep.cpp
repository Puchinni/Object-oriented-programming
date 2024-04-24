#include "Sheep.h"
#include <iostream>

Sheep::Sheep()
{
	this->initiative = 4;
	this->strength = 4;
}

Sheep::Sheep(int x, int y) :Animal(x, y)
{
	this->strength = 4;
	this->initiative = 4;
}

//void Sheep::Action(World* w)
//{
//}

void Sheep::Colission(Organism* org)
{
	if (dynamic_cast<Sheep*>(org) != nullptr) {
		Born(org);
	}
	else {
		if (this->strength < org->GetStrenght()) {
			Died();
		}
	}
}

void Sheep::Born(Organism* org) {
	int x_{ -1 }, y_{ -1 };
	for (int i = 0; i < 8; i++)
	{
		x_ = this->x + step_x[i];
		y_ = this->y + step_y[i];

		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {

			Sheep* sheep = new Sheep(x_, y_);
			sheep->SetWorld(world);

			world->organisms.push_back(sheep);
			return;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		x_ = org->GetX() + step_x[i];
		y_ = org->GetY() + step_y[i];
		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {
			Sheep* sheep = new Sheep(x_, y_);
			sheep->SetWorld(world);

			world->organisms.push_back(sheep);
			return;
		}
	}

}

char Sheep::Draw()
{
	return OrganismType::SHEEP;
}
