#include "Plant.h"
#include <ctime>
int Plant::GetRandomX(World* w)
{
	while (true)
	{
		int x = rand() % 3 - 1;

		int result_x = this->x + x;

		if (result_x >= 0 && result_x < w->GetCol()) {
			return result_x;
		}
	}

	return 0;
}

int Plant::GetRandomY(World* w)
{

	while (true)
	{
		int y = rand() % 3 - 1;

		int result_y = this->y + y;

		if (result_y >= 0 && result_y < w->GetRow()) {
			return result_y;
		}
	}

	return 0;
}

Plant::Plant() {
	this->initiative = 0;
	this->strength = 0;

	srand(time(NULL));
}

Plant::Plant(int x, int y) :Plant()
{
	this->x = x;
	this->y = y;
}

void Plant::Action(World* w)
{
	if (rand() % (int)probability == 0) {
		_plantX = GetRandomX(w);
		_plantY= GetRandomY(w);
		probability += 0.5;
	}
}

//void Plant::Colission(Organism* w)
//{
//}
//
//char Plant::Draw()
//{
//	return '~';
//}

