#include "Combat.h"
#include <iostream>

Combat::Combat(std::vector<Character>& players)
    : players(players) {}

void Combat::startCombat() {
    int round = 1;
    while (true) {
        std::cout << "\nРаунд " << round << "\n\n";

        std::cout << "Ход игрока:\n";
        std::string diceRoll;
        std::cout << "\nНажмите E чтобы бросить кубик\n";
        std::cin >> diceRoll;
        while (diceRoll != "E") {
            std::cout << "\nНажмите E чтобы бросить кубик\n";           
            std::cin >> diceRoll;
        }
        int roll = dice.roll();
        std::cout << "\nВыпавшее значение: " << roll << "\n";
        int damage = roll * 5;
        players[1].takeDamage(damage);
        std::cout << "\nИгрок нанёс " << damage << " урона врагу.\n";

        if (players[0].getHealth() <= 0) {
            std::cout << "\nGame over!\n";
            break;
        }
        if (players[1].getHealth() <= 0) {
            std::cout << "\nВраг повержен. Победа!\n";
            rewardPlayer();
            break;
        }

        std::cout << "\nХод врага:\n";
        int enemyDamage = players[1].getDamage();
        players[0].takeDamage(enemyDamage);
        std::cout << "Враг нанёс " << enemyDamage << " урона игроку.\n";

        if (players[0].getHealth() <= 0) {
            std::cout << "\nGame over!\n";
            break;
        }
        if (players[1].getHealth() <= 0) {
            std::cout << "\nВраг повержен. Победа!\n";
            rewardPlayer();
            break;
        }

        std::cout << "\nХод питомца:\n";
        int petDamage = players[2].getDamage();
        players[1].takeDamage(petDamage);
        std::cout << "Питомец нанёс " << petDamage << " урона врагу.\n";

        if (players[0].getHealth() <= 0) {
            std::cout << "\nGame over!\n";
            break;
        }
        if (players[1].getHealth() <= 0) {
            std::cout << "\nВраг повержен. Победа!\n";
            rewardPlayer();
            break;
        }

        std::cout << "\n\n" << round << " раунд завершён\n";
        std::cout << "Здоровье игрока: " << players[0].getHealth() << "\n";
        std::cout << "Здоровье врага: " << players[1].getHealth() << "\n";

        round++;
    }
}

void Combat::rewardPlayer() {
    if (players[1].getName() == "Arcadios") {
        Weapon WeaponObj = Weapon::createWeapon("ChaosBlade");
        Armor ArmorObj = Armor::createArmor("FlameplateArmor");
        Potion PotionObj = Potion::createPotion("DemonicEssence");
        
        std::cout << "\nВы получили:\n";

        std::cout << "\n" << WeaponObj.getName() << ": " << WeaponObj.getDescription() << "\n";
        players[0].addItem(WeaponObj);

        std::cout << "\n" << ArmorObj.getName() << ": " << ArmorObj.getDescription() << "\n";
        players[0].addItem(ArmorObj);

        std::cout << "\n" << PotionObj.getName() << ": " << PotionObj.getDescription() << "\n";
        players[0].addItem(PotionObj);
    }
    else if (players[1].getName() == "Serafina") {
        Weapon WeaponObj = Weapon::createWeapon("MoonshadowBow");
        Armor ArmorObj = Armor::createArmor("ShadowcloakMantle");
        Potion PotionObj = Potion::createPotion("ElvenEssence");

        std::cout << "\nВы получили:\n";

        std::cout << "\n" << WeaponObj.getName() << ": " << WeaponObj.getDescription() << "\n";
        players[0].addItem(WeaponObj);

        std::cout << "\n" << ArmorObj.getName() << ": " << ArmorObj.getDescription() << "\n";
        players[0].addItem(ArmorObj);

        std::cout << "\n" << PotionObj.getName() << ": " << PotionObj.getDescription() << "\n";
        players[0].addItem(PotionObj);
    }
    else if (players[1].getName() == "Malgrim") {
        Weapon WeaponObj = Weapon::createWeapon("BloodhoundDagger");
        Armor ArmorObj = Armor::createArmor("BloodKissCloak");
        Potion PotionObj = Potion::createPotion("VampiricEssence");

        std::cout << "\nВы получили:\n";

        std::cout << "\n" << WeaponObj.getName() << ": " << WeaponObj.getDescription() << "\n";
        players[0].addItem(WeaponObj);

        std::cout << "\n" << ArmorObj.getName() << ": " << ArmorObj.getDescription() << "\n";
        players[0].addItem(ArmorObj);

        std::cout << "\n" << PotionObj.getName() << ": " << PotionObj.getDescription() << "\n";
        players[0].addItem(PotionObj);
    }
}

