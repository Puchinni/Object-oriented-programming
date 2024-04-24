#include "Organism.h"

Organism::Organism()
{
    isDied = false;
    x = -1;
    y = -1;
}

int Organism::GetStrenght()
{
    return strength;
}

void Organism::SetStrength(int strenght)
{
    this->strength = strenght;
}

int Organism::GetInitiative()
{
    return initiative;
}

void Organism::SetInitiative(int initiative)
{
    this->initiative = initiative;
}

int Organism::GetX()
{
    return x;
}

void Organism::SetX(int x)
{
    this->x = x;
}

int Organism::GetY()
{
    return y;
}

void Organism::SetY(int y)
{
    this->y = y;
}

void Organism::SetXY(int x, int y)
{
    SetX(x);
    SetY(y);
}

void Organism::Died()
{
    this->isDied = true;
}

bool Organism::IsDied()
{
    return isDied;
}
