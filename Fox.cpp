#include "Fox.h"
#include <iostream>


Fox::Fox(int x, int y) :Animal(x, y)
{
	this->initiative = 7;
	this->strength = 3;
}
void Fox::Action(World* w)
{
	int stepCount = 0;

	for (int i = 0; i < 8; i++)
	{
		if (!world->isCellExists(this->x + step_x[i], this->y + step_y[i])) {
			stepCount++;
		}
	}

	while (stepCount < 8) {

		int x_ = GetRandomX(w);
		int y_ = GetRandomY(w);

		if (world->isCellExists(x_, y_)) {
			if (world->isEmptyCell(x_, y_)) {
				this->x = x_;
				this->y = y_;
				return;
			}
			else {
				Organism* org = w->GetOrganismByPosition(x_, y_);

				if (org->GetStrenght() >= this->GetStrenght()) {
					return;
				}

				org->Colission(this);
				return;
			}
		}

	}

}

void Fox::Colission(Organism* org)
{
	if (dynamic_cast<Fox*>(org) != nullptr) {
		Born(org);
	}
	else {
		if (this->strength < org->GetStrenght()) {
			Died();
		}
	}
}

void Fox::Born(Organism* org) {
	int x_{ -1 }, y_{ -1 };
	for (int i = 0; i < 8; i++)
	{
		x_ = this->x + step_x[i];
		y_ = this->y + step_y[i];

		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {

			Fox* fox = new Fox(x_, y_);
			fox->SetWorld(world);

			world->organisms.push_back(fox);
			return;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		x_ = org->GetX() + step_x[i];
		y_ = org->GetY() + step_y[i];
		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {
			Fox* fox = new Fox(x_, y_);
			fox->SetWorld(world);

			world->organisms.push_back(fox);
			return;
		}
	}

}

char Fox::Draw()
{
	return OrganismType::FOX;
}
