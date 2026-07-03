#include "Potion.h"

std::vector<Potion> Potion::availablePotions;

Potion::Potion(const std::string& name, const std::string& description, int plusHealth, int plusDamage)
    : Item(name, description, plusHealth, plusDamage) {}

void Potion::addAvailablePotion(const Potion& potion) {
    availablePotions.push_back(potion);
}

void Potion::initializeAvailablePotions() {

    Potion demonicEssence("DemonicEssence", "Демоническая Эссенция Жгучего Огня - это зелье придает силы огня, усиливая атаки и делая владельца "
                            "временно иммунным к огненным атакам.", 3, 5);


    Potion elvenEssence("ElvenEssence", "Эльфийская Эссенция Лесной Скорости - это зелье придает владельцу невероятную ловкость и скорость, что "
                          "улучшает маневренность в бою. ", 5, 5);


    Potion vampiricEssence("VampiricEssence", "Вампирская Кровавая Эссенция - это зелье позволяет владельцу впитывать часть здоровья противника "
                                      "при каждой атаке. Оно изготавливается из крови убитого вампира, придаваясь его мистической "
                                      "сущности.", 10, 2);

    availablePotions.push_back(demonicEssence);
    availablePotions.push_back(elvenEssence);
    availablePotions.push_back(vampiricEssence);
}

const std::vector<Potion>& Potion::getAvailablePotions() {
    if (availablePotions.empty()) {
        initializeAvailablePotions();
    }
    return availablePotions;
}
Potion Potion::createPotion(const std::string& name) {
    const auto& potions = Potion::getAvailablePotions();

    for (const auto& potion : potions) {
        if (potion.getName() == name) {
            return potion;
        }
    }
    return Potion("?", "Описание отсутствует", 0, 0);
}
