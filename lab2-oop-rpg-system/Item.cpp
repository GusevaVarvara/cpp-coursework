#include "Item.h"

Item::Item(const std::string& name, const std::string& description, int plusHealth, int plusDamage)
    : name(name), description(description), plusHealth(plusHealth), plusDamage(plusDamage) {}

const std::string& Item::getName() const {
    return name;
}
const std::string& Item::getDescription() const {
    return description;
}
int Item::getHealthBonus() const {
    return plusHealth;
}

int Item::getDamageBonus() const {
    return plusDamage;
}
