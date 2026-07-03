#pragma once

#include "Item.h"
#include <vector>

class Potion : public Item {
public:
    Potion(const std::string& name, const std::string& description, int plusHealth, int plusDamage);

    void addAvailablePotion(const Potion& potion);
    static const std::vector<Potion>& getAvailablePotions();
    static void initializeAvailablePotions();
    static Potion createPotion(const std::string& name);
private:
    static std::vector<Potion> availablePotions;
};

