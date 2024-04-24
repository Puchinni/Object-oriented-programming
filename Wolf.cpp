#include "Wolf.h"
#include <iostream>

Wolf::Wolf()
{
	this->initiative = 5;
	this->strength = 9;
}

Wolf::Wolf(int x, int y): Animal(x, y)
{
	this->initiative = 5;
	this->strength = 9;
}

void Wolf::Colission(Organism* org)
{
	if (dynamic_cast<Wolf*>(org) != nullptr) {

		int x_{ -1 }, y_{ -1 };
		for (int i = 0; i < 8; i++)
		{
			x_ = this->x + step_x[i];
			y_ = this->y + step_y[i];

			if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {

				Wolf* wolf = new Wolf(x_, y_);
				wolf->SetWorld(world);

				world->organisms.push_back(wolf);
				return;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			x_ = org->GetX() + step_x[i];
			y_ = org->GetY() + step_y[i];
			if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {
				Wolf* wolf = new Wolf(x_, y_);
				wolf->SetWorld(world);

				world->organisms.push_back(wolf);
				return;
			}
		}

	}
}

char Wolf::Draw()
{
	return OrganismType::WOLF;
}
