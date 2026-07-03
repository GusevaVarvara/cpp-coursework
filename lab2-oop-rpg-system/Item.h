#pragma once

#include <iostream>
#include <vector>

class Item {
public:
    Item(const std::string& name, const std::string& description, int plusHealth, int plusDamage);

    const std::string& getName() const;
    const std::string& getDescription() const;
    int getHealthBonus() const;
    int getDamageBonus() const;

private:
    std::string name;
    std::string description;
    int plusHealth;
    int plusDamage;
};