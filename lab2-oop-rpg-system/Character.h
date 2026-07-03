#pragma once

#include <iostream>
#include <string>
#include "Item.h" 

class Character {
public:
    Character(const std::string& name, int health, int fixedDamage);

    virtual void takeDamage(int damage);
    int getHealth() const;
    int getDamage() const;
    const std::string& getName() const;
    void addItem(const Item& item);

private:
    std::string name;
    int health;
    int fixedDamage;
};


