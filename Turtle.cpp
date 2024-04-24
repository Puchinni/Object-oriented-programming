#include "Turtle.h"
#include <iostream>

Turtle::Turtle(int x, int y)
{
	this->initiative = 1;
	this->strength = 2;
}

void Turtle::Action(World* w)
{
	if (rand() % 100 > 75) {
		Animal::Action(w);
	}
}

void Turtle::Colission(Organism* org)
{

	if (dynamic_cast<Turtle*>(org) != nullptr) {
		Born(org);
	}
	else {
		if (5 > org->GetStrenght()) {
			Died();
		}
		else {
			org->Action(world);
		}
	}
}

void Turtle::Born(Organism* org) {
	int x_{ -1 }, y_{ -1 };
	for (int i = 0; i < 8; i++)
	{
		x_ = this->x + step_x[i];
		y_ = this->y + step_y[i];

		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {

			Turtle* turtle = new Turtle(x_, y_);
			turtle->SetWorld(world);

			world->organisms.push_back(turtle);
			return;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		x_ = org->GetX() + step_x[i];
		y_ = org->GetY() + step_y[i];
		if (world->isCellExists(x_, y_) && world->isEmptyCell(x_, y_)) {
			Turtle* turtle = new Turtle(x_, y_);
			turtle->SetWorld(world);

			world->organisms.push_back(turtle);
			return;
		}
	}

}

char Turtle::Draw()
{
	return OrganismType::TURTLE;
}
