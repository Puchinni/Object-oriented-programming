#include "Human.h"
#include <conio.h>
Human::Human(int x, int y):Animal(x, y)
{
    baseStrength =  this->strength = 5;
    this->initiative = 4;
}

void Human::Action(World* w)
{
    char ch = _getch();
    if (ch == 0x4B) {
        if(x -1 >=0) x--;
    }
    else if (ch == 0x48) {
        if (y - 1 >= 0)y--;
    }
    else if (ch == 0x4D) {
        if (x + 1 < w->GetCol() )x++;
    }
    else if (ch == 0x50) {
        if (y + 1 < w->GetRow()) y++;
    }
    stepCount++;
    if (this->strength > baseStrength) {
        this->strength--;
    }

}

void Human::Colission(Organism* org)
{
    if (stepCount < 5) {
        return;
    }
    stepCount = 0;
    this->strength += 10;
}

char Human::Draw()
{
    return OrganismType::HUMAN;
}
