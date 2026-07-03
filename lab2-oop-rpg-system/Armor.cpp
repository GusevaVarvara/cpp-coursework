#include "Armor.h"

std::vector<Armor> Armor::availableArmors;

Armor::Armor(const std::string& name, const std::string& description, int plusHealth, int plusDamage)
	: Item(name, description, plusHealth, plusDamage) {}

void Armor::addAvailableArmor(const Armor& armor) {
    availableArmors.push_back(armor);
}

void Armor::initializeAvailableArmors() {

    Armor flameplateArmor("FlameplateArmor", "Демонический Пламенный Доспех - этот доспех создан из чешуи адского демона, устойчивого к огню. "
                           "При атаке противника, доспех может высвободить поток пламени в ответ, наносящий урон окружающим.", 5, 2);


    Armor shadowcloakMantle("ShadowcloakMantle", "Эльфийская Теневая Мантия - эта легкая мантия позволяет незаметно перемещаться в тени и становиться почти невидимым в "
                            "темноте.", 9, 0);


    Armor bloodKissCloak("BloodKissCloak", "Плащ Кровавого Поцелуя - этот плащ создан из особого материала, пропитанного кровью вампира. Он предоставляет защиту от физических "
                                     "атак и может впитывать часть урона, причиненного владельцу, восстанавливая его здоровье.", 12, 0);

    availableArmors.push_back(flameplateArmor);
    availableArmors.push_back(shadowcloakMantle);
    availableArmors.push_back(bloodKissCloak);
}

const std::vector<Armor>& Armor::getAvailableArmors() {
    if (availableArmors.empty()) {
        initializeAvailableArmors();
    }
    return availableArmors;
}
Armor Armor::createArmor(const std::string& name) {
    const auto& armors = Armor::getAvailableArmors();

    for (const auto& armor : armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }
    return Armor("?", "Описание отсутствует", 0, 0);
}
