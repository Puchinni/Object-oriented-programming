#include "OrganismFactory.h"
#include "Fox.h"
#include "Guarana.h"
#include "Grass.h"
#include "Hogweed.h"
#include "Human.h"
#include "Kosulya.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "WolfBerries.h"
#include "Antelope.h"
Organism* OrganismFactory::Create(OrganismType type, int x, int y)
{
	switch (type)
	{
	case EMPTY: return nullptr;
	case FOX: return new Fox(x, y);
	case GUARANA: return new Guarana(x, y);
	case GRASS: return new Grass(x, y);
	case HOGWEED: return (Organism*)new Hogweed(x, y);
	case HUMAN: return new Human(x, y);
	case KOSYLYA: return new Kosulya(x, y);
	case SHEEP: return new Sheep(x, y);
	case TURTLE: return new Turtle(x, y);
	case WOLF: return new Wolf(x, y);
	case WOLF_BERRIES: new WolfBerries(x, y);
	case ANTELOPA: return new Antelope(x, y);
	}
	throw std::exception("unknow organism request created");
}
