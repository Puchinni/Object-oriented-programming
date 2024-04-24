#include "Hogweed.h"
#include <iostream>

Hogweed::Hogweed(int x, int y):Animal(x, y) 
{
	this->strength = 10;
}

void Hogweed::Action(World* w)
{
	Animal::Action(w);
	for (int i = 0; i < 8; i++)
	{
		int x_ = this->x + step_x[i];
		int y_ = this->y + step_y[i];

		if (world->isCellExists(x_, y_) && !world->isEmptyCell(x_, y_)) {

			w->GetOrganismByPosition(x_, y_)->Died();
			return;
		}
	}
}

void Hogweed::Colission(Organism* org)
{

	if (dynamic_cast<Hogweed*>(org) != nullptr) {
		Born(org);
	}
	else {
		org->Died();
	}
}

void Hogweed::Born(Organism* org) {
	int x_{ -1 }, y_{ -1 };
	for (int i = 0; i < 8; i++)
	{
		x_ = this->x + step_x[i];
		y_ = this->y + step_y[i];

		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {

			Hogweed* hogweed = new Hogweed(x_, y_);
			hogweed->SetWorld(world);

			world->organisms.push_back(hogweed);
			return;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		x_ = org->GetX() + step_x[i];
		y_ = org->GetY() + step_y[i];
		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {
			Hogweed* hogweed = new Hogweed(x_, y_);
			hogweed->SetWorld(world);

			world->organisms.push_back(hogweed);
			return;
		}
	}

}

char Hogweed::Draw()
{
	return OrganismType::HOGWEED;
}
