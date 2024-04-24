#pragma once
#include "Organism.h"

class Animal :public Organism
{
protected:
	int GetRandomX(World* w);
	int GetRandomY(World* w);
	double probability = 8;
	int _animalX = -1, _animalY = -1;
	World* world = nullptr;
public:
	Animal();
	Animal(int x, int y);
	void virtual Action(World* w) override;
	void SetWorld(World* w);
	//virtual void Colission(Organism* w) override;
	//virtual char Draw() override;

};

