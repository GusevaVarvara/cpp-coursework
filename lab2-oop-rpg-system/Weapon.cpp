#include "Weapon.h"

std::vector<Weapon> Weapon::availableWeapons;

Weapon::Weapon(const std::string& name, const std::string& description, int plusHealth, int plusDamage)
    : Item(name, description, plusHealth, plusDamage) {}

void Weapon::addAvailableWeapon(const Weapon& weapon) {
    availableWeapons.push_back(weapon);
}

void Weapon::initializeAvailableWeapons() {

    Weapon chaosblade("ChaosBlade", "Демонический Клинок Хаоса - это оружие обладает огненными рунами, выгравированными в темном металле. "
                            "Каждый удар этим клинком вызывает мгновенный ожог, а его острый лезвие способно проникнуть даже через "
                            "самые прочные доспехи.", 0, 7);


    Weapon moonshadowBow("MoonshadowBow", "Эльфийский Лунный Лук - этот лук обработан волшебными растениями, произрастающими только в дремучих "
                                          "лесах эльфов.Стрелы, выпущенные из этой дуги, обладают магическим эффектом, позволяя следить за "
                                          "целью и мгновенно находить слабые места в доспехах.", 0, 9);


    Weapon bloodhoundDagger("BloodhoundDagger", "Кровавый Кинжал Вампиризма - кинжал этого типа имеет лезвие, покрытое материей из сгустков темной крови "
                                      "вампира. При поражении врага, кинжал впитывает часть его жизненной энергии, передавая её владельцу.", 2, 10);

    availableWeapons.push_back(chaosblade);
    availableWeapons.push_back(moonshadowBow);
    availableWeapons.push_back(bloodhoundDagger);
}

const std::vector<Weapon>& Weapon::getAvailableWeapons() {
    if (availableWeapons.empty()) {
        initializeAvailableWeapons();
    }
    return availableWeapons;
}
Weapon Weapon::createWeapon(const std::string& name) {
    const auto& weapons = Weapon::getAvailableWeapons();

    for (const auto& weapon : weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }
    return Weapon("?", "Описание отсутствует", 0, 0);
}
