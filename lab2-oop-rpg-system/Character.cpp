#include "Character.h"

Character::Character(const std::string& name, int health, int fixedDamage)
    : name(name), health(health), fixedDamage(fixedDamage) {}


void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

int Character::getHealth() const {
    return health;
}

int Character::getDamage() const {
    return fixedDamage;
}

const std::string& Character::getName() const {
    return name;
}

void Character::addItem(const Item& item) {
    health += item.getHealthBonus();
    fixedDamage += item.getDamageBonus();

    std::cout << "Бонус к здоровью: " << item.getHealthBonus() << "\n";
    std::cout << "Бонус к наносимому урону: " << item.getDamageBonus() << "\n";
}
