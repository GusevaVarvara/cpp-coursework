#pragma once

#include "Item.h"
#include <vector>

class Armor : public Item {
public:
    Armor(const std::string& name, const std::string& description, int plusHealth, int plusDamage);

    void addAvailableArmor(const Armor& armor);
    static const std::vector<Armor>& getAvailableArmors();
    static void initializeAvailableArmors();
    static Armor createArmor(const std::string& name);
private:
    static std::vector<Armor> availableArmors;
};
