#pragma once

#include "Item.h"
#include <vector>

class Weapon : public Item {
public:
    Weapon(const std::string& name, const std::string& description, int plusHealth, int plusDamage);

    void addAvailableWeapon(const Weapon& weapon);
    static const std::vector<Weapon>& getAvailableWeapons();
    static void initializeAvailableWeapons();
    static Weapon createWeapon(const std::string& name);
private:
    static std::vector<Weapon> availableWeapons;
};
