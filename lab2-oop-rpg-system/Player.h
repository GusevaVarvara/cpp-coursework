#pragma once

#include "Character.h"

class Player : public Character {
public:
    Player(const std::string& name, int health, int fixedDamage);
};
