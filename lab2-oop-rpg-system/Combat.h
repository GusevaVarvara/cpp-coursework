#pragma once

#include "Character.h"
#include "Enemy.h"
#include "Pet.h"
#include "Player.h"
#include "Dice.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

class Combat {
public:
    Combat(std::vector<Character>& players);

    void startCombat();
    void rewardPlayer();

private:
    std::vector<Character>& players;
    Dice dice;
};

