#pragma once
#include "Organism.h"

class OrganismFactory {
public:
    static Organism* Create(OrganismType type, int x, int y);
};