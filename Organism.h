#pragma once
#include "World.h"
#include "OrganismType.h"
class World;
class Organism {
protected:
	int strength;
	int initiative;
	int x;
	int y;
	bool isDied;
public:
	Organism();
	virtual void Action(World* w) = 0;
	virtual void Colission(Organism* w) = 0;
	virtual char Draw() = 0;
	int GetStrenght();
	void SetStrength(int strenght);
	int GetInitiative();
	void SetInitiative(int initiative);
	int GetX();
	void SetX(int x);
	int GetY();
	void SetY(int y);
	void SetXY(int x, int y);
	void Died();
	bool IsDied();
};