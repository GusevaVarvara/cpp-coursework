#include <iostream>
#include <locale>
#include "Player.h" 
#include "Race.h"
#include "Class.h"
#include "Enemy.h" 
#include "Pet.h" 
#include "Combat.h" 


void displayAvailableOptions() {
    std::cout << "Доступные расы:\n\n";
    const std::vector<Race>& races = Race::getAvailableRaces();
    for (const Race& race : races) {
        std::cout << race.getName() << ": " << race.getDescription() << "\n\n";
    }

    std::cout << "\n\nДоступные классы:\n\n";
    const std::vector<Class>& classes = Class::getAvailableClasses();
    for (const Class& characterClass : classes) {
        std::cout << characterClass.getName() << ": " << characterClass.getDescription() << "\n\n";
    }

    std::cout << "\n\nДоступные питомцы:\n\n";
    const std::vector<Pet>& pets = Pet::getAvailablePets();
    for (const Pet& characterPet : pets) {
        std::cout << characterPet.getName() << ": " << characterPet.getDescription() << "\n\n";
    }

}

int main() {

    setlocale(LC_ALL, "Russian");

    Race::initializeAvailableRaces();
    Class::initializeAvailableClasses();
    Pet::initializeAvailablePets();
    Enemy::initializeAvailableEnemies();

    Player player("Игрок", 100, 0);

    std::cout << "Выберите расу, класс и питомца для вашего персонажа\n\n";

    displayAvailableOptions();

    std::string chosenRace, chosenClass, chosenPet;
    std::cout << "\n\nВыберите расу для вашего персонажа: ";
    std::cin >> chosenRace;
    std::cout << "Выберите класс для вашего персонажа: ";
    std::cin >> chosenClass;
    std::cout << "Выберите питомца для вашего персонажа: ";
    std::cin >> chosenPet;

    Race chosenRaceObj = Race::createRace(chosenRace);
    Class chosenClassObj = Class::createClass(chosenClass);
    Pet chosenPetObj = Pet::createPet(chosenPet);

    while (chosenPetObj.getName() == "?") {
        std::cout << "\nВыберите питомца из доступных\n";
        std::cin >> chosenPet;
        chosenPetObj = Pet::createPet(chosenPet);
    }

    std::cout << "\nВаш персонаж:\n";
    std::cout << "Раса: " << chosenRaceObj.getName() << "\n";
    std::cout << "Класс: " << chosenClassObj.getName() << "\n";
    std::cout << "\nВаш питомец:" << chosenPetObj.getName() << "\n";

    std::cout << "\nТеперь выберите врага, с которым хотите сразиться\n\n";

    std::cout << "\n\nДоступные враги:\n\n";
    const std::vector<Enemy>& enemies = Enemy::getAvailableEnemies();
    for (const Enemy& characterEnemy : enemies) {
        std::cout << characterEnemy.getName() << ": " << characterEnemy.getDescription() << "\n\n";
    }
    
    std::string chosenEnemy;
    std::cout << "\nВыберите врага: ";
    std::cin >> chosenEnemy;

    Enemy chosenEnemyObj = Enemy::createEnemy(chosenEnemy);

    while (chosenEnemyObj.getName() == "?") {
        std::cout << "\nВыберите врага из доступных\n";
        std::cin >> chosenEnemy;
        chosenEnemyObj = Enemy::createEnemy(chosenEnemy);
    }

    std::cout << "\nВаш враг: " << chosenEnemyObj.getName() << "\n" << chosenEnemyObj.getDescription() << "\n";

    std::vector<Character> players;
    players.push_back(player);
    players.push_back(chosenEnemyObj);
    players.push_back(chosenPetObj);

    Combat combat(players);

    std::cout << "\nБой начался!\n";
    combat.startCombat();

    return 0;
}

